#include <iostream.h>
#include <stdio.h>
#include <conio.h>

struct spgw {
    int nip;
    char nama[25];
    int gaji;
    int lembur;
};

spgw datapgw[2];

char lagi[1];
int a = 0;

void main() {
    do {
        // clrscr();
        cout << "Input Data Pegawai\n";
        cout << "==============================\n";
        cout << "1. NIP          : "; cin >> datapgw[a].nip;
        cout << "2. Nama         : "; gets(datapgw[a].nama);
        cout << "3. Gaji         : "; cin >> datapgw[a].gaji;
        cout << "4. Lembur (Jam) : "; cin >> datapgw[a].lembur;

        cout << "\nLagi (y/t) : "; cin >> lagi;
        a++;
    } while (strcmp("y", lagi) == 0);

    int no, len = a, brs = 5, klm = 0;
    char div[100] = "--------------------------------------dst.\n";
    // Cetak Data........................
    clrscr();
    cout << "Laporan Gaji Pegawai\n";
    cout << div;
    cout << "No   NIP Nama     Gaji Lembur Total\n";
    cout << div;
    for (int pss = 0; pss < len; pss++) {
        no = pss + 1;
        gotoxy((klm+1), brs); cout << no;
        gotoxy((klm+5), brs); cout << datapgw[pss].nip;
        gotoxy((klm+15), brs); cout << datapgw[pss].nama;
        gotoxy((klm+35), brs); cout << datapgw[pss].gaji;
        gotoxy((klm+45), brs); cout << datapgw[pss].lembur;
        int total = datapgw[pss].gaji + datapgw[pss].lembur;
        gotoxy((klm+55), brs); cout << total;
        brs++;
    }
    cout << endl;
    cout << div;
    cout << "Data sudah tercetak semua\n";
    getch();
}