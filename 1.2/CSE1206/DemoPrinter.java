
public class DemoPrinter {

    public static void main(String[] args) {
        Printer p = new Printer();
        Pdf ob = new Pdf();
        Jpeg obj = new Jpeg();
        p.print(ob);
        p.print(obj);
    }
    
}
