public class Overloading02 {
    String nama;
    int ccmobil;

    Overloading02(String nama) {
        this.nama = nama;
    }

    Overloading02(String nama, int ccmobil) {
        this.nama = nama;
        this.ccmobil = ccmobil;
    }
}

class CobaMobil1 {
    public static void main(String[] args) {
        Overloading02 mobilA = new Overloading02("Agya");
        Overloading02 mobilB = new Overloading02("Katana", 1500);
        System.out.println("Mobil  : " + mobilA.nama);
        System.out.println("Mobil  : " + mobilB.nama);
    }
}
