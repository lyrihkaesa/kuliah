public class Latihan03b {
    public static void main(String[] args) {
        int a, hasil;
        a = 14;

        hasil = (a++ > 14) ? 10 : 20; // (14 > 14), salah karena 14 lebih dari 14
        System.out.println("Output Satu  : " + hasil); // Output(false): 20

        // a = 15
        hasil = (a <= 14) ? 30 : 40; // (15 <= 14), salah karena 15 lebih besar dari 14
        System.out.println("Output Dua   : " + hasil); // Output(false): 40

        hasil = (a > 14 && a < 45) ? 50 : 60;
        // (15 > 14 && 15 < 45), benar karena 15 lebih dari 14 dan 15 kurang dari 50,
        // dan operator perbandingan && "dan" harus keduanya benar agar hasilnya
        // benar/true
        System.out.println("Output Tiga  : " + hasil); // Output(true): 50

        hasil = (a <= 14 || a < 45) ? 70 : 80;
        // (15 <= 14 || 15 < 45), benar karena 15 kurang dari 45 atau 15 kurang dari
        // sama dengan 14, dan operator perbandingan || "atau" jika salah satu benar
        // maka hasilnya benar/true
        System.out.println("Output Empat : " + hasil); // Output(true): 70

        System.out.println("\n========================");
        System.out.println("Program : Latihan03b");
        System.out.println("NIM     : A12.2020.06495");
        System.out.println("Nama    : Kukuh Setya A.");
    }
}