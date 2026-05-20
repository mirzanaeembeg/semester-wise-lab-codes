import * as THREE from 'three';

// RENDERER
const renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
renderer.shadowMap.enabled = true;
renderer.shadowMap.type = THREE.PCFSoftShadowMap;
renderer.toneMapping = THREE.ACESFilmicToneMapping;
renderer.toneMappingExposure = 1.1;
document.body.appendChild(renderer.domElement);

// SCENE 
const scene = new THREE.Scene();
scene.background = new THREE.Color(0x1a0f05);
scene.fog = new THREE.Fog(0x1a0f05, 12, 32);

//  PERSPECTIVE CAMERA (Requirement 3) 
const camera = new THREE.PerspectiveCamera(
  72,
  window.innerWidth / window.innerHeight,
  0.1,
  100
);
camera.position.set(0, 1.7, 6.5);
camera.lookAt(0, 0.8, 0);

//  TEXTURE LOADER (Requirement 4) 
const texLoader = new THREE.TextureLoader();

function loadTex(path, rx = 1, ry = 1) {
  const t = texLoader.load(path);
  t.wrapS = t.wrapT = THREE.RepeatWrapping;
  t.repeat.set(rx, ry);
  return t;
}

const texWood  = loadTex('textures/wood.jpg',  2, 2);
const texWood2 = loadTex('textures/wood2.jpg', 2, 2);
const texWall  = loadTex('textures/wall.jpg',  4, 2);
const texFloor = loadTex('textures/floor.jpg', 5, 5);

//  CUSTOM SHADERS (Requirement 1) 
const floorVert = `
  varying vec2 vUv;
  varying vec3 vWorldPos;
  void main() {
    vUv = uv;
    vec4 wp = modelMatrix * vec4(position, 1.0);
    vWorldPos = wp.xyz;
    gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.0);
  }
`;

const floorFrag = `
  uniform vec3      uLightPos;
  uniform float     uTime;
  uniform sampler2D uFloorTex;
  uniform vec2      uTexRepeat;   // must match loadTex repeat (5,5)
  varying vec2      vUv;
  varying vec3      vWorldPos;

  void main() {
    // Apply repeat manually -- ShaderMaterial bypasses Three.js texture matrix
    vec2 repeatedUV = fract(vUv * uTexRepeat);
    vec3 texCol = texture2D(uFloorTex, repeatedUV).rgb;

    // Grout grid overlay (matches tile count to texture repeat)
    float tileCount = uTexRepeat.x;          // 5 tiles across
    vec2  tileUV    = vUv * tileCount;
    vec2  tileId    = floor(tileUV);
    vec2  tileFrac  = fract(tileUV);

    float groutW  = 0.04;
    float inGrout = step(groutW, tileFrac.x) * step(groutW, tileFrac.y)
                  * step(tileFrac.x, 1.0 - groutW)
                  * step(tileFrac.y, 1.0 - groutW);

    // Darken grout lines
    vec3 groutCol = texCol * 0.40;
    vec3 baseCol  = mix(groutCol, texCol, inGrout);

    // Soft distance-based light -- linear falloff avoids harsh bright patch
    float dist = length(vWorldPos - uLightPos);
    float glow = 1.0 / (1.0 + dist * 0.55);

    // Subtle specular
    vec2  tileCenter = (tileId + vec2(0.5)) / tileCount;
    vec2  lightXZ    = vec2(uLightPos.x, uLightPos.z) / 8.0 + 0.5;
    float spec  = pow(max(0.0, 1.0 - length(tileCenter - lightXZ) * 4.0), 8.0);
    float shine = spec * inGrout * 0.12;

    // Keep base brightness high enough that texture reads clearly everywhere
    vec3 lit = baseCol * (0.75 + 0.25 * glow) + vec3(shine);
    gl_FragColor = vec4(clamp(lit, 0.0, 1.0), 1.0);
  }
`;

