#include <conio.h> // getch()
#include <iostream.h> // cout, cin {untuk tipe data tanpa spasi}
#include <stdio.h> // gets {untuk tipe data char}
#define namaEntity "PT. Selalu Untung"
#define almtEntity "Jl. Untung Soropati Raya 777"
#define kotaEntity "Semarang"
#define maxHuruf 16

// struct data pelanggan
struct sPlg {
    char kodePelanggan[maxHuruf], namaPelanggan[maxHuruf], jenisBarang[maxHuruf], status[maxHuruf];
    int jumlahPembelian, hargaSatuan, jmlBayar1, jmlBayar2, jmlBayar3, jumlahBayar, biayaKirim, pajak, totalBayar;
};
sPlg dataPelanggan[100];

int a = 0;

// Fungsi Prototype (Function Prototype)
void garisH(int kolom, int baris, int kolom_awal=2);
void garisV(int kolom, int baris, int baris_awal=2);
void entityProp(int kolom, int baris);
void templateUtama();
void menuUtama(int kolom, int baris);
void pilihanMenu(int kolom, int baris);
void editData(int kolom, int baris);
void tampilanEdit(int kolom, int baris);
void tampilanHitungHarga(int kolom, int baris);
void editDataLanjutan(int kolom, int baris);
int jumlahHuruf(const char *temp);
void jumlahTitik(int kolom, int baris, int mxHuruf);
void jumlahSpasi(int kolom, int baris, int mxHuruf);
void isiKodePelanggan(int kolom, int baris, int mxHuruf);
void isiNamaPelanggan(int kolom, int baris, int mxHuruf);
void isiJenisBarang(int kolom, int baris);
void isiStatus(int kolom, int baris);
void inputData(int kolom, int baris);
void ketikInputData(int kolom, int baris);

// Deklarasi Garis Utama
int gh = 83, gv = 20;

