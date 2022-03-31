#include <iostream.h>
#include <conio.h>
#include <stdio.h> // gets {untuk tipe data char spasi}

struct smhs
{
    char nim[6];
    char nama[15];
    float nilai;
};

smhs mahasiswa[5];

void main() {
    clrscr();
    for (int i = 0; i < 5; i++)
    {
        // input data...................
        cout << "\nIsi Data Mahasiswa : \n";
        cout << "masukan NIM    = "; cin >> mahasiswa[i].nim;
        cout << "masukan Nama   = "; gets(mahasiswa[i].nama);
        cout << "masukan Nilai  = "; cin >> mahasiswa[i].nilai;
    }

    // cetak data....................
    cout << "\n\nCetakData yang sudah diisikan : \n";
  cout << " No\t NIM\t Nama\t Nilai\n";
    cout << "====================================\n";
    for (int a = 0; a < 5; a++)
    {
        cout << " " << a;
        cout << "\t" << mahasiswa[a].nim;
        cout << "\t" << mahasiswa[a].nama;
        cout << "\t" << mahasiswa[a].nilai << endl;
    }

    cout << endl;
    getch();
};