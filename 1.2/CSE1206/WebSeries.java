
package entertainmentcompany;

public class WebSeries extends ProductionCompany {
    private String seriesName;
    private String platformName;
    
    public WebSeries(){
        super();
    }
    public WebSeries(String seriesName, String platformName, String companyName) {
        super(companyName);
        this.seriesName = seriesName;
        this.platformName = platformName;
    }

    public String getSeriesName() {
        return seriesName;
    }

    public String getPlatformName() {
        return platformName;
    }

    public void setSeriesName(String seriesName) {
        this.seriesName = seriesName;
    }

    public void setPlatformName(String platformName) {
        this.platformName = platformName;
    }
    
    /**
     *
     */
    @Override
    public void productionInfo(){
        System.out.println("Series name is: "+seriesName);
        System.out.println("Platform name is: "+platformName);
    }
    
}