const floorUniforms = {
  uLightPos: { value: new THREE.Vector3() },
  uTime:     { value: 0.0 },
  uFloorTex: { value: texFloor },
  uTexRepeat:{ value: new THREE.Vector2(5, 5) },  // must match loadTex('floor.jpg', 5, 5)
};
const floorShaderMat = new THREE.ShaderMaterial({
  vertexShader:        floorVert,
  fragmentShader:      floorFrag,
  uniforms:            floorUniforms,
  polygonOffset:       true,   // prevent Z-fighting with room box inner bottom face
  polygonOffsetFactor: -1,
  polygonOffsetUnits:  -1,
});

//  MATERIALS 
const wallMat = new THREE.MeshStandardMaterial({
  map: texWall, side: THREE.BackSide,
  roughness: 0.6, metalness: 0.0, color: 0xd8c3a4,
});
const ceilMat = new THREE.MeshStandardMaterial({ color: 0xf0e0c8, roughness: 0.92 });

// Wood material for chair & table frame
const darkWoodMat = new THREE.MeshStandardMaterial({
  map: texWood, roughness: 0.55, metalness: 0.02,
  color: 0xb07040,
});
// Table surface (swappable)
const tableSurfMat = new THREE.MeshStandardMaterial({
  map: texWood, roughness: 0.35, metalness: 0.05,
  color: 0xc08050,
});

//  ROOM 
const room = new THREE.Mesh(new THREE.BoxGeometry(16, 6, 16), wallMat);
room.receiveShadow = true;
scene.add(room);

const floor = new THREE.Mesh(new THREE.PlaneGeometry(16, 16), floorShaderMat);
floor.rotation.x = -Math.PI / 2;
floor.position.y = -2.999;  // tiny offset above room box bottom (y=-3) to eliminate Z-fighting
floor.receiveShadow = true;
scene.add(floor);

const ceiling = new THREE.Mesh(new THREE.PlaneGeometry(16, 16), ceilMat);
ceiling.rotation.x = Math.PI / 2;
ceiling.position.y = 3;
scene.add(ceiling);

//  UTILITY: add a box child to a group
function addBox(parent, w, h, d, mat, x, y, z, castShadow = true) {
  const m = new THREE.Mesh(new THREE.BoxGeometry(w, h, d), mat);
  m.position.set(x, y, z);
  m.castShadow = castShadow;
  m.receiveShadow = true;
  parent.add(m);
  return m;
}

// Cylinder (for turned chair legs / spindles)
function addCyl(parent, rTop, rBot, h, segs, mat, x, y, z, rotX = 0) {
  const m = new THREE.Mesh(new THREE.CylinderGeometry(rTop, rBot, h, segs), mat);
  m.position.set(x, y, z);
  m.rotation.x = rotX;
  m.castShadow = true;
  m.receiveShadow = true;
  parent.add(m);
  return m;
}

//  REALISTIC LARGE TABLE (Requirement 7)
//  Dimensions: 3.8 wide × 1.9 deep × 0.80 tall (seat height ~0.74 m scale)

const tableGroup = new THREE.Group();
scene.add(tableGroup);
tableGroup.position.set(0, -3 + 0.78, 0); // floor -3, legs + top

const TW = 3.8;   // table width
const TD = 1.9;   // table depth
const TH = 0.10;  // tabletop thickness

//Tabletop slab 
const tabletop = new THREE.Mesh(
  new THREE.BoxGeometry(TW, TH, TD),
  tableSurfMat
);
tabletop.position.set(0, 0, 0);
tabletop.castShadow = true;
tabletop.receiveShadow = true;
tabletop.name = 'tabletop';
tableGroup.add(tabletop);

// 2 Books on the table 
const bookOnTableY = TH / 2; // sit exactly on top of the tabletop slab

// Book 1 — closed, lying flat, slightly left of center
const book1Cover = new THREE.MeshStandardMaterial({ color: 0x8b1a1a, roughness: 0.8 });
const book1Pages = new THREE.MeshStandardMaterial({ color: 0xf2e8d5, roughness: 1.0 });

