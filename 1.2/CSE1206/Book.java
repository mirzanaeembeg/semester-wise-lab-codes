
package costestimation;

public class Book {
    private int numberOfPages;
    private int costPerPage;
    
    Book(int numberOfPages,int costPerPage ){
        this.numberOfPages=numberOfPages;
        this.costPerPage=costPerPage;
    }
    public void setNumberOfPages(int numberOfPages){
        this.numberOfPages=numberOfPages;
    }
    public void setCostPerPage(int numberOfPages){
        this.costPerPage=costPerPage;
    }
    public int getNumberOfPages(){
        return this.numberOfPages;
    }
    public int getCostPerPage(){
        return this.costPerPage;
    }
}
