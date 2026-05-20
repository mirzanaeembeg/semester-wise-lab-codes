
package demophone;

public class DemoPhone {

    public static void main(String[] args) {
        Samsung S22 =new Samsung();
        Messenger m = new Messenger();
        S22.makeACall("01521738367");
        S22.saveContact("Naeem", "01521738367");
        S22.sendSMS("Naeem","I love you!");
        m.makeACall("01521738367");
        m.openCamera("front camera");
    }
    
}
