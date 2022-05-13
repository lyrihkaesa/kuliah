public class Mobil05_1 {
    String nama;

    Mobil05_1() {
    }

    Mobil05_1(String nama) {
        this.nama = nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }
}

class CobaMobil {
    public static void main(String[] args) {
        Mobil05_1 mobilx = new Mobil05_1();
        Mobil05_1 mobilLCGC = new Mobil05_1("Agya");
        System.out.println("Mobil LCGC    : " + mobilLCGC.nama);
        mobilx.setNama("Wuling");
        System.out.println("Mobil         : " + mobilx.nama);
    }
}
