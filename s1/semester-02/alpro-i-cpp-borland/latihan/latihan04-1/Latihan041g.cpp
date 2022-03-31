#include <iostream.h>
#include <conio.h>

void main()
{
    char kode;
    clrscr();
    cout<<"Masukkan Kode Barang [A..C] : ";cin>>kode;

    switch (kode)
    {
    case 'A':
    case 'a':
        cout<<"Alat Olah Raga";
        break;
    case 'B':
    case 'b':
        cout<<"Alat Elektronik";
        break;
    case 'C':
    case 'c':
        cout<<"Alat Masak";
        break;
    default:
        cout<<"Anda Salah Memasukan Kode";
    }
    getch();
}