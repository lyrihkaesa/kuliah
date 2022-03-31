import java.util.Scanner;
// import java.io.*; // error: The import java.io is never used
// Solusi error diatas: "hapus atau komentari" import java.io

public class Latihan02j {
  public static void main(String[] args) {

    // Scanner u_input = new Scanner(System.in); // error: Resource leak: 'u_input' is never closed

    // Solusi error diatas:
    try (Scanner u_input = new Scanner(System.in)) {
      String nama;
      int nilai1, nilai2;
      float rata2;

      System.out.print("Nama        : ");
      nama = u_input.next(); // Input: Kukuh
      // nama = u_input.nextLine(); // gunakan *.nextLine() untuk input String yang ada "spasinya" // Input: Kukuh Setya A
      System.out.print("Nilai1      : ");
      nilai1 = u_input.nextInt(); // Input: 95
      System.out.print("Nilai2      : ");
      nilai2 = u_input.nextInt(); // Input: 88

      System.out.println("======================");
      rata2 = (nilai1 + nilai2) / 2;
      System.out.println("Nama      : " + nama); //  Output: Nama      : Kukuh
      System.out.println("Rata-rata : " + rata2); // Output: Rata-rata : 91.0
    }
  }
}
