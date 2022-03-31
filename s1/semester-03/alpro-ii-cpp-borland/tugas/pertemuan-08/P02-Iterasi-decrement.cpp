#include <iostream.h> // cout, cin
#include <conio.h> // getch()
#include <stdio.h> // unknown fungtion

void main (){
    int n, k;
    cout << "Masukkan sebuah angka : "; cin >> k;

    for (n = k; n >= 1; n--){
        cout << "angka = " << n << endl;
    }
    getch();
}