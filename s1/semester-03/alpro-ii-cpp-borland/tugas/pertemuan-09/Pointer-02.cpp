#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main(){
    int nilai1, nilai2;
    int *p1, *p2;

    nilai1 = 10;
    p1 = &nilai1;

    nilai2 = 20;
    p2 = &nilai2;

    cout << "Nilai1 = " << nilai1 << " disimpan di " << p1 << endl;
    cout << "Nilai2 = " << nilai2 << " disimpan di " << p2 << endl;
    cout << endl;
    cout << "Nilai yg ditunjuk p1 = " << *p1 << endl;
    cout << "Nilai yg ditunjuk p2 = " << *p2 << endl;
    cout << endl;
    cout << "Alamat : " << p1 << " isinya = " << *p1 << endl;
    cout << "Alamat : " << p2 << " isinya = " << *p2 << endl;

    getch();
}