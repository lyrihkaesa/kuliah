#include <conio.h>
#include <iostream.h>

void tambah(int m, int n); // parameter formal
void main(){
    int a, b;
    a = 5;
    b = 9;
    cout << "nilai sebelum fungsi digunakan ";
    cout << "\n a = " << a << " b = " << b;
    tambah(a, b); // parameter aktual a dan b
    cout << "nilai sesudah fungsi digunakan ";
    cout << "\n a = " << a << " b = " << b;
    getch();
}

void tambah(int m, int n){ // parameter formal m dan n
    m+=5; // m = m + 5;
    n+=7; // n = n + 7;
    cout << "\n\n Nilai didlm fungsi tambah()";
    cout << "\nm = " << m << " n = " << n;
    getch();
}