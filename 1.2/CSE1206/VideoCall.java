
package demophone;

public interface VideoCall extends PhoneCall {
    @Override
    public void makeACall(String phoneNumber);
    public void openCamera(String camera);
}
