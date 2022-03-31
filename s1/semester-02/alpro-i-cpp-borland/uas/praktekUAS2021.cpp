#include <conio.h> // getch()
#include <iostream.h> // cout, cin {untuk tipe data tanpa spasi}
#include <stdio.h> // gets {untuk tipe data char}
#define namaEntity "PT. Terang Benerang"
#define almtEntity "Jl. Merdeka Raya 17"
#define kotaEntity "Semarang"
#define maxHuruf 16
#define maxHurufNIP 5

// struct data pelanggan
struct sPgw {
    char nip[maxHurufNIP], namaPegawai[maxHuruf], jenisKelamin[maxHuruf], status[maxHuruf];
    int jumlahAnak, gajiPokok, tunjIstri, tunjAnak, gajiKotor, pajak, biayaJabatan, gajiBersih;
};
sPgw dataPegawai[100];

int a = 0;

// Fungsi Prototype (Function Prototype)
void garisH(int kolom, int baris, int kolom_awal=2);
void garisHT(int kolom, int baris, int kolom_awal=2);
void garisV(int kolom, int baris, int baris_awal=2);
void entityProp(int kolom, int baris);
void templateUtama();
void menuUtama(int kolom, int baris);
void pilihanMenu(int kolom, int baris);
void tampilanEdit(int kolom, int baris);
void tampilanHitungHarga(int kolom, int baris);
int jumlahHuruf(const char *temp);
void jumlahTitik(int kolom, int baris, int mxHuruf);
void jumlahSpasi(int kolom, int baris, int mxHuruf);
void isiNIP(int kolom, int baris, int mxHuruf);
void isiNamaPegawai(int kolom, int baris, int mxHuruf);
void isiJenisKelamin(int kolom, int baris);
void isiStatus(int kolom, int baris);
void isiGajiPokok(int kolom, int baris);
void inputData(int kolom, int baris);
void ketikInputData(int kolom, int baris);
void outputData(int kolom, int baris);
void prosesTunjanganIstri(int kolom, int baris);
void prosesTunjanganAnak(int kolom, int baris);
void prosesGajiKotor(int kolom, int baris);
void prosesPajak(int kolom, int baris);
void prosesBiayaJabatan(int kolom, int baris);
void prosesGajiBersih(int kolom, int baris);
void laporanGaji(int kolom, int baris);
void judulLaporan(int kolom, int baris);
void cetakData(int kolom, int baris);
void bubble(int kolom, int baris);

// Deklarasi Garis Utama
int gh = 88, gv = 20;

void main() {
    int pilih;
    do {
        clrscr();
        templateUtama();
        menuUtama(0, 8);
        pilihanMenu(0, (gv-1)); cin >> pilih;
        switch (pilih) {
            case 1 : inputData(5, 8);
            break;
            case 2 : bubble(0, gv-4);
            break;
            case 3 : laporanGaji(3, 8);
            break;
        }
    } while (pilih != 4);
}

// Definisi Function Prototype
void garisH(int kolom, int baris, int kolom_awal){
    for(int i=kolom_awal;i<kolom;i++){
        gotoxy(i, baris); cout << "_";
    }
}

void garisHT(int kolom, int baris, int kolom_awal){
    for(int i=kolom_awal;i<kolom;i++){
        gotoxy(i, baris); cout << "-";
    }
}

void garisV(int kolom, int baris, int baris_awal){
    for(int i=baris_awal;i<baris;i++){
        gotoxy(kolom, i); cout << "|";
    }
}

// Tampilkan Indentitas Entity/PT
void entityProp(int kolom, int baris){
    gotoxy(kolom, baris++); cout << namaEntity;
    gotoxy(kolom, baris++); cout << almtEntity;
    gotoxy(kolom, baris++); cout << kotaEntity;
}

// Tampilkan Template Utama
void templateUtama(){
    // Garis Horizontal
    garisH(gh, 1);
    garisH(gh, 6);
    garisH(gh, gv);
    // Garis Vertikal
    garisV(1, (gv+1));
    garisV(gh, (gv+1));
    // Tampilkan Identitas Entity
    entityProp(3, 3);
}

