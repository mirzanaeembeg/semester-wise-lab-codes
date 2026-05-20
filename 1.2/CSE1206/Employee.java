
package demothreadproject;

import java.util.Random;

public class Employee implements Runnable{
    PotatoContainer pc;
    Random rm;

    public Employee(PotatoContainer pc) {
        this.pc = pc;
        this.rm = new Random();
    }
    public void run(){
        int storedPotat=1+rm.nextInt(5);
        pc.putPotato(storedPotat,Thread.currentThread().getName());
    }
}
