public class PostPreOperator {
    public static void main(String[] args) {
        String line = "------------------";
        // postfix
        // x++
        int x = 10;
        System.out.println(" xAwal    : " + x); // Output: 10
        System.out.println(" x++      : " + x++); // Output: 10
        System.out.println(" xHasil   : " + x); // Output: 11
        System.out.println(line);
        // * Penjelasannya:
        // * "x-nya" akan ditampilkan dulu sebelum penjumlahan "x + 1" dieksekusi atau disebut dengan post/setelah.

        // prefix
        // ++x
        x = 10;
        System.out.println(" xAwal    : " + x); // Output: 10
        System.out.println(" ++x      : " + ++x); // Output: 11
        System.out.println(" xHasil   : " + x); // Output: 11
        System.out.println(line);
        // * Penjelasannya:
        // * "x-nya" penjumlahannya di eksekusi dulu "x + 1", lalu ditampilkan ke layar atau disebut pre/sebelum
    }
}
