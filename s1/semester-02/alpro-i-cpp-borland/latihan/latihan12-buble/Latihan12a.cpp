#include <conio.h>
#include <stdio.h>
#include <iostream.h>

struct spgw {
    char nip[5], x, nama[30], jeniskel;
    int agama, anak, gaji;
};
spgw datapgw[20];

//deklarasi variabel global............................
int a = 0; // counter data index
int brs, klm, klmi; // pengaturan baris dan kolom
char ketjk[10], ketagama[15];
int tanak, terima;

//deklarasi fungsi .....................................
// menghitung jumlah char
int jml(const char *temp) {
    int x = 0;
    for ( ;*temp != '\0'; temp++) ++x;
    return x;
}

// fungsi tampilan input
void tampilan() {
    clrscr();
    brs = 4, klm = 10, klmi = klm + 27;
    gotoxy(klm, brs++); cout << "Input Data Pegawai";
    gotoxy(klm, brs++); cout << "==============================";
    gotoxy(klm, brs++); cout << "1. NIP : ";
    gotoxy(klm, brs++); cout << "2. Nama : ";
    gotoxy(klm, brs++); cout << "3. Jenis Kelamin [L/P] : ";
    gotoxy(klm, brs++); cout << "4. Agama [1..5] : ";
    gotoxy(klm, brs++); cout << "5. Anak : ";
    gotoxy(klm, brs++); cout << "6. Gaji Pokok : ";
    gotoxy(klm, brs++); cout << " Tunjangan Anak : ";
    gotoxy(--klmi, brs++); cout << "============ +";
    gotoxy(klm, brs++); cout << " Terima Gaji : ";
}

void isinip() {
    gotoxy(klmi, brs); cout << "..... ";
    gotoxy(klmi, brs++); cin >> datapgw[a].nip;
    if (jml(datapgw[a].nip) != 5) {
        brs--;
        isinip();
    }
}

void isinama() {
    gotoxy(klmi, brs); cout << "......................... ";
    gotoxy(klmi, brs++); gets(datapgw[a].nama);
    if (jml(datapgw[a].nama) < 5) {
        brs--;
        isinama();
    }
}

void hitungjeniskel(char xjk) {
    if (xjk == 76 || xjk == 108)
        strcpy(ketjk, "Laki-laki");
    else
        strcpy(ketjk, "Perempuan");
}

void isijeniskel() {
    gotoxy(klmi, brs); cout << ". ";
    gotoxy(klmi, brs); cin >> datapgw[a].jeniskel;
    hitungjeniskel(datapgw[a].jeniskel);
    gotoxy(klmi, brs++); cout << ketjk;
}

void hitungagama(int xagama) { 
    switch (xagama) {
        case 1 : strcpy(ketagama, "Islam");
        break;
        case 2 : strcpy(ketagama, "Kristen");
        break;
        case 3 : strcpy(ketagama, "Protestan");
        break;
        case 4 : strcpy(ketagama, "Hindu");
        break;
        case 5 : strcpy(ketagama, "Budha");
        break;
        default : strcpy(ketagama, "Kepercayaan");
        break;
    }
}

void isiagama() {
    gotoxy(klmi, brs); cout << ". ";
    gotoxy(klmi, brs); cin >> datapgw[a].agama;
    hitungagama(datapgw[a].agama);
    gotoxy(klmi, brs++); cout << ketagama;
}

int hitungtanak(int xjmlanak) {
    int xhasil;
    if (xjmlanak > 3)
        xhasil = 3 * 5000;
    else
        xhasil = xjmlanak * 5000;
    return xhasil;
}

void isianak() {
    gotoxy(klmi, brs); cout << ".. ";
    gotoxy(klmi, brs++); cin >> datapgw[a].anak;
    tanak = hitungtanak(datapgw[a].anak);
}

void isigaji() {
    gotoxy(klmi, brs); cout << "........ ";
    gotoxy(klmi, brs++); cin >> datapgw[a].gaji;
}

int hitungterima(int xgaji, int xtanak) {
    int xterima = xgaji + xtanak;
    return xterima;
}

void tampilkanterima() {
    terima = hitungterima(datapgw[a].gaji, tanak);
    gotoxy(klmi, brs++); cout << tanak;
    brs++;
    gotoxy(klmi, brs++); cout << terima;
}

// fungsi cetak data.................................
void cetakjudullap() {
    clrscr();
    cout << "Laporan Gaji Pegawai\n";
    
    //12345678901234567890123456789012345678901234567890
    cout << "--------------------------------------------------\n";
    cout << " No NIP Nama Jenis Kel. Anak ";
    cout << " Tunj. Anak Terima\n";
    cout << "--------------------------------------------------\n";
}

