
package entertainmentcompany;

public class EntertainmentCompany {

    public static void main(String[] args) {
    
        WebSeries web1 = new WebSeries("Squid game","Netflix","Netflix Inc");
        TVSeries tv1 = new TVSeries("Bachelor Point","GOODLUC");
        web1.productionInfo();
        web1.stopProduction();
        tv1.productionInfo();
        tv1.stopProduction();
    }
    
}
