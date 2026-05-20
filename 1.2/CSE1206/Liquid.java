
package testmatter;

public class Liquid extends Matters{
    private double density;

    public Liquid(double density, String matterName, double matterMass) {
        super(matterName, matterMass);
        this.density = density;
    }

    public double getDensity() {
        return density;
    }

    public void setDensity(double density) {
        this.density = density;
    }
    public void showDetails(){
        System.out.println("Name of matter"+getMatterName());
        System.out.println("Mass of matter"+getMatterMass());
        System.out.println("Density="+getDensity());
    }
    public void calculateVolume(){
        double x=matterMass/density;
        System.out.println("Volume="+x);
    }
}
