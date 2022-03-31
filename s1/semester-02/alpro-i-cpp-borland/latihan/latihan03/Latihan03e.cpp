#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    // Deklarasi................................................
    int a, b;

    // Masukan..................................................
    cout << "Nilai a                : "; cin >> a;
    cout << "Nilai b                : "; cin >> b;
    cout << "Hasil 1 (a>10 && b<20) : " << (a>10 && b<20) << endl;
    cout << "Hasil 2 (a==b && b>20) : " << (a==b && b>20) << endl;
    cout << "Hasil 3 (a>=b && b>20) : " << (a>=b && b>20) << endl;
    cout << "Hasil 4 (a>10 || b<20) : " << (a>10 || b<20) << endl;
    cout << "Hasil 5 (a==b || b>20) : " << (a==b || b>20) << endl;
    cout << "Hasil 6 (a>=b || b>20) : " << (a>=b || b>20) << endl;
    cout << "Hasil 7 (a!=10 || b>20): " << (a!=10 || b>20) << endl;

    // Keluaran Identitas Mahasiswa.............................
    cout << "\n================================\n";
    cout << "Program 05 dibuat oleh         : \n";
    cout << "NIM    : A12.2020.06495" << endl;
    cout << "Nama   : Kukuh Setya Arumansyah" << endl;

    getch();
}