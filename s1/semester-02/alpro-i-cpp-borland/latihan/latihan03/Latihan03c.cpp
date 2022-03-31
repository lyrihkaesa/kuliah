#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int a;
    cout << "Nilai a            : "; cin >> a;

    a = a + 1;
    cout << "Hasil 1 (a = a + 1): " << a << endl;

    a++;
    cout << "Hasil 2 (a++)      : " << a << endl;

    a += 1;
    cout << "Hasil 3 (a += 1)   : " << a << endl;
    
    cout << "\n================================\n";
    cout << "Program 03 dibuat oleh         : \n";
    cout << "NIM    : A12.2020.06495" << endl;
    cout << "Nama   : Kukuh Setya Arumansyah" << endl;

    getch();
}