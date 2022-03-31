# Pengantar

Bahasa Pemrograman (Programming Language) adalah sebuah instruksi standar untuk memerintah komputer agar menjalankan fungsi tertentu.
Bahasa pemrograman ini merupakan suatu **himpunan** dari **aturan sintaks dan semantik** yang dipakai untuk mendefinisikan program komputer.

## Paradigma Pemrograman

Jenis Paradigma Pemrograman:

1. Pemrograman Fungsional  
   Program dibangun dengan menerapkan dan menyusun fungsi.  
   `(LISP, Haskell, Scala, Scheme)`
2. Pemrograman Prosedural atau Iteratif  
   Dilakukan dengan memberikan serangkaian perintah yang berurutan.  
   `(Pascal, C, PHP)`
3. Pemrograman Berorientasi Objek  
   Berdasarkan konsep "objek", yang dapat berisi data, dalam bentuk field atau dikenal juga sebagai atribut; serta kode, dalam bentuk fungsi/prosedur atau dikenal juga sebagai method.  
   `(C++, Java, Smalltalk, PHP)`
4. Pemrograman Deklaratif, Predikatif atau Lojik  
   Paradigma pemrograman yang mengekspresikan logika komputasi tanpa menjelaskan aliran kontrolnya.
   `(Prolog)`

## Sejarah Program Java

Java dikembangkan pada tahun 1990 oleh insinyur Sun, **James Gosling** sebagai bahasa pemrograman yang berperan sebagai otak untuk peralatan pintar (TV interaktif, oven serba bisa).  
Gosling menamakan bahasa pemograman barunya **Oak**, nama sebuah pohon yang bisa ia lihat dari **jendela kantornya**; ia kemudian menamainya **Green**, dan kemudian mengganti namanya menjadi **Java**, berasal dari **kopi Jawa (Java Coffee)**, yang katanya banyak dikonsumsi dalam jumlah besar oleh pencipta bahasa ini.

## Jenis Java

- **Java Platform Standard Edition [J2SE]**  
  Banyak digunakan sebagai platform untuk pemrograman dalam bahasa Java.
- **Java Platform Enterprise Edition [J2EE]**  
  Standar untuk mengembangkan aplikasi skala besar / enterprise. J2EE banyak digunakan sebagai platform untuk pemrograman di sisi server.
- **Java Platform Micro Edition [Java ME]**  
  Salah satu platform java yang dirancang untuk aplikasi mobile dan sistem tertanam (embedded system). Level Java ME digunakan untuk merancang perangkat lunak handphone dan PDA.

## 💻 Lingkungan Pengembangan

- ⚒ Mengunduh JDK (Java Developer Kit)

  - [JDK Oralce](https://www.oracle.com/java/technologies/downloads) 💰  
    Sepertinya ini berlasensi, tidak Open Source ~~Gratis~~.
  - [OpenJDK](https://jdk.java.net/) ✅ Direkomendasikan.  
    JDK ini Open Source alias `gratis`.

- 👩‍💻 Mengunduh IDE (Integrated Development Environment)  
  Editor cangih, dimana editor ini mirip dengan `📝Notepad` pada Windows 10, dengan banyak fitur yang mempermudah kita sat koding.  
  Saya menggunakan [Visual Studio Code [VSCode]](https://code.visualstudio.com/download) versi `System Installer` karena saya ingin menginstallnya pada sistem Windows 10.  
  Salah satu fiturnya adalah:

  - Auto Correct
  - Auto Complite
  - Sintak Highlight (Memberikan warna karakter dan simbol)
  - dll

---

## Struktur Program Java ☕

Struktur program java dibagi menjadi `empat` bagian:

```java
// 1. Deklarasi Package (Mendeklarasikan Paket)
package pbo.program;

// 2. Import Library (Memasukan Perpustakaan)
import java.io.File;

// 3. Bagian class
public class HelloWorld {
    // 4. Method Main (Fungsi Utama)
     public static void main(String[] args) {
        System.out.println("Hallo World");
    }
}
```

## ⚙ Cara Kerja Program Java

1. Membuat aplikasi Java di text editor [IDE]  
   (Visual Studio Code, Jcreator, NotePad, UltraEdit, WordPad, dsb) dan disimpan dengan eksentensi `*.java`
2. **Meng-kompilasi** file tersebut dengan perintah `javac` pada `command prompt` (comman prompt adalah aplikasi yang ada di windows), atau meng-kompile dengan menggunakan IDE tertentu.  
   Dalam istilah Java, kode objek ini disebut `bytecode`, Hasil kompilasi ini akan menghasilkan file baru berekstensi `*.class`
3. JVM (Java Virtual Machine) akan **menginterpretasikan** file `*.class` tersebut menjadi kode-kode yang bisa di jalankan pada platform tersebut.
4. Proses eksekusi program sesuai dengan `bytecode` yang sudah diinterpretasikan oleh JVM.

| Keterangan           | Ekstensi  | Dibutuhkan                                               |
| -------------------- | --------- | -------------------------------------------------------- |
| Source Code          | `*.java`  | IDE                                                      |
| Object (bytecode)    | `*.class` | Compailler `javac` (java compailer)                      |
| Run Program          | `*.class` | Interpreted `java` [JVM] (Java Virtual Machine) atau JRE |
| Arsip (Java Archive) | `*.jar`   | ???                                                      |
