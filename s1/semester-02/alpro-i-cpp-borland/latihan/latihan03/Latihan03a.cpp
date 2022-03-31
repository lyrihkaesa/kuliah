#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    // Deklarasi.........................
    int x = 9;
    int y (3);
    int hasil;

    // Keluaran..........................
    cout << "Nilai x            : " << x << endl;
    cout << "Nilai y            : " << y << endl;

    // Proses..............................
    hasil = x + y;

    // Keluaran..........................
    cout << "Hasil 1 (x + y)    : " << (x + y) << endl;
    cout << "Hasil 2 (hasil)    : " << hasil << endl;

    // Keluaran Identitas Mahasiswa..........................
    cout << "\n================================\n";
    cout << "Program 01 dibuat oleh         : \n";
    cout << "NIM    : A12.2020.06495" << endl;
    cout << "Nama   : Kukuh Setya Arumansyah" << endl;

    getch();
}