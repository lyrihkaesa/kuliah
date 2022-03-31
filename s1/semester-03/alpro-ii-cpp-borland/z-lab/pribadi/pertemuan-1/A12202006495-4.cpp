// Borland Compailler
#include <conio.h> // getch()
#include <iostream.h> // cout, cin {untuk tipe data tanpa spasi} 
#include <stdio.h> // gets {untuk tipe data char spasi} Kukuh Setya

struct mhs
{
    char nim[7];
    char nama[15];
    float nilai;
};

mhs mahasiswa[5];

void main() {
    clrscr();
    for (int i = 0; i < 5; i++)
    {
        // input data...................
        cout << "\nIsi Data Mahasiswa : \n";
        cout << "masukan NIM    = "; gets(mahasiswa[i].nim);
        cout << "masukan Nama   = "; gets(mahasiswa[i].nama);
        cout << "masukan Nilai  = "; cin >> mahasiswa[i].nilai;
    }

    // cetak data....................
    cout << "\n\nCetakData yang sudah diisikan : \n";
    cout << " No\t NIM\t Nama\t Nilai\t NilaiHuruf\n";
    cout << "====================================\n";
    for (int a = 0; a < 5; a++)
    {
        cout << " " << (a+1);
        cout << "\t" << mahasiswa[a].nim;
        cout << "\t" << mahasiswa[a].nama;
        cout << "\t" << mahasiswa[a].nilai;
        if (mahasiswa[a].nilai < 50) {
            cout << "\tD";
        } else if (mahasiswa[a].nilai < 60) {
            cout << "\tC";
        } else if (mahasiswa[a].nilai < 80) {
            cout << "\tB";
        } else if (mahasiswa[a].nilai >= 80) {
            cout << "\tA";
        } else {
            cout << "\t???";
        };
        cout << endl;
    }

    cout << endl;
    getch();
};