const b1 = new THREE.Group();
// Cover (slightly larger than pages)
const b1Cover = new THREE.Mesh(new THREE.BoxGeometry(0.30, 0.035, 0.22), book1Cover);
b1Cover.castShadow = true;
b1.add(b1Cover);
// Pages block inside
const b1Pages = new THREE.Mesh(new THREE.BoxGeometry(0.275, 0.028, 0.200), book1Pages);
b1Pages.position.set(0.008, 0, 0); // slight offset so page edges show on spine side
b1.add(b1Pages);
// Spine strip
const b1Spine = new THREE.Mesh(new THREE.BoxGeometry(0.015, 0.036, 0.22), book1Cover);
b1Spine.position.set(-0.1425, 0, 0);
b1.add(b1Spine);

b1.position.set(-0.55, bookOnTableY + 0.0175, 0.18);
b1.rotation.y = 0.18; // slight angle, natural placement
tableGroup.add(b1);

// Book 2 — open/propped at an angle, right of center
const book2Cover = new THREE.MeshStandardMaterial({ color: 0x1a3a6b, roughness: 0.8 });
const book2Pages = new THREE.MeshStandardMaterial({ color: 0xeee0c8, roughness: 1.0 });

const b2 = new THREE.Group();
// Left half of open book
const b2Left = new THREE.Mesh(new THREE.BoxGeometry(0.20, 0.012, 0.26), book2Cover);
b2Left.position.set(-0.10, 0, 0);
b2Left.rotation.z =  0.15; // slightly angled open
b2Left.castShadow = true;
b2.add(b2Left);
// Right half
const b2Right = new THREE.Mesh(new THREE.BoxGeometry(0.20, 0.012, 0.26), book2Cover);
b2Right.position.set( 0.10, 0, 0);
b2Right.rotation.z = -0.15;
b2Right.castShadow = true;
b2.add(b2Right);
// Left page surface
const b2PL = new THREE.Mesh(new THREE.BoxGeometry(0.185, 0.003, 0.242), book2Pages);
b2PL.position.set(-0.095, 0.007, 0);
b2PL.rotation.z = 0.15;
b2.add(b2PL);
// Right page surface
const b2PR = new THREE.Mesh(new THREE.BoxGeometry(0.185, 0.003, 0.242), book2Pages);
b2PR.position.set( 0.095, 0.007, 0);
b2PR.rotation.z = -0.15;
b2.add(b2PR);

b2.position.set(0.60, bookOnTableY + 0.012, -0.15);
b2.rotation.y = -0.25;
tableGroup.add(b2);

// Apron (skirt frame under the tabletop edge)
const apronH   = 0.12;
const apronThk = 0.06;
const apronY   = -(TH / 2 + apronH / 2);
const apronInX = TW / 2 - 0.20;   // inset from tabletop edge
const apronInZ = TD / 2 - 0.20;

// front & back apron boards
addBox(tableGroup, TW - 0.40, apronH, apronThk, darkWoodMat,  0, apronY,  apronInZ);
addBox(tableGroup, TW - 0.40, apronH, apronThk, darkWoodMat,  0, apronY, -apronInZ);
// left & right apron boards
addBox(tableGroup, apronThk, apronH, TD - 0.40, darkWoodMat,  apronInX, apronY, 0);
addBox(tableGroup, apronThk, apronH, TD - 0.40, darkWoodMat, -apronInX, apronY, 0);

// 4 chunky tapered legs
const legH    = 0.72;
const legTopR = 0.065;
const legBotR = 0.038;
const tLegY   = -(TH / 2 + apronH + legH / 2);
const tLX     = TW / 2 - 0.22;
const tLZ     = TD / 2 - 0.22;

[[-tLX, -tLZ], [tLX, -tLZ], [-tLX, tLZ], [tLX, tLZ]].forEach(([x, z]) => {
  addCyl(tableGroup, legTopR, legBotR, legH, 16, darkWoodMat, x, tLegY, z);
});