// Tampilan Menu Utama
void menuUtama(int kolom, int baris){
    int jT = 30;
    kolom = ((gh-jT)/2)+kolom;
    gotoxy(kolom, baris++); cout << "Menu Utama";
    baris++;
    gotoxy(kolom, baris++); cout << "1. Input Gaji Pegawai";
    gotoxy(kolom, baris++); cout << "2. Urutkan Data (Bubble Sort)";
    gotoxy(kolom, baris++); cout << "3. Laporan Gaji Pegawai";
    gotoxy(kolom, baris++); cout << "4. Exit (Keluar)";
    garisH(gh, (gv-3));
}

void pilihanMenu(int kolom, int baris){
    char tulisan[] = "Pilihan anda [1,2,3,4=exit] : ";
    int jT = jumlahHuruf(tulisan);
    gotoxy((((gh-jT)/2)+kolom), baris); cout << tulisan;    
}

void tampilanEdit(int kolom, int baris){
    gotoxy(kolom, baris++); cout << "1. NIP               = ";
    gotoxy(kolom, baris++); cout << "2. Nama Pegawai      = ";
    gotoxy(kolom, baris++); cout << "3. Jenis Kelamin[P/W]= ";
    gotoxy(kolom, baris++); cout << "4. Status [0,1,2,3,4]= ";
    gotoxy(kolom, baris++); cout << "   Jumlah anak       = ";
    gotoxy(kolom, baris++); cout << "5. Gaji Pokok        = ";
}

void tampilanHitungHarga(int kolom, int baris){
    gotoxy(kolom, baris++); cout << "Tunjangan Istri      = ";
    gotoxy(kolom, baris++); cout << "Tunjangan Anak       = ";
    gotoxy(kolom, baris++); cout << "Gaji Kotor           = ";
    gotoxy(kolom, baris++); cout << "Pajak                = ";
    gotoxy(kolom, baris++); cout << "Biaya Jabatan        = ";
    gotoxy(kolom, baris++); cout << "Gaji Bersih          = ";
}

void inputData(int kolom, int baris){
    char tanya;
    do {
        clrscr();
        int barisF = baris;
        char judulAtas[] = "Input Gaji Pegawai";
        int xJA = jumlahHuruf(judulAtas);
        templateUtama();
        gotoxy(((gh-xJA)/2), barisF++); cout << judulAtas;
        barisF = barisF+1;
        tampilanEdit(kolom, barisF);
        int kolomA = kolom + maxHuruf + 1 + 25; // 2 adalah spasi antar kolom, 25 panjang huruf tertinggi di tampilanEdit() yaitu (24+1);
        tampilanHitungHarga(kolomA, barisF);
        ketikInputData((kolom+23), barisF);
        //isi data berikutnya [y]....................
        outputData((kolom+65), barisF);
        gotoxy(kolom, (barisF+8)); cout << "Ulangi Lagi [Y/T]: "; cin >> tanya;
        a++;
    } while (tanya == 89 || tanya == 121);
}


// Input Gaji Pegawai
void ketikInputData(int kolom, int baris){
    isiNIP(kolom, baris++, maxHurufNIP);
    isiNamaPegawai(kolom, baris++, maxHuruf);
    isiJenisKelamin(kolom, baris++);
    isiStatus(kolom, baris++);
    gotoxy(kolom, baris++); cout << dataPegawai[a].jumlahAnak;
    isiGajiPokok(kolom, baris++);
}

// Output Proses Pegawai
void outputData(int kolom, int baris){
    if(strcmp("Pria", dataPegawai[a].jenisKelamin) == 0){
        prosesTunjanganIstri(kolom, baris++);
        prosesTunjanganAnak(kolom, baris++);
    } else {
        gotoxy(kolom, baris++); cout << dataPegawai[a].tunjIstri;
        gotoxy(kolom, baris++); cout << dataPegawai[a].tunjAnak;               
    }
    prosesGajiKotor(kolom, baris++);
    prosesPajak(kolom, baris++);
    prosesBiayaJabatan(kolom, baris++);
    prosesGajiBersih(kolom, baris++);
}

