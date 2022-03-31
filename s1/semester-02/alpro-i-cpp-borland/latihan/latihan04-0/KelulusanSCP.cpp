#include <iostream.h>
#include <conio.h>

void main()
{
    // Deklarasi
    int ujian1, ujian2, rt;
    char ket[50] = "";

    // Masukan
    cout<<"Masukkan nilai Ujian 1: "; cin>>ujian1;
    cout<<"Masukkan nilai Ujian 2: "; cin>>ujian2;
    
    // Proses
    rt = (ujian1+ujian2)/2;

    // Struktur Kontrol Keputusan
    if(ujian1 > 100) {
        strcpy(ket,"Nilai ujian 1 tidak boleh lebih dari 100");
    }
    else if(ujian1 < 0) {
        strcpy(ket,"Nilai ujian 1 tidak boleh kurang dari 0");
    }
	else if(ujian2 > 100) {
        strcpy(ket,"Nilai ujian 2 tidak boleh lebih dari 100");
    }
    else if(ujian2 < 0) {
        strcpy(ket,"Nilai ujian 2 tidak boleh kurang dari 0");
    }
    else if(ujian1 >= 85) {
        if(ujian2 >= 85) {
            strcpy(ket,"Lulus Seleksi Pegawai karena kedua nilai minimal 85");
        }
        else if(rt >= 90) {
            strcpy(ket,"Lulus Seleksi Pegawai dengan rata-rata nilai >= 90");
        }
        else {
            strcpy(ket,"Tidak memenuhi syarat karena nilai ujian 2 kurang dari 80 dan rata-rata tidak 90");
        }
    }
    else if(ujian1 >= 80) {
        if(rt >= 90) {
            strcpy(ket,"Lulus Seleksi Pegawai dengan nilai rata-rata >= 90");
        }
        else {
            strcpy(ket,"Tidak memenuhi syarat nilai rata-rata 90");
        }
    }
    else {
        strcpy(ket,"Tidak memenuhi syarat karena nilai ujian 1 kurang dari 80 dan rata-rata tidak 90");
    }

    // Keluaran
    cout<<"Keterangan: "<<ket<<endl;
    cout<<"Rata-rata: "<<rt<<endl;

    getch();
}