//  Stretcher braces (horizontal, near floor) 
const stretchY = tLegY - legH / 2 + 0.10;
const stretchR = 0.025;
// long stretcher (along width)
addCyl(tableGroup, stretchR, stretchR, TW - 0.44, 10, darkWoodMat, 0, stretchY,  tLZ, 0);
addCyl(tableGroup, stretchR, stretchR, TW - 0.44, 10, darkWoodMat, 0, stretchY, -tLZ, 0);
// short stretcher (along depth)
addCyl(tableGroup, stretchR, stretchR, TD - 0.44, 10, darkWoodMat,  tLX, stretchY, 0, Math.PI / 2);
addCyl(tableGroup, stretchR, stretchR, TD - 0.44, 10, darkWoodMat, -tLX, stretchY, 0, Math.PI / 2);

//  REALISTIC CHAIR (Requirement 7)
//  Full woodworking detail: tapered legs, spindle back, armrests, stretchers

function makeChair(px, pz, rotY = 0) {
  const g = new THREE.Group();

  // Seat proportions
  const SW  = 0.56;   // seat width
  const SD  = 0.52;   // seat depth
  const SH  = 0.055;  // seat thickness
  const SY  = 0;      // local seat Y origin
  const legCH = 0.44; // leg height from floor to seat underside

  // Seat 
  addBox(g, SW, SH, SD, darkWoodMat, 0, SY, 0);

  // Seat front chamfer strip (visual detail)
  addBox(g, SW, 0.018, 0.015, darkWoodMat, 0, SY - SH / 2 + 0.008, SD / 2);

  // Back posts (2 vertical cylinders rising from rear seat corners)
  const bpH   = 0.58;   // height above seat
  const bpR   = 0.028;
  const bpX   = SW / 2 - 0.06;
  const bpY   = SY + SH / 2 + bpH / 2;
  const bpZ   = -SD / 2 + 0.04;

  addCyl(g, bpR, bpR * 0.85, bpH, 12, darkWoodMat,  bpX, bpY, bpZ);
  addCyl(g, bpR, bpR * 0.85, bpH, 12, darkWoodMat, -bpX, bpY, bpZ);

  //  Back slats (3 horizontal boards between back posts) 
  const slotW   = SW - 0.08;
  const slotH   = [0.085, 0.072, 0.060]; // heights, tallest at bottom
  const slotThk = 0.022;
  const slotZZ  = bpZ;
  const slotYBase = SY + SH / 2 + 0.08;
  const slotGap   = 0.13;

  slotH.forEach((sh, i) => {
    addBox(g, slotW, sh, slotThk, darkWoodMat, 0, slotYBase + i * slotGap, slotZZ);
  });

  //  Top rail (crest rail connecting back posts) 
  const crY = SY + SH / 2 + bpH - 0.04;
  addBox(g, SW + 0.02, 0.055, 0.045, darkWoodMat, 0, crY, bpZ);

  // Armrests
  const armY  = SY + SH / 2 + 0.24;    // comfortable armrest height
  const armLX = SW / 2 + 0.03;
  const armW  = 0.045;
  const armD  = SD * 0.85;

  addBox(g, armW, 0.035, armD, darkWoodMat,  armLX, armY, -0.03);
  addBox(g, armW, 0.035, armD, darkWoodMat, -armLX, armY, -0.03);

  // Armrest supports (small vertical brace)
  addBox(g, armW * 0.8, 0.22, armW * 0.8, darkWoodMat,  armLX, armY - 0.13, SD / 2 - 0.10);
  addBox(g, armW * 0.8, 0.22, armW * 0.8, darkWoodMat, -armLX, armY - 0.13, SD / 2 - 0.10);

  // 4 Tapered legs
  const cLT = 0.030;  // leg top radius
  const cLB = 0.018;  // leg bottom radius (tapered)
  const chairLegY = SY - SH / 2 - legCH / 2;
  const legFX = SW / 2 - 0.06;
  const legFZ = SD / 2 - 0.06;

  [[-legFX, -legFZ], [legFX, -legFZ], [-legFX, legFZ], [legFX, legFZ]]
    .forEach(([cx, cz]) => addCyl(g, cLT, cLB, legCH, 14, darkWoodMat, cx, chairLegY, cz));

  // Stretchers 
  const stY = SY - SH / 2 - legCH + 0.10;
  const stR = 0.018;

  // front & back side stretchers
  addCyl(g, stR, stR, SW - 0.12, 10, darkWoodMat,  0, stY,  legFZ);
  addCyl(g, stR, stR, SW - 0.12, 10, darkWoodMat,  0, stY, -legFZ);
  // left & right stretchers
  addCyl(g, stR, stR, SD - 0.12, 10, darkWoodMat,  legFX, stY, 0, Math.PI / 2);
  addCyl(g, stR, stR, SD - 0.12, 10, darkWoodMat, -legFX, stY, 0, Math.PI / 2);

  //  Position in scene
  // seat top matches table height - comfortable gap
  const seatFloorH = legCH + SH / 2;
  g.position.set(px, -3 + seatFloorH, pz);
  g.rotation.y = rotY;
  scene.add(g);
  return g;
}