void laporanGaji(int kolom, int baris){
    clrscr();
    char judulAtas[] = "Laporan Gaji Pegawai";
    int xJA = jumlahHuruf(judulAtas);
    templateUtama();
    gotoxy(((gh-xJA)/2), baris++); cout << judulAtas;
    baris++;
    garisHT(gh, baris++);
    judulLaporan(kolom, baris++);
    garisHT(gh, baris++);
    cetakData(kolom, baris++);
    getch();
}

void judulLaporan(int kolom, int baris){
    gotoxy(kolom, baris); cout << "No.";
    kolom += 5;
    gotoxy(kolom, baris); cout << "NIP ";
    kolom += maxHurufNIP;
    gotoxy(kolom, baris); cout << " ";
    kolom += 1;
    gotoxy(kolom, baris); cout << "Nama Peg.";
    kolom += maxHuruf + 1;
    gotoxy(kolom, baris); cout << "Gaji Pokok";
    kolom += 12;
    gotoxy(kolom, baris); cout << "Tunj. Istri";
    kolom += 13;
    gotoxy(kolom, baris); cout << "Tunj. Anak";
    kolom += 12;
    gotoxy(kolom, baris); cout << "G. Kotor";
    kolom += 10;
    gotoxy(kolom, baris); cout << "G. Bersih";
}

void cetakData(int kolom, int baris){
    int len = a;
    for (int i=0; i < len; i++) {
    int kolomi = kolom;
    gotoxy(kolomi, baris); cout << (i+1);
    kolomi += 5;
    gotoxy(kolomi, baris); cout << dataPegawai[i].nip;
    kolomi += maxHurufNIP;
    gotoxy(kolomi, baris); cout << " ";
    kolomi += 1;
    gotoxy(kolomi, baris); cout << dataPegawai[i].namaPegawai;
    kolomi += maxHuruf + 1;
    gotoxy(kolomi, baris); cout << dataPegawai[i].gajiPokok;
    kolomi += 12;
    gotoxy(kolomi, baris); cout << dataPegawai[i].tunjIstri;
    kolomi += 13;
    gotoxy(kolomi, baris); cout << dataPegawai[i].tunjAnak;
    kolomi += 12;
    gotoxy(kolomi, baris); cout << dataPegawai[i].gajiKotor;
    kolomi += 10;
    gotoxy(kolomi, baris); cout << dataPegawai[i].gajiBersih;
    baris++;
    }
}

// Proses Memasukan Data (Input Data)
// Menghitung Jumlah Huruf (Jumlah Character) yang dimasukan
int jumlahHuruf(const char *temp){
    int x = 0;
    for( ;*temp != '\0'; temp++) ++x;
    return x;
}

void jumlahTitik(int kolom, int baris, int mxHuruf){
    gotoxy(kolom, baris);
    for(int i = 0; i < mxHuruf; i++){
        cout << ".";
    }
}

void jumlahSpasi(int kolom, int baris, int mxHuruf){
    gotoxy(kolom, baris);
    for(int i = 0; i < mxHuruf; i++){
        cout << " ";
    }
}

void isiNIP(int kolom, int baris, int mxHuruf){
    jumlahTitik(kolom, baris, mxHuruf);
    jumlahSpasi((kolom+5), baris, 11);
    gotoxy(kolom, baris); gets(dataPegawai[a].nip);
    if(jumlahHuruf(dataPegawai[a].nip) != mxHuruf) {
        isiNIP(kolom, baris, mxHuruf);
    }
}

void isiNamaPegawai(int kolom, int baris, int mxHuruf){
    jumlahTitik(kolom, baris, mxHuruf);
    gotoxy(kolom, baris); gets(dataPegawai[a].namaPegawai);
    if(jumlahHuruf(dataPegawai[a].namaPegawai) < 4) {
        isiNamaPegawai(kolom, baris, mxHuruf);
    }
}

void isiJenisKelamin(int kolom, int baris){
    jumlahTitik(kolom, baris, 1);
    jumlahSpasi(kolom++, baris, 16);
    char input[2];
    gotoxy(--kolom, baris); gets(input);
    if(strcmp("P", input) == 0 || strcmp("p", input) == 0){
        strcpy(dataPegawai[a].jenisKelamin,"Pria");
    } else if(strcmp("W", input) == 0 || strcmp("w", input) == 0){
        strcpy(dataPegawai[a].jenisKelamin,"Wanita");
    } else {
        isiStatus(kolom, baris);
    }
    gotoxy((kolom+2), baris); cout << "(" << dataPegawai[a].jenisKelamin << ")";
}

