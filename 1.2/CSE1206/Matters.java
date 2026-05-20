
package testmatter;

public abstract class Matters {
    String matterName;
    double matterMass;

    public Matters(String matterName, double matterMass) {
        this.matterName = matterName;
        this.matterMass = matterMass;
    }
    public String getMatterName() {
        return matterName;
    }

    public void setMatterName(String matterName) {
        this.matterName = matterName;
    }

    public double getMatterMass() {
        return matterMass;
    }

    public void setMatterMass(double matterMass) {
        this.matterMass = matterMass;
    }
    
    public abstract void showDetails();
    public abstract void calculateVolume();
}
