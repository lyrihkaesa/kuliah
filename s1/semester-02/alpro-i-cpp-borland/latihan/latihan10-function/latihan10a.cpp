#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

COORD coord = {0,0};

void gotoxy(int x, int y) {
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct spgw {
    char nip[5], x, nama[30], jeniskel[11];
    int agama, anak, gaji;
};

spgw datapgw[20];

//deklarasi variabel global............................
int a = 0; // counter data index
char ketagama[15];
int tanak, terima;
int brs, klm, klmi; // pengaturan baris dan kolom

//deklarasi fungsi .....................................
// membuat garis
void garis(int z, int y) {
    int x = 100, klmg = z;
    for (int i = 0; i < x; i++) {
        gotoxy(klmg++,y); cout << "=";
    }
    brs++;
}
// menghitung jumlah char
int jml(const char *temp) {
    int x = 0;
    for ( ;*temp != '\0'; temp++) ++x;
    return x;
}

// fungsi tampilan input
void tampilan() {
    // clrscr();
    system("cls");
    brs = 4, klm = 10, klmi = klm + 27;
    gotoxy(klm, brs++); cout << "Input Data Pegawai";
    garis(klm, brs);
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

void isijeniskel() {
    gotoxy(klmi, brs); cout << ". ";
    gotoxy(klmi, brs); cin >> datapgw[a].jeniskel;
    if (strcmp("l", datapgw[a].jeniskel) == 0 || strcmp("L", datapgw[a].jeniskel) == 0)
        strcpy (datapgw[a].jeniskel, "Laki-Laki");
    else if (strcmp("p", datapgw[a].jeniskel) == 0 || strcmp("P", datapgw[a].jeniskel) == 0)
        strcpy (datapgw[a].jeniskel, "Perempuan");
    else
        strcpy (datapgw[a].jeniskel, "None");
    gotoxy(klmi, brs++); cout << datapgw[a].jeniskel;
}

void isiagama() {
    gotoxy(klmi, brs); cout << ". ";
    gotoxy(klmi, brs); cin >> datapgw[a].agama;
    switch (datapgw[a].agama) {
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
    gotoxy(klmi, brs++); cout << ketagama;
}

void isianak() {
    gotoxy(klmi, brs); cout << ".. ";
    gotoxy(klmi, brs++); cin >> datapgw[a].anak;
    if (datapgw[a].anak > 3)
        tanak = 3 * 5000;
    else
        tanak = datapgw[a].anak * 5000;
}

void isigaji() {
    gotoxy(klmi, brs); cout << "........ ";
    gotoxy(klmi, brs++); cin >> datapgw[a].gaji;
}

void hitungterima() {
    terima = datapgw[a].gaji + tanak;
    gotoxy(klmi, brs++); cout << tanak;
    brs++;
    gotoxy(klmi, brs++); cout << terima;
}

// fungsi cetak data.................................
void cetakjudullap() {
    system("cls");
    cout << "Laporan Gaji Pegawai\n";
    //12345678901234567890123456789012345678901234567890
    garis(0, 2);
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
        gotoxy((klm+33), brs); cout << datapgw[pss].jeniskel;
        gotoxy((klm+46), brs); cout << datapgw[pss].anak;
        if (datapgw[pss].anak > 3)
            tanak = 3 * 5000;
        else
            tanak = datapgw[pss].anak * 5000;
        gotoxy((klm+53), brs); cout << tanak;
        terima = datapgw[pss].gaji + tanak;
        gotoxy((klm+65), brs); cout << terima;
        totalgaji += terima;
        brs++;
    }
    cout << endl;
    cout << "--------------------------------------------------\n";
    cout << "Total Gaji Keseluruhan : Rp. " << totalgaji << endl;
    cout << "--------------------------------------------------\n";
    cout << "data sudah tercetak semua\n";
}

//program utama .....................................
int main() {
    char tanya;
    //isi data.......................................
    do {
        tampilan();
        brs = 6;
        isinip();
        isinama();
        isijeniskel();
        isiagama();
        isianak();
        isigaji();
        hitungterima();
        //isi data berikutnya [y]....................
        brs++;
        gotoxy(klm, brs);cout << "Isi Data Lagi [y/t] : ";
        cin >> tanya;
        a++;
    } while (tanya == 89 || tanya == 121);
    //cetak data......................................
    gotoxy(klm, brs);cout << " ";
    gotoxy(klm, brs);cout << "Cetak Data [y/t] :      ";
    cin >> tanya;
    if (tanya == 89 || tanya == 121) {
        cetakdata();
    }
    // getch();
    system("pause");
    return 0;
}
