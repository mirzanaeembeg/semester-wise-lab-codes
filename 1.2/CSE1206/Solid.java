
package testmatter;

public class Solid extends Matters {
    
    private double length;
    private double width;
    private double height;

    public Solid( String matterName, double matterMass,double length, double width, double height) {
        super(matterName, matterMass);
        this.length = length;
        this.width = width;
        this.height = height;
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }
    
    @Override
    public void showDetails(){
        System.out.println("Name of matter:"+getMatterName());
        System.out.println("Mass of matter:"+getMatterMass());
        System.out.println("Length="+getLength());
        System.out.println("Width="+getWidth());
        System.out.println("Height="+getHeight());
    }
    public void calculateVolume(){
        double x=length*width*height;
        System.out.println("Volume="+x);
    }
}
