
package myproject;

public class Printer implements Runnable {
    /*public String name;
    public Printer(String name){
        super();
        this.name=name;
    }*/
    public void run(){
        print();
    }
    public synchronized void print(){
        System.out.println("Printing "+Thread.currentThread().getName()+" item");
    }
}
