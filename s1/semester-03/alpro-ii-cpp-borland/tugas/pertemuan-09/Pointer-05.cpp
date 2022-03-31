#include <iostream.h> // cout, cin, endl atau /n digunakan untuk memindahkan kursor ke garis baru.
#include <conio.h> // getch()
// #include <stdio.h> tidak terpakai karena tidak menggunakan printf dan scanf.

//fungsi dengan nama fsatu bertipedata integer
int fsatu(int *a, int *b){ //menerima variabel a dan b dari parameter aktual
    *a *= 2; //mengalikan nilai pointer a dengan dua, nilai perkaliannya dimasukkan kembali ke pointer a.
    *b *= 2; //mengalikan nilai pointer 
    return 0; //mengembalikan nilai 0 pada fungsi fsatu
}

void main(){
    int a, b; //mendeklarasikan variabel a dan b dengan tipedata integer
    cout << "Masukkan nilai a = "; cin >> a; //masukan nilai ke variabel a
    cout << "Masukkan nilai b = "; cin >> b; //masukan nilai ke variabel b

    cout << "\nSebelum melewati fungsi fsatu " << endl;
    cout << "a = " << a << endl; //menampilkan nilai variabel a
    cout << "b = " << b << endl; //menampilkan nilai variabel a

    fsatu(&a, &b); //mengirim alamat variabel a dan b ke parameter formal fungsi fsatu
    cout << "\nSetelah melewati fungsi fsatu " << endl;
    cout << "a = " << a << endl; //menampilkan nilai variabel a
    cout << "b = " << b << endl; //menampilkan nilai variabel a

    getch(); //menjeda/pause program agar program berhenti sebentar sampai salah satu tombol pada keyboard ditekan.
}