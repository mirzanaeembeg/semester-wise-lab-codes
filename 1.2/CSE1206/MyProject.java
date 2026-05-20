
package myproject;

public class MyProject {

    public static void main(String[] args) {
        Printer p1 = new Printer();
        Printer p2 = new Printer();
        Thread t1 = new Thread(p1);
        Thread t2 = new Thread(p2);
        t1.setName("T1");
        t2.setName("T2");
        t1.start();
        t2.start();
        try{
            t1.join();
        }catch(InterruptedException ex){
            System.out.println(ex);
        }
        System.out.println("Main thread");
    }
    
}
