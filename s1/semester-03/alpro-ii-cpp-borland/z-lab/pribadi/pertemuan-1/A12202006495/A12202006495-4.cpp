#include <conio.h> // getch()
#include <iostream.h> // cout, cin {untuk tipe data tanpa spasi}
#include <stdio.h> // gets {untuk tipe data char}

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
    cout << " No     NIM     Nama    Nilai   NilaiHuruf\n";
    cout << "====================================\n";
    for (int a = 0; a < 5; a++)
    {
        cout << " " << (a+1);
        cout << "\t" << mahasiswa[a].nim;
        cout << "\t" << mahasiswa[a].nama;
        cout << "\t" << mahasiswa[a].nilai;
        if (mahasiswa[a].nilai >= 80) {
            cout << "\tA";
        } else if (mahasiswa[a].nilai < 80 && mahasiswa[a].nilai >=60) {
            cout << "\tB";
        } else if (mahasiswa[a].nilai < 60){
            cout << "\tC";
        } else {
            cout << "\t?";
        }
        cout << endl;
        
    }

    cout << endl;
    getch();
};