import java.util.Scanner;

public class Latihan04d {
    public static void main(String[] args) {
        String nama, nopel;
        int pakai, total = 0;

        try (Scanner masukan = new Scanner(System.in)) {
            System.out.println("Perhitungan Biaya Pakai");
            System.out.println("==============================");
            System.out.print("Nama           : ");
            nama = masukan.nextLine();
            System.out.print("No Pelanggan   : ");
            nopel = masukan.nextLine();
            System.out.print("Pemakaian Air  : ");
            pakai = masukan.nextInt();

            if (pakai <= 10)
                total = pakai * 1000;

            else if (pakai > 10 && pakai <= 20)
                total = (pakai - 10) * 2000 + 10000;

            else if (pakai > 20)
                total = (pakai - 20) * 5000 + 30000;

            System.out.println("\n==============================");
            System.out.println("Nama          : " + nama);
            System.out.println("No. Pelanggan : " + nopel);
            System.out.println("Pemakaian Air : " + pakai);
            System.out.println("Biaya Pakai   : " + total);
            System.out.println("==============================");
        }
    }
}