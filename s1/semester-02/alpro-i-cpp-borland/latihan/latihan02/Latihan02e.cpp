#include <iostream>
#include <conio.h>
using namespace std;

float C, F = 0;

int main()
{
    //input..............................
    cout << "Input Celcius = ";
    cin >> C;

    //proses..............................
    F = (9.0/5*C)+32;
    
    //output..............................
    cout << "Fahrenheit = " << F << endl;

    getch();
}