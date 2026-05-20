
package demothreadproject;

public class PotatoContainer {
    public int storedPotato,capacity;
    public PotatoContainer(int capacity){
        this.storedPotato=0;
        this.capacity=capacity;
    }
    synchronized public void putPotato(int numOfPotato, String name){
        if((this.storedPotato+numOfPotato)>capacity){
            try{
                System.out.println(name+" is waiting to put "+numOfPotato+" KG potato");
                System.out.println("Potato would be "+(this.storedPotato+numOfPotato)+" KG");
                wait();
                notify();
            }catch(InterruptedException e){
                System.out.println(e);
            }
        }
        this.storedPotato=this.storedPotato+numOfPotato;
        System.out.println("After "+name+" putting "+numOfPotato+" KG of potato,now "+storedPotato+" KG");
        if(this.storedPotato>1){
            notify();
        }
    }
    public synchronized void takePotato(int numOfPotato,String name){
        while((this.storedPotato-numOfPotato)<1){
            try{
                System.out.println(name+" is trying to take "+numOfPotato+" KG potato");
                System.out.println("Current "+this.storedPotato+" KG");
                notify();
                wait();
            }catch(InterruptedException e){
                System.out.println(e);
            }
        }
        this.storedPotato=this.storedPotato-numOfPotato;
        System.out.println("After "+name+" taking "+numOfPotato+" KG of potato,remaining "+this.storedPotato+"KG");
        if(this.storedPotato<1){
            notify();
        }
    }
}
