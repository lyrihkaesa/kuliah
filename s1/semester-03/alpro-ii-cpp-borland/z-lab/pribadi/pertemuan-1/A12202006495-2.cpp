#include <iostream.h>
#include <conio.h>

struct smhs
{
    char nim[5];
    char nama[15];
    float nilai;
};

smhs mahasiswa;

void main() {
    clrscr();
    // input data...................
    cout << "\nIsi Data Mahasiswa : \n";
    cout << "masukan NIM    = "; cin >> mahasiswa.nim;
    cout << "masukan Nama   = "; cin >> mahasiswa.nama;
    cout << "masukan Nilai  = "; cin >> mahasiswa.nilai;

    // cetak data....................
    cout << "\n\nCetakData yang sudah diisikan : \n";
    cout << "NIM            = " << mahasiswa.nim << endl;
    cout << "Nama           = " << mahasiswa.nama << endl;
    cout << "Nilai          = " << mahasiswa.nilai << endl;

    cout << endl;
    getch();
};