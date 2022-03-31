#include <iostream.h>
#include <conio.h> // hanya buat getch()
#define garis "==========================================="
int main(){
    int ARnilai[5]; 
    int tampung = 0;
    // a)....
    int rata2;

    cout << garis << endl;
    cout << "= Program Menjumlahkan Semua Elemen Array =" << endl;
    cout << garis << endl;

    // Mengisi nilai ke dalam elemen array
    cout << endl << "== Isi Array ==" << endl;
    for(int i=0; i<5; i++){
        cout << "Isi index ke [" << i <<"] = "; cin >> ARnilai[i];
        // b)....
        tampung = tampung + ARnilai[i];
    }

    // c)....
    rata2 = tampung/5;

    cout << endl << "Hasil Penjumlahan semua elemen Array: " << tampung;
    cout << endl << "Nilai Rata-Rata                     : " << rata2;
    getch();
    return 0;
}