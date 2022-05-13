// Nomor 1
// Deklarasi Package adalah pemanggilan folder dimana file ini berada
package Kaesa;

// Import Library adalah pemanggilan package yang berisi banyak class dan interface yang sudah dideklarasikan sebelumnya
// import java.io.*;

// Bagian Class ini adalah class yang mengikuti dengan nama file dari source code java, dan
// didalamnya biasanya terdapat method main.
// Pada Java, setiap aplikasi dimulai dengan nama class, dan class itu harus cocok dengan nama file *.java
public class SP {

    // Method main adalah method yang akan dijalankan pertama kali oleh sistem.
    public static void main(String[] args) {

        // Nomor 2
        // variabel dengan nama nilaiTugas yang memiliki tipe data non primitif String
        // yang memiliki nilai "95";
        String nilaiTugas = "95";
        // variabel dengan nama totalNilai yang memiliki tipe data primitif Integer
        // (Bilangan Bulat) yang memiliki nilai 95 yang didapatkan dari parse/conversi
        // dari string "95" ke number 95.
        int totalNilai = Integer.parseInt(nilaiTugas);

        // Tambahan supaya bisa dieksekusi.
        System.out.println(totalNilai);

        // variabel dengan nama a, tanpa default value.
        int a;
        // nilai variabel a diubah menjadi 10.
        a = 10;
        // variabel dengan nama b dengan nilai 30 didapat dari ternary operation dengan
        // kondisi a kurang dari sama dengan 10 yang akan mengembalikan nilai 30 jika
        // benar dan 40 jika salah
        int b = (a <= 10 ? 30 : 40);

        // Tambahan supaya bisa dieksekusi
        System.out.println("a :" + a);
        System.out.println("b :" + b);

        // Tambahan supaya tidak error
        int x = 5;
        int y = 10;

        // menampilkan hasil dari kondisi x = x + 1 lebih besar dari 9 dan y + 1 lebih
        // besar dari 4 yang berupa boolean
        System.out.println(x++ > 9 && y + 1 > 4);

        // Nomor 3
        // https://kulino.dinus.ac.id/mod/forum/discuss.php?d=40899
        // a. BufferedReader
        // b. Scanner
        // c. JOptionPane

        // Nomor 4
        // Bilangan Ganjil
        for (int i = 1; i <= 10; i++) {
            if (i % 2 != 0) {
                System.out.println(i);
            }
        }
        // Bilangan Genap
        for (int i = 1; i <= 15; i++) {
            if (i % 2 == 0) {
                System.out.println(i);
            }
        }

        // Nomor 6
        // penjelasan,
        // Abstract class adalah sebuah class yang tidak bisa di-instansiasi (tidak bisa
        // dibuat menjadi objek)
        // dan berperan sebagai ‘kerangka dasar’ bagi class turunannya.

        // Kegunaan,
        // Class Abstract berisi beberapa method dan beberapa method abstract. Class
        // Abstract berisi sebagian implementasi, dan subclass yang melengkapi
        // implementasinya.
        // Deklarasikan method abstract, jika ada satu atau lebih subclass yang
        // diharapkan mempunyai fungsionalitas yang sama tapi implementasi berbeda.
        // Gunakan class abstract untuk mendefinisikan behavior secara umum sebagai
        // superclass, sedangkan subclass menyediakan implementasi detail.
        // Jika class abstract semua method merupakan method abstract, sebaiknya class
        // abstract tersebut diganti menjadi Interface.

    }
}
