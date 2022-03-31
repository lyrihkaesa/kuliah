#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    // Deklarasi.........................
    int a, b;
    int hasil;

    // Keluaran..........................
    cout << "Nilai a            : "; cin >> a;
    cout << "Nilai b            : "; cin >> b;

    // Proses..............................
    hasil = a++;

    // Keluaran..........................
    cout << "Hasil 1 (a % b)    : " << (a % b) << endl;
    cout << "Hasil 2 (hasil)    : " << hasil << endl;
    cout << "Hasil 3 ( a )      : " << a << endl;

    // Proses..............................
    hasil = ++b;
    cout << "Hasil 4 (hasil)    : " << hasil << endl;

    // Keluaran Identitas Mahasiswa..........................
    cout << "\n================================\n";
    cout << "Program 02 dibuat oleh         : \n";
    cout << "NIM    : A12.2020.06495" << endl;
    cout << "Nama   : Kukuh Setya Arumansyah" << endl;

    getch();
}