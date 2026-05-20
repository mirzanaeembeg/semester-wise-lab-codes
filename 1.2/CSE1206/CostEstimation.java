
package costestimation;

public class CostEstimation {

    public static void main(String[] args) {
    Book book1=new Book(120,2);
    TotalPricing price1=new TotalPricing(book1);
    price1.finalCost();
    }
    
}
