public class Latihan01c {
    public static void main(String[] args) {
        int a = 0;
        System.out.println("a   : " + a); // a : 0
        System.out.println("a++ : " + a++); // a++ : 0 | a = a + 1 | "a" nya di tampilkan dulu sebelum ditambah "+1"
        System.out.println("a   : " + a); // a : 1
        System.out.println("++a   : " + ++a); // ++a : 2 | a + 1 = a | "a" nya di tambah "+1" dulu sebelum ditampilkan
        System.out.println("a   : " + a); // a : 2
        System.out.println("a--   : " + a--); // a-- : 2 | a = a - 1
        System.out.println("a   : " + a); // a : 1
        System.out.println("--a   : " + --a); // --a : 0 | a - 1 = a
        System.out.println("a   : " + a); // a : 0
    }
}