// Rotation math (Three.js Y-axis, right-hand rule):
//   rotY = 0       → local +Z faces world +Z
//   rotY = Math.PI → local +Z faces world -Z
//   rotY = +π/2    → local +Z faces world +X   ← LEFT chair must use this (faces toward center)
//   rotY = -π/2    → local +Z faces world -X   ← RIGHT chair must use this (faces toward center)
//
// Table half-extents: X=1.9, Z=0.95. Chair seat depth=0.52 (half=0.26). Gap from apron=0.08
//   Front/back  Z = ±(0.95 + 0.26 + 0.08) ≈ ±1.30
//   Left/right  X = ±(1.90 + 0.26 + 0.08) ≈ ±2.24

makeChair(-1.0,  1.30,  Math.PI);           // front-left  → local +Z faces -Z (into table)
makeChair( 1.0,  1.30,  Math.PI);           // front-right → local +Z faces -Z (into table)
makeChair(-1.0, -1.30,  0);                 // back-left   → local +Z faces +Z (into table)
makeChair( 1.0, -1.30,  0);                 // back-right  → local +Z faces +Z (into table)
makeChair(-2.24, 0.0,   Math.PI / 2);       // left side   → local +Z faces +X (into table)
makeChair( 2.24, 0.0,  -Math.PI / 2);       // right side  → local +Z faces -X (into table)

// TALL READING ROOM BOOKSHELVES 
// Each bookshelf: ~2.4m tall x 1.8m wide x 0.38m deep, 5 shelf levels

