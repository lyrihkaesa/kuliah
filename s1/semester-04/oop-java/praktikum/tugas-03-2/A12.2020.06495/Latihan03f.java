public class Latihan03f {
    public static void main(String[] args) {
        int a = 8;
        int b = 10;

        System.out.println("Nilai a     : " + (a)); // Output: 8
        System.out.println("Nilai b     : " + (b)); // Output: 10
        System.out.println("a++         : " + (a++)); // Output: 8
        // Ouputnya bisa 8 karena "a"-nya tampil dulu sebelum dijumlahkan. (a"tampil dulu (8)" = 8 + 1).
        System.out.println("++b         : " + (++b)); // Output: 11
        // Outputnya bisa 11 karena "b"-nya dihitung dulu setelah itu ditampilkan pada layar.
        // (b + 1 = b"tampil setelah dihitung (11)")
        System.out.println("a++ + ++a   : " + (a++ + ++a)); // Output: 20
        // {a = 9 + 1} + {10 + 1 = a} a tampil dulu sebelum dihitung, terus ditambahkan a lagi yang sudah dihitung
        // a:9 + a:11 = 20
        System.out.println("b++ + b++   : " + (b++ + b++)); // Output: 23
        // {b = 11 + 1} + {b = 12 + 1} | b tampil dulu sebelum dihitung.
        // b:11 + b:12 = 23
        System.out.println("\n=====================");
        System.out.println("Program : Latihan03f");
        System.out.println("NIM     : A12.2020.06495");
        System.out.println("Nama    : Kukuh Setya A.");
    }
}