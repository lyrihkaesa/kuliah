#include <iostream.h>
#include <conio.h>
#define jumlahDataArray 4

void main() {
    // deklarasi variabel
    int a[jumlahDataArray];

    for (int i = 0; i < jumlahDataArray; i++)
    {
        cout << "Data index ke-" << i << " : "; cin >> a[i];
    };

    // memasukan data yang ingin dicari
    int inputCari;
    cout << "Masukan data yang akan dicari : "; cin >> inputCari;

    // proses mencari data
    int j = 0;
    int temp[jumlahDataArray];
    for (int i = 0; i < jumlahDataArray; i++){
        if(a[i]==inputCari) {
            temp[j] = i;
            j++;
        }
    }
    // jika ditemukan
    if(j>0) {
        cout << "Data " << inputCari << " yang dicari ada " << j << " buah" << endl;
        cout << "Data tersebut terdapat dalam index ke : {";
        for (int i = 0; i < j; i++) {
            cout << temp[i] << ", ";
        }
        cout << "}" << endl;
    // jika tidak ditemukan
    } else {
        cout << "Data tidak ditemukan dalam array" << endl;
    }
    getch();
}