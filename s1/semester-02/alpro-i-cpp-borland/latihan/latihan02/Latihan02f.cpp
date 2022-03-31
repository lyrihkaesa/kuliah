#include <iostream>
#include <conio.h>
using namespace std;

float D, R, Luas;
float pi (3.14);

int main()
{
    //input..............................
    cout << "Input Diameter = ";
    cin >> D;

    //proses..............................
    R = D/2;
    Luas = pi*R*R;
    
    //output..............................
    cout << "Luas Lingkaran = " << Luas << endl;

    getch();
}