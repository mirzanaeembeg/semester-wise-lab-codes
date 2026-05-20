
package demophone;

public abstract class MobilePhone implements PhoneCall {
    public abstract void sendSMS(String R,String mgs);
    public abstract void saveContact(String name,String phoneNumber);
    @Override
    public abstract void makeACall(String phoneNumber);
}
