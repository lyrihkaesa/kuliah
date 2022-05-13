class Pegawai {
    public String idNIP;
    public String nama;

    public void hitungGapok() {
        System.out.println("ini gaji pokok!");
    }

    public void printPegawai() {
        System.out.println("NIP  : " + idNIP);
        System.out.println("Nama : " + nama);
    }
}

class Guru extends Pegawai {
    public double serGur;
}

class Tendik extends Pegawai {
    public int Honor;
}

public class HI {
    public static void main(String[] args) {
        Guru guru = new Guru();
        guru.serGur = 6479;

        Tendik tendik = new Tendik();
        tendik.Honor = 122006479;

        System.out.println("Sertifikat Guru : " + guru.serGur);
        System.out.println("Honor Tendik : " + tendik.Honor);

        guru.idNIP = "A12.2020.06476";
        guru.nama = "Farhan Taqi";
        guru.hitungGapok();
        guru.printPegawai();

    }
}
