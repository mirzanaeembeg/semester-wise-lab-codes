
package demothreadproject;

import java.util.Random;

public class Customer implements Runnable {
    PotatoContainer pc;
    Random rm;

    public Customer(PotatoContainer pc) {
        this.pc = pc;
        this.rm = new Random();
    }
    public void run(){
        int storedPotat=1+rm.nextInt(5);
        pc.takePotato(storedPotat,Thread.currentThread().getName());
    }
}
