#include <iostream.h> // cout, /n digunakan untuk memindahkan kursor ke garis baru.
#include <conio.h> // getch()
// #include <stdio.h> tidak terpakai karena tidak menggunakan printf.

void main(){
    int nilai1 = 5, nilai2 = 15; //mendeklarasikan variabel nilai1 yang berisi 5 dan variabel nilai2 yang berisi 15
    int *p1, *p2; //mendeklarasikan variabel pointer p1 dan p2

    p1 = &nilai1; //variabel p1 diisi dengan alamat nilai1
    p2 = &nilai2; //variabel p2 diisi dengan alamat nilai2

    *p1 = 10; //variabel pointer p1 diisi dengan 10
    *p2 = *p1; //variabel pointer p2 diisi dengan variabel pointer p1

    p1 = p2; //variabel p1 diisi dengan variabel p2
    p2 = p1; //variabel p2 diisi dengan variabel p1

    cout << "nilai1 = " << nilai1 << '\n'; //menampilkan nilai dari variabel nilai1
    cout << "nilai2 = " << nilai2 << '\n'; //menampilkan nilai dari variabel nilai2
    getch(); //menjeda/pause program agar program berhenti sebentar sampai salah satu tombol pada keyboard ditekan.
}