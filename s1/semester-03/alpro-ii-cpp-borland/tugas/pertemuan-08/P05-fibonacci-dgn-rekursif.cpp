#include <iostream.h>
#include <conio.h>

int fibo(int i) {
    if(i == 0){
        return 0;
    }
    else if(i == 1){
        return 1;
    }
    else
        //fungsi rekursif
        return fibo (i - 1) + fibo (i - 2);
}

int main(){
    int bil;
    cout << "\tFungsi Rekursif Bilangan Fibonacci" << endl;
    cout << "\t======================================" << endl;
    cout << "\nMasukkan Bilangan : "; cin >> bil;
    //pemanggilan fungsi
    cout << "Fibonacci (" << bil << ") = " << fibo(bil);
    getch();
}