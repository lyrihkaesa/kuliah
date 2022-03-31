public class Latihan02e {
  public static void main(String[] args) {
    int a, t;
    double luas;
    // int luas; // error: Type mismatch: cannot convert from double to int

    a = 2;
    t = 7;

    luas = 0.5 * a * t;

    System.out.println("Luas Segitiga : " + luas); // Output: Luas Segitiga : 7.0

    // Ubahlah tipe data dari variabel luas dengan int, apa hasilnya?
    // Hasilnya error berikut:
    // Type mismatch: cannot convert from double to int

    // Solusi:
    int luasInt;

    // luasInt = 0.5 * a * t;
    // error: Type mismatch: cannot convert from double to int
    // Kode diatas error karena ada desimal "0.5"

    // luasInt = (int) luas; // Opsi-01
    luasInt = a * t / 2; // Opsi-02

    System.out.println("Luas Segitiga : " + luasInt); // Output: Luas Segitiga : 7
  }
}