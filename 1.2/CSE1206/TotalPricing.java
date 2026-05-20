
package costestimation;

public class TotalPricing {
    public Book bookObj;
    TotalPricing(Book bookObj){
        this.bookObj=bookObj;
    }
    public void finalCost(){
        int x = bookObj.getCostPerPage()*bookObj.getNumberOfPages();
        System.out.println(x);
        int y=x*x;
        int z=y%10;
        if(z==x)
            System.out.println("Pricing is too high");
        
        else
            System.out.println("Pricing is okay");
    }
}
