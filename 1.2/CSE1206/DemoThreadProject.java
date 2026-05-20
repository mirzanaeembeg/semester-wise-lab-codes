package demothreadproject;

public class DemoThreadProject {

    public static void main(String[] args) {

        PotatoContainer pc = new PotatoContainer(50);

        Employee e = new Employee(pc);
        Customer c = new Customer(pc);

        Thread e1 = new Thread(e, "e1");
        Thread c1 = new Thread(c, "c1");

        e1.start();
        c1.start();
    }

}
