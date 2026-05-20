
package testmatter;

public class Gas extends Matters {
    private double pressure;
    private double temperature;
    private double mole;

    public Gas(double pressure, double temperature, double mole, String matterName, double matterMass) {
        super(matterName, matterMass);
        this.pressure = pressure;
        this.temperature = temperature;
        this.mole = mole;
    }

    public double getPressure() {
        return pressure;
    }

    public void setPressure(double pressure) {
        this.pressure = pressure;
    }

    public double getTemperature() {
        return temperature;
    }

    public void setTemperature(double temperature) {
        this.temperature = temperature;
    }

    public double getMole() {
        return mole;
    }

    public void setMole(double mole) {
        this.mole = mole;
    }
    public void showDetails(){
        System.out.println("Name of matter"+getMatterName());
        System.out.println("Mass of matter"+getMatterMass());
        System.out.println("Pressure="+getPressure());
        System.out.println("Temperature="+getTemperature());
        System.out.println("Mole="+getMole());
    }
    public void calculateVolume(){
        double x=(8.314*mole*temperature)/pressure;
        System.out.println("Volume="+x);
    }
    
}