function makeBookshelf(px, py, pz, rotY = 0) {
  const sg = new THREE.Group();

  const W  = 1.8;
  const H  = 2.4;
  const D  = 0.38;
  const TK = 0.05;
  const shelfMat = new THREE.MeshStandardMaterial({
    color: 0x4a2a10, roughness: 0.75, metalness: 0.0,
  });

  // Left & right side panels (full height)
  addBox(sg, TK, H, D, shelfMat, -W/2, H/2, 0);
  addBox(sg, TK, H, D, shelfMat,  W/2, H/2, 0);
  // Back panel
  addBox(sg, W - TK, H, TK * 0.6, shelfMat, 0, H/2, -D/2 + TK * 0.3);
  // Top panel
  addBox(sg, W + TK, TK, D, shelfMat, 0, H, 0);
  // Bottom base panel
  addBox(sg, W - TK, TK, D, shelfMat, 0, TK/2, 0);
  // Base kick board
  addBox(sg, W - TK, 0.08, TK, shelfMat, 0, 0.04, D/2 - TK/2);
  // Crown molding strip
  addBox(sg, W + TK * 2, 0.06, TK * 1.5, shelfMat, 0, H + 0.03, D/2);

  // 5 internal shelves
  const numShelves = 5;
  const shelfSpacing = (H - 0.1) / numShelves;
  const shelfYs = [];
  for (let i = 0; i < numShelves; i++) {
    const sy = 0.08 + i * shelfSpacing;
    addBox(sg, W - TK, TK, D - TK, shelfMat, 0, sy, 0);
    shelfYs.push(sy);
  }

  // Books on each shelf
  const PALETTES = [
    [0x8b1a1a, 0xc0392b, 0x96281b],
    [0x1a3a6b, 0x2471a3, 0x154360],
    [0x1e5c1e, 0x27ae60, 0x145a32],
    [0x7d6608, 0xd4ac0d, 0x9a7d0a],
    [0x4a235a, 0x7d3c98, 0x6c3483],
    [0x784212, 0xba4a00, 0x935116],
  ];

  shelfYs.forEach((sy, si) => {
    const palette = PALETTES[si % PALETTES.length];
    let curX = -W/2 + TK + 0.04;
    const maxX    = W/2 - TK - 0.02;
    const shelfTop = sy + TK / 2;
    const availH  = shelfSpacing - TK - 0.04;

    while (curX < maxX - 0.06) {
      const bw = 0.055 + Math.random() * 0.055;
      if (curX + bw > maxX) break;
      const bh   = availH * (0.65 + Math.random() * 0.32);
      const tilt = (Math.random() - 0.5) * 0.08;
      const col  = palette[Math.floor(Math.random() * palette.length)];

      const bMat  = new THREE.MeshStandardMaterial({ color: col, roughness: 0.85 });
      const bMesh = new THREE.Mesh(new THREE.BoxGeometry(bw, bh, D * 0.78), bMat);
      bMesh.position.set(curX + bw/2, shelfTop + bh/2, 0);
      bMesh.rotation.z = tilt;
      bMesh.castShadow = true;
      sg.add(bMesh);

      // Page-edge strip on front face
      const pageMat  = new THREE.MeshStandardMaterial({ color: 0xf5e6c8, roughness: 1.0 });
      const pageStrip = new THREE.Mesh(new THREE.BoxGeometry(bw * 0.12, bh * 0.96, 0.01), pageMat);
      pageStrip.position.set(curX + bw/2, shelfTop + bh/2, D * 0.39);
      sg.add(pageStrip);

      curX += bw + 0.006 + Math.random() * 0.018;
    }
  });

  sg.position.set(px, py, pz);
  sg.rotation.y = rotY;
  scene.add(sg);
  return sg;
}

// Two tall bookshelves on the back wall
makeBookshelf(-3.2, -3, -7.6, 0);
makeBookshelf( 3.2, -3, -7.6, 0);

// One bookshelf on each side wall
makeBookshelf(-7.7, -3,  0,  Math.PI / 2);
makeBookshelf( 7.7, -3,  0, -Math.PI / 2);

// LIGHTING (Requirements 2 & 10)
// Warm ambient
const ambient = new THREE.AmbientLight(0xffd580, 0.35);
scene.add(ambient);

// Soft fill from above
const fill = new THREE.DirectionalLight(0xffeedd, 0.4);
fill.position.set(2, 5, 3);
fill.castShadow = false;
scene.add(fill);

// Cool accent light to separate wall/floor hues
const coolFill = new THREE.PointLight(0x7abfff, 0.5, 18);
coolFill.position.set(-4, 2.2, -4);
scene.add(coolFill);

// Orbiting point light (animated) — the key feature light
const orbitLight = new THREE.PointLight(0xff9933, 5, 16);
orbitLight.castShadow = true;
orbitLight.shadow.mapSize.set(1024, 1024);
orbitLight.shadow.camera.near = 0.2;
orbitLight.shadow.camera.far  = 16;
scene.add(orbitLight);

// Visible bulb mesh attached to the light
const bulbGeo = new THREE.SphereGeometry(0.14, 16, 16);
const bulbMat = new THREE.MeshBasicMaterial({ color: 0xffc044 });
const bulbMesh = new THREE.Mesh(bulbGeo, bulbMat);
orbitLight.add(bulbMesh);

