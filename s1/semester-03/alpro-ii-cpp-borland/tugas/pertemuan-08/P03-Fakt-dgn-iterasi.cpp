#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main (){
    int bil, n;
    long int hasil;
    cout << "Mencari Nilai Faktorial";
    cout << "\n===========================";
    cout << "\n\nMasukkan Angka = "; cin >> n;
    hasil = 1;

    for (bil = n; bil >=1; bil--){
        //fungsi iterasi
        hasil *= bil;
    }
    cout << "\nHasil Faktorial = " << hasil << "\n";
    getch();
}