void isiStatus(int kolom, int baris){
    jumlahTitik(kolom, baris, 1);
    jumlahSpasi(kolom++, baris, 16);
    int input;
    gotoxy(--kolom, baris); cin >> input;
    switch (input) {
        case 0:{
            strcpy(dataPegawai[a].status, "Belum Menikah");
            dataPegawai[a].jumlahAnak = 0;
        }
        break;
        case 1:{
            strcpy(dataPegawai[a].status, "Menikah anak 1");
            dataPegawai[a].jumlahAnak = 1;
        }
        break;
        case 2:{
            strcpy(dataPegawai[a].status, "Menikah anak 2");
            dataPegawai[a].jumlahAnak = 2;
        }
        break;
        case 3:{
            strcpy(dataPegawai[a].status, "Menikah anak 3");
            dataPegawai[a].jumlahAnak = 3;
        }
        break;
        case 4:{
            strcpy(dataPegawai[a].status, "Menikah anak 4");
            dataPegawai[a].jumlahAnak = 4;
        }
        break;
        default : isiStatus(kolom, baris);
        break;
    }
    gotoxy((kolom+2), baris); cout << "(" << dataPegawai[a].status << ")";    
}

void isiGajiPokok(int kolom, int baris){
    jumlahTitik(kolom, baris, 10);
    gotoxy(kolom, baris); cin >> dataPegawai[a].gajiPokok;
}

void prosesTunjanganIstri(int kolom, int baris){
    dataPegawai[a].tunjIstri = 0.1 * dataPegawai[a].gajiPokok;
    gotoxy(kolom, baris); cout << dataPegawai[a].tunjIstri;
}

void prosesTunjanganAnak(int kolom, int baris){
    int tPerAnak = 0.05 * dataPegawai[a].gajiPokok;
    if (dataPegawai[a].jumlahAnak > 3)
        dataPegawai[a].tunjAnak =  3 * tPerAnak;
    else
        dataPegawai[a].tunjAnak =  dataPegawai[a].jumlahAnak * tPerAnak;
    gotoxy(kolom, baris); cout << dataPegawai[a].tunjAnak;
}

void prosesGajiKotor(int kolom, int baris){
    dataPegawai[a].gajiKotor = dataPegawai[a].gajiPokok + dataPegawai[a].tunjIstri + dataPegawai[a].tunjAnak;
    gotoxy(kolom, baris); cout << dataPegawai[a].gajiKotor;

}

void prosesPajak(int kolom, int baris){
    dataPegawai[a].pajak = 0.1 * dataPegawai[a].gajiKotor;
    gotoxy(kolom, baris); cout << dataPegawai[a].pajak;
}

void prosesBiayaJabatan(int kolom, int baris){
    dataPegawai[a].biayaJabatan = 0.1 * dataPegawai[a].gajiPokok;
    gotoxy(kolom, baris); cout << dataPegawai[a].biayaJabatan;
}

void prosesGajiBersih(int kolom, int baris){
    dataPegawai[a].gajiBersih = dataPegawai[a].gajiKotor - dataPegawai[a].pajak + dataPegawai[a].biayaJabatan;
    gotoxy(kolom, baris); cout << dataPegawai[a].gajiBersih;
}

void bubble(int kolom, int baris) {
    char info[] = "Data sudah diurutkan! (Buble Sort)";
    int jH = jumlahHuruf(info);
    sPgw tempdata;
    for(int i=1;i<a;i++) {
        for(int j=0;j<a-i;j++) {
            // lakukkan penukaran data.........
            if(strcmp(dataPegawai[j].nip, dataPegawai[j+1].nip) > 0) {
                tempdata = dataPegawai[j];
                dataPegawai[j] = dataPegawai[j+1];
                dataPegawai[j+1] = tempdata;
            }
        }
    }
    
    // mencetak keterangan (sudah diurutkan).........
    gotoxy((((gh-jH)/2)+kolom), baris); cout << info;
    getch();
}