import java.util.Scanner;

public class Latihan04c {
    public static void main(String[] args) {
        String nama, prodi, ket = "";
        int nilai;
        try (Scanner input = new Scanner(System.in)) {
            System.out.println("Data Tes");
            System.out.println("==========================");
            System.out.print("Nama          : ");
            nama = input.nextLine();
            System.out.print("Program Studi : ");
            prodi = input.nextLine();
            System.out.print("Nilai         : ");
            nilai = input.nextInt();

            if (nilai > 80 && nilai <= 100) {
                ket = "A";
            } else if (nilai > 65 && nilai <= 80) {
                ket = "B";
            } else if (nilai > 50 && nilai <= 65) {
                ket = "C";
            } else if (nilai > 40 && nilai <= 50) {
                ket = "D";
            } else if (nilai <= 40) {
                ket = "E";
            }

            System.out.println("\n==========================");
            System.out.println("Nama          : " + nama);
            System.out.println("Program Studi : " + prodi);
            System.out.println("Nilai         : " + nilai);
            System.out.println("Nilai Huruf   : " + ket);
            System.out.println("==========================");
        }
    }
}
