#include <conio.h>
#include <iostream.h>

// Fungsi Prototype (Function Prototype)
void garisH(int kolom, int baris, int kolom_awal=1);
void garisV(int kolom, int baris, int baris_awal=1);

struct contoh
{
    int NPP, Gpkok, Tkeluarga, Tjabatan, GjKotor, Pajak, GBersih;
    char Nama[16];
};
contoh lol[50];

void main() {
    garisH(20, 20);
    garisV(10, 10);
// char tanya;
// int a = 0;
// do {
//    cout << a << endl;
//         //isi data berikutnya [y]....................
//         cout << "Isi Data Lagi [y/t] : ";
//         cin >> tanya;
//     a++;
// } while (tanya == 89 || tanya == 121);
getch();
}

// Definisi Function Prototype
void garisH(int kolom, int baris, int kolom_awal){
    for(int i=kolom_awal;i<kolom;i++){
        gotoxy(i, baris); cout << "_";
    }
}
void garisV(int kolom, int baris, int baris_awal){
    for(int i=baris_awal;i<baris;i++){
        gotoxy(kolom, i); cout << "|";
    }
}