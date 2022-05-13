public class Main03_1 {
    int i;

    // constructor without parameter....
    private Main03_1() {
        i = 5;
        System.out.println("Constructor is Called!");
    }

    public static void main(String[] args) {
        Main03_1 obj = new Main03_1();
        System.out.println("Value of i : " + obj.i);
    }

}