void cetakdata() {
    int no, len = a;
    brs = 5; klm = 1;
    int totalgaji = 0;
    cetakjudullap();
    for (int pss=0; pss < len; pss++) {
        no = pss + 1;
        gotoxy((klm+1), brs); cout << no;
        gotoxy((klm+5), brs); cout << datapgw[pss].nip;
        gotoxy((klm+15), brs); cout << datapgw[pss].nama;
        if (datapgw[pss].jeniskel == 76 || datapgw[pss].jeniskel == 108)
            strcpy(ketjk, "Laki-laki");
        else 
            strcpy(ketjk, "Perempuan");
        gotoxy((klm+33), brs); cout << ketjk;
        gotoxy((klm+46), brs); cout << datapgw[pss].anak;
        tanak = hitungtanak(datapgw[pss].anak);
        gotoxy((klm+53), brs); cout << tanak;
        terima = hitungterima(datapgw[pss].gaji, tanak);
        gotoxy((klm+65), brs); cout << terima;
        totalgaji += terima;
        brs++;
    }
    cout << endl;
    cout << "--------------------------------------------------\n";
    cout << "Total Gaji Keseluruhan : Rp. " << totalgaji << endl;
    cout << "--------------------------------------------------\n";
    cout << "data sudah tercetak semua\n";
    getch();
}
// fungsi tambah data ......................................
void tambahdata() {
    char tanya;
    do {
        tampilan();
        brs = 6;
        isinip();
        isinama();
        isijeniskel();
        isiagama();
        isianak();
        isigaji();
        tampilkanterima();
        //isi data berikutnya [y]....................
        brs++;gotoxy(klm, brs); cout << "Isi Data Lagi [y/t] : ";
        cin >> tanya;
        a++;
    } while (tanya == 89 || tanya == 121);
}
// fungsi tambah data ......................................
void caridata() {
    int pssbaca = 0;
    int jmldata = a;
    int stscari = 0;
    char cari[5];
    tampilan();
    brs = 6;
    gotoxy(klmi, brs); cout << "..... ";
    gotoxy(klmi, brs++); cin >> cari;
    while (pssbaca < jmldata) {
        if (strcmp(datapgw[pssbaca].nip, cari) == 0) {
            //tampilkan..........
            //brs = 7;
            gotoxy(klmi, brs++); cout << (datapgw[pssbaca].nama);
            hitungjeniskel(datapgw[pssbaca].jeniskel);
            gotoxy(klmi, brs++); cout << ketjk;
            hitungagama(datapgw[pssbaca].agama);
            gotoxy(klmi, brs++); cout << ketagama;
            gotoxy(klmi, brs++); cout << (datapgw[pssbaca].anak);
            gotoxy(klmi, brs++); cout << (datapgw[pssbaca].gaji);
            tanak = hitungtanak(datapgw[pssbaca].anak);
            terima = hitungterima(datapgw[pssbaca].gaji, tanak);
            gotoxy(klmi, brs++); cout << tanak;
            brs++;
            gotoxy(klmi, brs++); cout << terima;
            stscari = 1;brs+= 2;
            gotoxy(klm, brs++); cout << "Kembali ke menu [Enter] ! ";
        }
        pssbaca++;
    }

    if (stscari == 0) {
        brs = 17;
        gotoxy(klm, brs++); cout << "Data tidak ditemukan !";
    }
    getch();
}

void urutbuble() {
    //proses pengurutan data........
    spgw tempdata; // penampungan sementara.....
    int n = a; // jumlah data......
    for(int i=1;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            // lakukkan penukaran data.........
            if(strcmp(datapgw[j].nip, datapgw[j+1].nip) > 0) {
                tempdata = datapgw[j];
                datapgw[j] = datapgw[j+1];
                datapgw[j+1] = tempdata;
            }
        }
    }
    
    // mencetak keterangan (sudah diurutkan).........
    brs = 15; klm = 20;
    gotoxy(klm, brs++); cout <<"Data sudah diurutkan !";
    getch();
}

void urutselection() {
    //proses pengurutan data........
    //materiberikutnya..............
    brs = 15; klm = 20;
    gotoxy(klm, brs++); cout << "Belum dibuat !";
    getch();
}

//program utama .....................................
void main() {
    int pilih;
    //isi data.......................................
    int b, k;
    do {
    // menu................
        b=4, k=20;
        clrscr();
        gotoxy(k, b++); cout << "Menu"; 
        gotoxy(k, b++); cout << "============================";
        gotoxy(k, b++); cout << "1. Tambah Data Data";
        gotoxy(k, b++); cout << "2. Cari Data";
        gotoxy(k, b++); cout << "3. Urutkan Buble Sort";
        gotoxy(k, b++); cout << "4. Urutkan Selection Sort";
        gotoxy(k, b++); cout << "5. Cetak Data";
        gotoxy(k, b++); cout << "6. Selesai";
        b++;
        gotoxy(k, b++); cout << "Pilih [1-6] : "; cin >> pilih;
        switch (pilih) {
            case 1 : tambahdata();
            break;
            case 2 : caridata();
            break;
            case 3 : urutbuble();
            break;
            case 4 : urutselection();
            break;
            case 5 : cetakdata();
            break;
        }
    } while (pilih != 6);
}
