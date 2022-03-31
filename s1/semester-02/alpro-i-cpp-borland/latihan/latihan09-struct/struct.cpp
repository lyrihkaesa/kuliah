#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#define judul "Laporan Data Mahasiswa\n"
#define garis "----------------------------------------------------------------------------------------"

// Struct Mahasiswa
struct sMhs
{
    char nim[15], nama[25], jenisKelamin[11], nilaiHuruf[2], agama[13];
    float nilai1, nilai2, rata;
};

sMhs dataMhs[10];

// Deklarasi variabel kolom dan baris.
int a = 0, agama, totalA, totalB, totalC, totalD, totalE;
char lagi[2];

void main()
{
    // Tampilan Masukan
    do {
    int b1 = 3, k1 = 6;
    clrscr();
    gotoxy(k1, b1++); cout << "Masukan Data Nilai ke-" << (a + 1);
    gotoxy(k1, b1++); cout << garis;
    gotoxy(k1, b1++); cout << "1. NIM                 : ";
    gotoxy(k1, b1++); cout << "2. Nama                : ";
    gotoxy(k1, b1++); cout << "3. Nilai1              : ";
    gotoxy(k1, b1++); cout << "4. Nilai2              : ";
    gotoxy(k1, b1++); cout << "   Rata-rata           : ";
    gotoxy(k1, b1++); cout << "   Nilai Huruf         : ";
    gotoxy(k1, b1++); cout << "   Jenis Kelamin [L/P] : ";
    gotoxy(k1, b1++); cout << "   Agama [1..6]        : ";
    
    int b2 = b1 - 8, k2 = k1 + 25;
    // Masukan [Kolom +25]
    gotoxy(k2, b2++); gets(dataMhs[a].nim);
    gotoxy(k2, b2++); gets(dataMhs[a].nama);
    gotoxy(k2, b2++); cin >> dataMhs[a].nilai1;
    gotoxy(k2, b2++); cin >> dataMhs[a].nilai2;
    
    // Proses rata-rata nilai1 & nilai2
    // float rata;
    dataMhs[a].rata = (dataMhs[a].nilai1 + dataMhs[a].nilai2) / 2;
    // Proses konversi nilai ke huruf
    // char nilaiHuruf[2];
    if (dataMhs[a].rata >= 85) {
        // strcpy (nilaiHuruf, "A");
        strcpy (dataMhs[a].nilaiHuruf, "A");
        totalA++;
    }
    else if (dataMhs[a].rata >= 70) {
        // strcpy (nilaiHuruf, "B");
        strcpy (dataMhs[a].nilaiHuruf, "B");
        totalB++;
    }
    else if (dataMhs[a].rata >= 60) {
        // strcpy (nilaiHuruf, "C");
        strcpy (dataMhs[a].nilaiHuruf, "C");
        totalC++;
    }
    else if (dataMhs[a].rata >= 50) {
        // strcpy (nilaiHuruf, "D");
        strcpy (dataMhs[a].nilaiHuruf, "D");
        totalD++;
    }
    else {
        // strcpy (nilaiHuruf, "E");
        strcpy (dataMhs[a].nilaiHuruf, "E");
        totalE++;
    }
    // Keluaran rata-rata
    gotoxy(k2, b2++); cout << dataMhs[a].rata; // cout << rata;
    // Keluaran nilai huruf
    gotoxy(k2, b2++); cout << dataMhs[a].nilaiHuruf; // cout << nilaiHuruf;
    // Masukan Huruf Jenis Kelamin
    gotoxy(k2, b2); gets(dataMhs[a].jenisKelamin);
    // Mengubah Huruf Jenis Kelamin ke Kata
    if (strcmp("l", dataMhs[a].jenisKelamin) == 0 || strcmp("L", dataMhs[a].jenisKelamin) == 0)
        strcpy (dataMhs[a].jenisKelamin, "Laki-Laki");
    else if (strcmp("p", dataMhs[a].jenisKelamin) == 0 || strcmp("P", dataMhs[a].jenisKelamin) == 0)
        strcpy (dataMhs[a].jenisKelamin, "Perempuan");
    else
        strcpy (dataMhs[a].jenisKelamin, "None");
    // Keluaran Kata Jenis Kelamin
    gotoxy(k2, b2++); cout << dataMhs[a].jenisKelamin;
    // Masukan Agama
    gotoxy(k2, b2); cin >> agama;
    // Switch Angka ke huruf Agama.
    switch (agama) 
    {
    case 1: 
        strcpy(dataMhs[a].agama, "Islam");
        break;
    case 2: 
        strcpy(dataMhs[a].agama, "Protestan");
        break;
    case 3: 
        strcpy(dataMhs[a].agama, "Katolik");
        break;
    case 4: 
        strcpy(dataMhs[a].agama, "Hindu");
        break;
    case 5: 
        strcpy(dataMhs[a].agama, "Budha");
        break;
    case 6: 
        strcpy(dataMhs[a].agama, "Khonghucu");
        break;
    default: 
        strcpy(dataMhs[a].agama, "Kepercayaan");
        break;
    }
    // Keluaran Kata Agama
    gotoxy(k2, b2++); cout << dataMhs[a].agama;

    // Mengulang
    gotoxy(k1, (b1 + 1)); cout << "Lagi (y/t) : "; cin >> lagi;
    a++;
    } while (strcmp("y", lagi) == 0 || strcmp("Y", lagi) == 0);


    // ................................................
    int len = a;
    // Cetak Data
    clrscr();
    int b1 = 3, k1 = 1;
    cout << judul;
    // Mulai cetak
    cout << garis;
    gotoxy(k1, b1); cout << "No";
    k1 = k1 + 4;
    gotoxy(k1, b1); cout << "NIM";
    k1 = k1 + 15;
    gotoxy(k1, b1); cout << "Nama";
    k1 = k1 + 25;
    gotoxy(k1, b1); cout << "Rata-rata";
    k1 = k1 + 10;
    gotoxy(k1, b1); cout << "N. Huruf";
    k1 = k1 + 9;
    gotoxy(k1, b1); cout << "Jenis Kelamin";
    k1 = k1 + 14;
    gotoxy(k1, b1); cout << "Agama";
    cout << endl << garis;
    // ........................................
    int b2 = 5;
    for (int p = 0; p < len; p++) {
        int k2 = 1;
        gotoxy(k2, b2); cout << (p + 1);
        k2 = k2 + 4;
        gotoxy(k2, b2); cout << dataMhs[p].nim;
        k2 = k2 + 15;
        gotoxy(k2, b2); cout << dataMhs[p].nama;
        k2 = k2 + 25;
        gotoxy(k2, b2); cout << dataMhs[p].rata;
        k2 = k2 + 10;
        gotoxy(k2, b2); cout << dataMhs[p].nilaiHuruf;
        k2 = k2 + 9;
        gotoxy(k2, b2); cout << dataMhs[p].jenisKelamin;
        k2 = k2 + 14;
        gotoxy(k2, b2); cout << dataMhs[p].agama;
        b2++;
    }
    cout << endl << garis << "\nJumlah Nilai:" << endl;
    cout << "A = " << totalA << endl;
    cout << "B = " << totalB << endl;
    cout << "C = " << totalC << endl;
    cout << "D = " << totalD << endl;
    cout << "E = " << totalE << endl;
    cout << garis << "\nData Sudah Tercetak Semua";
    getch();
}