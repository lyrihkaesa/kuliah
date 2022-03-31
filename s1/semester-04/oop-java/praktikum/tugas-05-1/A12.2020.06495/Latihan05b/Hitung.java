package Latihan05b;

public class Hitung {
    void methodTambah(int a, int b) {
        System.out.println(a + " + " + b + " = " + (a + b));
    }

    void methodKurang(int a, int b) {
        System.out.println(a + " - " + b + " = " + (a - b));
    }

    void methodKali(int a, int b) {
        System.out.println(a + " * " + b + " = " + (a * b));
    }

    void methodBagi(int a, int b) {
        System.out.println(a + " / " + b + " = " + (a / b));
    }

    public static void main(String[] args) {
        Hitung objHitung = new Hitung();

        objHitung.methodTambah(10, 50);
        objHitung.methodKurang(10, 50);
        objHitung.methodKali(50, 10);
        objHitung.methodBagi(50, 10);
    }
}