void main() {
    int pilih;
    do {
        clrscr();
        templateUtama();
        menuUtama(20, 8);
        pilihanMenu(15, (gv-1)); cin >> pilih;
        switch (pilih) {
            case 1 : inputData(5, 8);
            break;
            case 2 : editDataLanjutan(5, 8);
            break;
            case 3 : cout << "unknow";
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
    gotoxy(kolom, baris++); cout << "Menu Utama";
    baris++;
    gotoxy(kolom, baris++); cout << "1. Input Data";
    gotoxy(kolom, baris++); cout << "2. Edit/koreksi Data";
    gotoxy(kolom, baris++); cout << "3. Tampilkan Data";
    gotoxy(kolom, baris++); cout << "4. Exit (Keluar)";
    garisH(gh, (gv-3));
}

void pilihanMenu(int kolom, int baris){
    gotoxy(kolom, baris); cout << "Pilihan anda [1,2,3,4=exit] : ";    
}

void tampilanEdit(int kolom, int baris){
    gotoxy(kolom, baris++); cout << "~ Kode Pelanggan     = ";
    gotoxy(kolom, baris++); cout << "1. Nama              = ";
    gotoxy(kolom, baris++); cout << "2. Jenis Barang [int]= ";
    gotoxy(kolom, baris++); cout << "3. Status            = ";
    gotoxy(kolom, baris++); cout << "4. Jumlah Pembelian  = ";
}

void tampilanHitungHarga(int kolom, int baris){
    gotoxy(kolom, baris++); cout << "Harga Satuan   = ";
    gotoxy(kolom, baris++); cout << "Jumlah Bayar 1 = ";
    gotoxy(kolom, baris++); cout << "Jumlah Bayar 2 = ";
    gotoxy(kolom, baris++); cout << "Jumlah Bayar 3 = ";
    gotoxy(kolom, baris++); cout << "Jumlah Bayar   = ";
    gotoxy(kolom, baris++); cout << "Biaya Kirim    = ";
    gotoxy(kolom, baris++); cout << "Pajak          = ";
    gotoxy(kolom, baris++); cout << "Total Bayar    = ";
}

// Tampilkan Template Sub
void editData(int kolom, int baris){
    clrscr();
    templateUtama();
    gotoxy(kolom, baris++); cout << "Edit Data Pembayaran Pelanggan";
    baris++;
    gotoxy(kolom, baris++); cout << "Masukan Kode Pelanggan: ";
    getch();
}

void editDataLanjutan(int kolom, int baris){
    clrscr();
    templateUtama();
    gotoxy((kolom+20), baris++); cout << "Edit/Koreksi Data Pembayaran Pelanggan";
    baris++;
    tampilanEdit(kolom, baris);
    int kolomA = kolom + maxHuruf + 1 + 25; // 2 adalah spasi antar kolom, 25 panjang huruf tertinggi di tampilanEdit() yaitu (24+1);
    tampilanHitungHarga(kolomA, baris++);
    int barisA = baris + 8;
    gotoxy(kolom, barisA); cout << "Koreksi Data [1,2,3,4,5=exit] : ";
    getch();
}

void inputData(int kolom, int baris){
    char tanya;
    do {
        clrscr();
        int barisF = baris;
        templateUtama();
        gotoxy((kolom+20), barisF++); cout << "Input Data Pembayaran Pelanggan";
        barisF = barisF+1;
        tampilanEdit(kolom, barisF);
        int kolomA = kolom + maxHuruf + 1 + 25; // 2 adalah spasi antar kolom, 25 panjang huruf tertinggi di tampilanEdit() yaitu (24+1);
        tampilanHitungHarga(kolomA, barisF);
        ketikInputData((kolom+23), barisF);
        //isi data berikutnya [y]....................
        gotoxy(kolom, (barisF+8)); cout << "Ulangi Lagi : "; cin >> tanya;
        a++;
    } while (tanya == 89 || tanya == 121);
}

void ketikInputData(int kolom, int baris){
    isiKodePelanggan(kolom, baris++, maxHuruf);
    isiNamaPelanggan(kolom, baris++, maxHuruf);
    isiJenisBarang(kolom, baris++);
    isiStatus(kolom, baris++);
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

void isiKodePelanggan(int kolom, int baris, int mxHuruf){
    jumlahTitik(kolom, baris, mxHuruf);
    gotoxy(kolom, baris); gets(dataPelanggan[a].kodePelanggan);
    if(jumlahHuruf(dataPelanggan[a].kodePelanggan) < 5) {
        isiKodePelanggan(kolom, baris, mxHuruf);
    }
}

void isiNamaPelanggan(int kolom, int baris, int mxHuruf){
    jumlahTitik(kolom, baris, mxHuruf);
    gotoxy(kolom, baris); gets(dataPelanggan[a].namaPelanggan);
    if(jumlahHuruf(dataPelanggan[a].namaPelanggan) < 5) {
        isiNamaPelanggan(kolom, baris, mxHuruf);
    }
}

void isiJenisBarang(int kolom, int baris){
    jumlahTitik(kolom, baris, 1);
    jumlahSpasi(kolom++, baris, 16);
    int input;
    gotoxy(--kolom, baris); cin >> input;
    switch (input) {
        case 1:{
            strcpy(dataPelanggan[a].jenisBarang, "Narkoba");
            dataPelanggan[a].hargaSatuan = 50000;
        }
        break;
        case 2:{
            strcpy(dataPelanggan[a].jenisBarang, "Borax");
            dataPelanggan[a].hargaSatuan = 40000;
        }
        break;
        case 3:{
            strcpy(dataPelanggan[a].jenisBarang, "Sabu-Sabu");
            dataPelanggan[a].hargaSatuan = 30000;
        }
        break;
        case 4:{
            strcpy(dataPelanggan[a].jenisBarang, "Vitamin");
            dataPelanggan[a].hargaSatuan = 20000;
        }
        break;
        case 5:{
            strcpy(dataPelanggan[a].jenisBarang, "Bodrex");
            dataPelanggan[a].hargaSatuan = 10000;
        }
        break;
        default : isiJenisBarang(kolom, baris);
        break;
    }
    gotoxy((kolom+2), baris); cout << "(" << dataPelanggan[a].jenisBarang << ")";
}

void isiStatus(int kolom, int baris){
    jumlahTitik(kolom, baris, 1);
    jumlahSpasi(kolom++, baris, 16);
    char input[2];
    gotoxy(--kolom, baris); gets(input);
    if(strcmp("N", input) == 0 || strcmp("n", input) == 0){
        strcpy(dataPelanggan[a].status,"Non Pelanggan");
    } else if(strcmp("P", input) == 0 || strcmp("p", input) == 0){
        strcpy(dataPelanggan[a].status,"Pelanggan");
    } else {
        isiStatus(kolom, baris);
    }
    gotoxy((kolom+2), baris); cout << "(" << dataPelanggan[a].status << ")";
}