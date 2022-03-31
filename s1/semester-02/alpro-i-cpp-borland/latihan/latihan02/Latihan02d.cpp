#include <iostream>
#include <conio.h>
using namespace std;

float luas;
int jari_jari;
float pi = 3.14;

int main()
{
    //input..............................
    cout << "Input jari-jari = ";
    cin >> jari_jari;

    //proses..............................
    luas = pi * jari_jari * jari_jari;
    
    //output..............................
    cout << "Luas = " << luas << endl;

    getch();
}