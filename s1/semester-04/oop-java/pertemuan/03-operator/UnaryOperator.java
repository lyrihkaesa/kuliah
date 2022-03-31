public class UnaryOperator {
    public static void main(String[] args) {
        String line = "------------------";

        // postfix
        // x++
        int x = 10;
        System.out.println(" xAwal    : " + x);
        System.out.println(" x++      : " + x++);
        System.out.println(" xHasil   : " + x);
        System.out.println(line);
        // Penjelasannya: "x-nya" akan ditampilkan dulu sebelum penjumlahan "x + 1" dieksekusi atau disebut dengan
        // post/setelah.

        // x--
        x = 10;
        System.out.println(" xAwal    : " + x);
        System.out.println(" x--      : " + x++);
        System.out.println(" xHasil   : " + x);
        System.out.println(line);

        // prefix
        // ++x
        x = 10;
        System.out.println(" xAwal    : " + x);
        System.out.println(" ++x      : " + ++x);
        System.out.println(" xHasil   : " + x);
        System.out.println(line);
        // Penjelasannya: "x-nya" penjumlahannya di eksekusi dulu "x + 1", lalu ditampilkan ke layar atau disebut
        // pre/sebelum

        // --x
        x = 10;
        System.out.println(" xAwal    : " + x);
        System.out.println(" --x      : " + --x);
        System.out.println(" xHasil   : " + x);
        System.out.println(line);

        // +x
        x = 10;
        System.out.println(" xAwal    : " + x);
        System.out.println(" +x      : " + +x);
        System.out.println(" xHasil   : " + x);
        System.out.println(line);

        // -x
        x = 10;
        System.out.println(" xAwal    : " + x);
        System.out.println(" -x      : " + -x);
        System.out.println(" xHasil   : " + x);
        System.out.println(line);

        // ~x
        x = 10;
        System.out.println(" xAwal    : " + x);
        System.out.println(" ~x      : " + ~x);
        System.out.println(" xHasil   : " + x);
        System.out.println(line);

        // !x
        boolean y = true;
        System.out.println(" xAwal : " + y);
        System.out.println(" !y : " + !y);
        System.out.println(" xHasil : " + y);
        System.out.println(line);
    }
}
