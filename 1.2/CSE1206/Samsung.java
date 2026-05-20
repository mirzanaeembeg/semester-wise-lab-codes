
package demophone;

public class Samsung extends MobilePhone {
    @Override
    public void sendSMS(String R,String mgs){
        System.out.println("Sending "+R+" message:"+mgs);
    }
    @Override
    public void saveContact(String name,String phoneNumber){
        System.out.println("Saving "+name+",Number:"+phoneNumber);
    }
    @Override
    public void makeACall(String phoneNumber){
        System.out.println("Calling "+phoneNumber);
    }
}
