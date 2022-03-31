#include <iostream.h>
#include <conio.h>

int main() {
    const char data[10] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char cari;

    // menampilkan data
    cout << "PENCARIAN BINARI" << endl;
    cout << "===================" << endl;
    
    cout << "\nData : ";
    for (int i = 0; i < 6; i++) {
        cout << "'" << data[i] << "', ";
    }

    cout << endl <<  "Masukan data yang dicari : "; cin >> cari;
    int awal = 0, akhir = 6, tengah;
    while (awal <= akhir) {
        tengah = (awal+akhir)/2;
        if (cari > data[tengah]) {
            awal = tengah + 1;
        } else if (cari < data[tengah]) {
            akhir = tengah - 1;
        } else {
            awal = akhir + 1;
        }
    }
    if (cari == data[tengah]) {
        cout << "Data '" << data[tengah] << "' ditemukan index ke-" << tengah;
    }
    else {
        cout << "Target tidak ditemukan" << endl;
    }
    getch();
}