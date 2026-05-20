
package demophone;

public class Messenger implements VideoCall {
    @Override
    public void makeACall(String phoneNumber){
        System.out.println("Calling "+phoneNumber);
    }
    @Override
    public void openCamera(String camera){
        System.out.println("Opening "+camera);
    }
    public void addFilters(String F){
        System.out.println("Selecting filter:"+F);
    }
}
