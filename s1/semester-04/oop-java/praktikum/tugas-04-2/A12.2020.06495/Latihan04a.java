import java.util.Scanner;

public class Latihan04a {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            String nama;
            int anak, tanak, gaji, total;

            // Judul
            System.out.println("Hitung tunj. anak");
            System.out.println("===============================\n");

            // input
            System.out.print("Nama            : ");
            nama = input.next();
            System.out.print("Anak            : ");
            anak = input.nextInt();
            System.out.print("Gaji            : ");
            gaji = input.nextInt();
            System.out.println("===============================\n");
            // sum tunj. anak
            if (anak > 3) {
                tanak = 3 * 200000;
            } else {
                tanak = anak * 200000;
            }

            total = gaji + tanak;

            // Output
            System.out.println("Nama            : " + nama);
            System.out.println("Tunjangan Anak  : " + tanak);
            System.out.println("Total           : " + total);
        }
    }
}
