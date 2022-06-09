package src.entity;

public class Pegawai {
    private String nip;
    private String nama;
    private String bagian;
    private String jenisKelamin;
    private String password;

    public String getNip() {
        return this.nip;
    }

    public void setNip(String nip) {
        this.nip = nip;
    }

    public String getNama() {
        return this.nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getBagian() {
        return this.bagian;
    }

    public void setBagian(String bagian) {
        this.bagian = bagian;
    }

    public String getJenisKelamin() {
        return this.jenisKelamin;
    }

    public void setJenisKelamin(String jenisKelamin) {
        this.jenisKelamin = jenisKelamin;
    }

    public String getPassword() {
        return this.password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
