#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    // Deklarasi.........................
    int x1, x2, x3, x4, x5;

    // Proses..........................
    x1 = 5 + 7 * 2;
    x2 = (5 + 7) * 2;
    x3 = 5 + 7 * 2 - 1;
    x4 = (5 + 7) * (2 - 1);
    x5 = 1 + 2 - 3 * 4 % 5;

    // Keluaran..........................
    cout << "Hasil 1 (x1 = 5 + 7 * 2)         : " << x1 << endl;
    cout << "Hasil 2 (x2 = (5 + 7) * 2)       : " << x2 << endl;
    cout << "Hasil 3 (x3 = 5 + 7 * 2 - 1)     : " << x3 << endl;
    cout << "Hasil 4 (x4 = (5 + 7) * (2 - 1)) : " << x4 << endl;
    cout << "Hasil 5 (x5 = 1 + 2 - 3 * 4 % 5) : " << x5 << endl;

    // Keluaran Identitas Mahasiswa..........................
    cout << "\n================================\n";
    cout << "Program 07 dibuat oleh         : \n";
    cout << "NIM    : A12.2020.06495" << endl;
    cout << "Nama   : Kukuh Setya Arumansyah" << endl;

    getch();
}