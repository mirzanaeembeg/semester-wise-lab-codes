package rectangledemo;

public class RectangleDemo {

    public static void main(String[] args) {
        Rectangle r1 = new Rectangle();
        Rectangle R1 = new Rectangle();
        Rectangle R2 = new Rectangle();
        r1.setLength(12);
        r1.setWidth(17);
        System.out.println("Length= "+r1.getLength());
        System.out.println("Width= "+r1.getWidth());
        System.out.println("Area= "+r1.getArea());
        System.out.println("Perimeter= "+r1.getPerimeter());
        System.out.println(r1.toString());
        
        R1=r1.newRectangle();
        System.out.println("Length= "+R1.getLength());
        System.out.println("Width= "+R1.getWidth());
        System.out.println("Area= "+R1.getArea());
        System.out.println("Perimeter= "+R1.getPerimeter());
        System.out.println(R1.toString());
        
        R2=R1.newRectangle();
        System.out.println("Length= "+R2.getLength());
        System.out.println("Width= "+R2.getWidth());
        System.out.println("Area= "+R2.getArea());
        System.out.println("Perimeter= "+R2.getPerimeter());
        System.out.println(R2.toString());
    }
    
}
