public class Latihan03e {
    public static void main(String[] args) {
        int a = 8;
        int b = 20;

        System.out.println("Nilai a     : " + (a)); // Output: 8
        System.out.println("Nilai b     : " + (b)); // Output: 20
        System.out.println("Nilai a>>1  : " + (a >> 1)); // Output: 4
        // BINARY dari a(8): 0000 1000
        // SHIFT: digeser ke kanan 1 (a >> 1) menjadi 0000 0100
        // 0000 0100 diubah ke desimal menjadi 4
        System.out.println("Nilai a>>2  : " + (a >> 2)); // Output: 2
        // BINARY dari a(8): 0000 1000
        // SHIFT: digeser ke kanan 2 (a >> 2) menjadi 0000 0010
        // 0000 0010 diubah ke desimal menjadi 2
        System.out.println("Nilai b<<1  : " + (b << 1)); // Output: 40
        // BINARY dari b(20): 0001 0100
        // SHIFT: digeser ke kiri 1 (b << 1) menjadi 0010 1000
        // 0010 1000 diubah ke desimal menjadi 40
        System.out.println("Nilai b<<2  : " + (b << 2)); // Output: 80
        // BINARY dari b(20): 0001 0100
        // SHIFT: digeser ke kiri 1 (b << 1) menjadi 0101 0000
        // 0101 0000 diubah ke desimal menjadi 80

        System.out.println("\n=====================");
        System.out.println("Program : Latihan03e");
        System.out.println("NIM     : A12.2020.06495");
        System.out.println("Nama    : Kukuh Setya A.");
    }
}