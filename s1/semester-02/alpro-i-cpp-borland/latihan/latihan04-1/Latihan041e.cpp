#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main()
{
    char nama[50];
    int nilai;
    char ket[10];

    int brs=4, klm=18, klmi=36;

    gotoxy(klm, brs++); cout << "Nilai Mahasiswa";
    gotoxy(klm, brs++); cout << "====================================";
    gotoxy(klm, brs++); cout << "1. Nama        : ";
    gotoxy(klm, brs++); cout << "2. Nilai       : ";
    gotoxy(klm, brs++); cout << "3. Nilai Huruf : ";
    gotoxy(klm, brs++); cout << "4. Keterangan  : ";

    brs=6, klm=36;
    gotoxy(klm, brs++); gets(nama);
    gotoxy(klm, brs++); cin >>nilai;

    if(nilai>=85)
        strcpy(ket,"A");
    else if(nilai>=70)
        strcpy(ket,"B");
    else if(nilai>=60)
        strcpy(ket,"C");
    else if(nilai>=50)
        strcpy(ket,"D");
    else
        strcpy(ket,"E");
    //cetak nilai huruf...............................
    gotoxy(klmi, brs++); cout << ket;

    if(nilai>=60)
        strcpy(ket,"Lulus");
    else
        strcpy(ket,"Gagal");
    //cetak keterangan nilai..........................
    gotoxy(klmi, brs++);cout<<ket;

    getch();
}