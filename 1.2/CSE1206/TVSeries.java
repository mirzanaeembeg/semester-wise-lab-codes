
package entertainmentcompany;


public class TVSeries extends ProductionCompany {
    private String tvSeriesName;
    
    public TVSeries(){
        super();
    }

    public String getTvSeriesName() {
        return tvSeriesName;
    }

    public void setTvSeriesName(String tvSeriesName) {
        this.tvSeriesName = tvSeriesName;
    }
    
    
    public TVSeries(String tvSeriesName, String companyName) {
        super(companyName);
        this.tvSeriesName = tvSeriesName;
    }

    /**
     *
     */
    @Override
    public void productionInfo(){
        System.out.println("Series name is: "+tvSeriesName);
    }
    
    
}