// Small halo glow ring around the bulb
const haloGeo = new THREE.RingGeometry(0.18, 0.32, 32);
const haloMat = new THREE.MeshBasicMaterial({
  color: 0xffaa22, transparent: true, opacity: 0.18, side: THREE.DoubleSide
});
const haloMesh = new THREE.Mesh(haloGeo, haloMat);
orbitLight.add(haloMesh);

// KEYBOARD INTERACTION (Requirement 8)
const keys = {};
window.addEventListener('keydown', e => { keys[e.code] = true;  e.preventDefault(); });
window.addEventListener('keyup',   e => { keys[e.code] = false; });

const SPEED     = 0.07;
const ROOM_EDGE = 7.0;

function handleCamera() {
  const dir = new THREE.Vector3();
  camera.getWorldDirection(dir);
  dir.y = 0;
  dir.normalize();

  const right = new THREE.Vector3();
  right.crossVectors(dir, camera.up).normalize();

  if (keys['KeyW'] || keys['ArrowUp'])    camera.position.addScaledVector(dir,   SPEED);
  if (keys['KeyS'] || keys['ArrowDown'])  camera.position.addScaledVector(dir,  -SPEED);
  if (keys['KeyA'] || keys['ArrowLeft'])  camera.position.addScaledVector(right, -SPEED);
  if (keys['KeyD'] || keys['ArrowRight']) camera.position.addScaledVector(right,  SPEED);
  if (keys['KeyQ']) camera.rotation.y += 0.015;
  if (keys['KeyE']) camera.rotation.y -= 0.015;

  // Clamp inside room
  camera.position.x = THREE.MathUtils.clamp(camera.position.x, -ROOM_EDGE, ROOM_EDGE);
  camera.position.z = THREE.MathUtils.clamp(camera.position.z, -ROOM_EDGE, ROOM_EDGE);
  camera.position.y = 1.7;
}

// MOUSE INTERACTION (Requirement 9) 
const raycaster = new THREE.Raycaster();
const mouse     = new THREE.Vector2();
let   altTex    = false;

window.addEventListener('click', (e) => {
  mouse.x =  (e.clientX / window.innerWidth)  * 2 - 1;
  mouse.y = -(e.clientY / window.innerHeight) * 2 + 1;

  raycaster.setFromCamera(mouse, camera);
  const hits = raycaster.intersectObjects(tableGroup.children, true);

  if (hits.length > 0 && hits[0].object.name === 'tabletop') {
    altTex = !altTex;
    tableSurfMat.map = altTex ? texWood2 : texWood;
    tableSurfMat.needsUpdate = true;

    // Flash feedback: briefly change emissive color
    tableSurfMat.emissive.setHex(altTex ? 0x331100 : 0x110800);
    setTimeout(() => tableSurfMat.emissive.setHex(0x000000), 300);
  }
});

// RESIZE 
window.addEventListener('resize', () => {
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
});

//  ANIMATION LOOP (Requirements 5 & 10)
const clock = new THREE.Clock();

const ORBIT_RADIUS = 5.5;
const ORBIT_Y      = 2.2;
const ORBIT_SPEED  = 0.4;

function animate() {
  requestAnimationFrame(animate);
  const t = clock.getElapsedTime();

  // ① Light orbits room (Req. 10)
  orbitLight.position.set(
    Math.cos(t * ORBIT_SPEED) * ORBIT_RADIUS,
    ORBIT_Y + Math.sin(t * 0.7) * 0.3,       // slight vertical bob
    Math.sin(t * ORBIT_SPEED) * ORBIT_RADIUS
  );

  // Face the halo ring toward the camera
  haloMesh.lookAt(camera.position);

  // Pulse the light intensity gently
  orbitLight.intensity = 4.5 + Math.sin(t * 2.3) * 0.5;

  // ② Update shader uniforms
  floorUniforms.uLightPos.value.copy(orbitLight.position);
  floorUniforms.uTime.value = t;

  // ③ Camera keyboard movement
  handleCamera();

  renderer.render(scene, camera);
}

animate();