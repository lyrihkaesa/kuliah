#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int faktorial(int n) {
    if (n == 0 || n == 1){
        cout << n;
        return 1;
    }
    else {
        cout << n << "*";
        //fungsi rekursif disni
        return n * faktorial (n - 1);
    }
}

void main() {
    int n, hasil;
    cout << "Masukkan suatu bilangan bulat : "; cin >> n;
    hasil = faktorial(n);
    cout << "\nBilangan yang akan dihitung : " << n;
    cout << "\nHasil faktorial : " << hasil;
    getch();
}