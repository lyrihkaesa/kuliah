public class TernaryOperator {
    public static void main(String[] args) {
        int a = 14;
        System.out.println("b = ( a++:" + (a++) + " > " + 14 + " ) ? true : false");
        a = 14;
        boolean b = (a++ > 14) ? true : false;
        System.out.println("Output b: " + b);

        System.out.println("-----------------");

        System.out.println("b = ( a++:" + a + " <= " + 14 + " ) ? true : false");
        b = (a <= 14) ? true : false;
        System.out.println("Output b: " + b);

        System.out.println("-----------------");

        a = 14;
        System.out.println("b = ( ++a:" + (++a) + " > " + 14 + " ) ? true : false");
        a = 14;
        b = (++a > 14) ? true : false;
        System.out.println("Output b: " + b);

        System.out.println("-----------------");

        System.out.println("b = ( ++a:" + a + " <= " + 14 + " ) ? true : false");
        b = (a <= 14) ? true : false;
        System.out.println("Output b: " + b);
    }
}
