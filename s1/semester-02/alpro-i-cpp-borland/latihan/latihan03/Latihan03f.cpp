#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    // Deklarasi.........................
    int x = 10;
    int y = 16;

    // Masukan...........................
    cout << "Nilai x            : "; cin >> x;
    cout << "Nilai y            : "; cin >> y;
    
    // Keluaran..........................
    cout << "Hasil 1 (x & y)    : " << (x & y) << endl;
    cout << "Hasil 2 (x | y)    : " << (x | y) << endl;
    cout << "Hasil 3 (x >> 2)   : " << (x >> 2) << endl;
    cout << "Hasil 4 (y >> 2)   : " << (y >> 2) << endl;
    cout << "Hasil 5 (x << 1)   : " << (x << 1) << endl;
    cout << "Hasil 6 (y << 1)   : " << (y << 1) << endl;

    // Keluaran Identitas Mahasiswa..........................
    cout << "\n================================\n";
    cout << "Program 06 dibuat oleh         : \n";
    cout << "NIM    : A12.2020.06495" << endl;
    cout << "Nama   : Kukuh Setya Arumansyah" << endl;

    getch();
}