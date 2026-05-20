clc;
clear;
close all;

% 1. Read an RGB image
image = imread('input.jpg');

% 2. Split into R, G, B channels
R = double(image(:,:,1));
G = double(image(:,:,2));
B = double(image(:,:,3));

% 3. Apply filters per channel

% Positive Laplacian (8-neighbor) on G
laplacian_kernel = [1  1  1;
                    1 -8  1;
                    1  1  1];
G_laplacian = imfilter(G, laplacian_kernel, 'replicate');

% Sobel on R
sobel_x = fspecial('sobel');
sobel_y = sobel_x';
R_sobel = sqrt(imfilter(R, sobel_x, 'replicate').^2 + imfilter(R, sobel_y, 'replicate').^2);

% Prewitt on B
prewitt_x = fspecial('prewitt');
prewitt_y = prewitt_x';
B_prewitt = sqrt(imfilter(B, prewitt_x, 'replicate').^2 + imfilter(B, prewitt_y, 'replicate').^2);

% 4. Apply derivatives

% Forward derivative on G: f'(x) = f(x+1) - f(x)
G_forward = zeros(size(G_laplacian));
G_forward(:, 1:end-1) = G_laplacian(:, 2:end) - G_laplacian(:, 1:end-1);

% Backward derivative on B: f'(x) = f(x) - f(x-1)
B_backward = zeros(size(B_prewitt));
B_backward(:, 2:end) = B_prewitt(:, 2:end) - B_prewitt(:, 1:end-1);

% Central derivative on R: f'(x) = (f(x+1) - f(x-1)) / 2
R_central = zeros(size(R_sobel));
R_central(:, 2:end-1) = (R_sobel(:, 3:end) - R_sobel(:, 1:end-2)) / 2;

% Normalize helper function
normalize = @(x) uint8(255 * (x - min(x(:))) / (max(x(:)) - min(x(:)) + eps));

R_final = normalize(R_central);
G_final = normalize(G_forward);
B_final = normalize(B_backward);

% 5. Merge into single RGB edge-enhanced image
merged = cat(3, R_final, G_final, B_final);

% Write output image
imwrite(merged, 'A2_20210204033.jpg');

% 6. Compare merged image with individual operator results
figure('Name', 'Edge Detection Comparison - A2_20210204033', 'NumberTitle', 'off');

subplot(2,4,1); imshow(image);          title('Original RGB');
subplot(2,4,2); imshow(normalize(G_laplacian)); title('G - Laplacian (8-neighbor)');
subplot(2,4,3); imshow(normalize(R_sobel));     title('R - Sobel');
subplot(2,4,4); imshow(normalize(B_prewitt));   title('B - Prewitt');
subplot(2,4,5); imshow(merged);                 title('Merged Edge-Enhanced RGB');
subplot(2,4,6); imshow(G_final);                title('G - Laplacian + Forward Deriv');
subplot(2,4,7); imshow(R_final);                title('R - Sobel + Central Deriv');
subplot(2,4,8); imshow(B_final);                title('B - Prewitt + Backward Deriv');

saveas(gcf, 'A2_20210204033_comparison.jpg');

