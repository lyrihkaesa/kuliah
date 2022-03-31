#include <iostream.h>
#include <conio.h>
// konstanta (constanta)
#define jumlahDataArray 8

void main(){
    // deklarasi variabel
    int data[jumlahDataArray];
    // proses memasukan (input) data
    for (int i = 0; i < jumlahDataArray; i++) {
        cout << "Data index ke-" << i << " : "; cin >> data[i];
    }

    // proses pengurutan data
    int temp;
    for (int i = 0; i < jumlahDataArray; i++) {
        for (int j = i + 1; j < jumlahDataArray; j++) {
            if (data[i]>data[j]) {
                temp = data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }   
    }

    // memasukan data yang akan dicari
    int inputCari;
    cout << "Masukan data yang akan dicari : "; cin >> inputCari;
    
    // proses pencarian data
    int indexAwal = 0;
    int indexAkhir = jumlahDataArray;
    int indexTengah = 0;
    while (indexAwal<=indexAkhir) {
        indexTengah = (indexAwal+indexAkhir)/2;
        cout << "Awal: " << indexAwal << ", Tengah: " << indexTengah <<", Akhir: " << indexAkhir << endl;
        if (inputCari > data[indexTengah]) {
            indexAwal = indexTengah + 1;
            cout << "iAwal = iTengah + 1:" << indexAwal;
        } else if (inputCari < data[indexTengah]) {
            indexAkhir = indexTengah - 1;
            cout << "iAkhir = iTengah - 1:" << indexAkhir;
        } else {
            indexAwal = indexAkhir + 1;
            cout << "iAwal = iAkhir + 1:" << indexAwal;
        }
        cout << endl;
    }
    if (inputCari==data[indexTengah]){
        cout << "Data ditemukan pada index ke-" << indexTengah << endl;
    } else {
        cout << "Target tidak ditemukan " << endl;
    }
getch();
}