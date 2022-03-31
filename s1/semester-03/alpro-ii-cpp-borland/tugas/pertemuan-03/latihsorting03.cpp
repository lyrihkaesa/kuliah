#include <iostream.h>
#include <conio.h> // clrscr(), getche(), getch()
#include <stdio.h> // gets(), strchr()
#include <iomanip.h> // setw() | set width | atur lebar kolom pada baris.
// sort record insertion...................

int const n = 10;
int jml;

struct  smhs {
    char nama[10];
    int nilai;
};

smhs datamhs[n];

void tukar(int a, int b) {
    smhs temp;
    temp = datamhs[b];
    datamhs[b] = datamhs[a];
    datamhs[a] = temp;
}

void insertionSort() {
    int j;
    for (int i = 1; i < jml; i++) {
        j = i;
        while (j > 0 && datamhs[j-1].nilai > datamhs[j].nilai) {
            tukar(j-1, j);
            j--; // artinya sama dengan j = j - 1.
        }   
    }
}

void cetakData() {
     for (int i = 0; i < jml; i++) {
        cout << setw(5) << (i+1);
        cout << setw(15) << datamhs[i].nama;
        cout << setw(5) << datamhs[i].nilai << endl;
    }
}

void main() {
    cout << "===PROGRAM INSERTION SORT===" << endl;
    // tampilkan data awal....................
    jml = 0;
    while(jml<n) {
        cout << "\n\nmasukkan data index [" << jml << "] : \n";
        cout << "Nama   : "; gets(datamhs[jml].nama);
        cout << "Nilai  : "; cin >> datamhs[jml].nilai;
        jml++;
        cout << "\nTambah data lagi [y/t] : ";
        char lagi = getche();
        if(strchr("Tt",lagi) != NULL) {
            break;
        }
    }

    // tampilkan data.........................
    clrscr();
    cout << "\n\nData awal : " << endl;
    cetakData();

    // proses pengurutan data.................
    insertionSort();

    // tampilkan data setelah diurutkan.......
    cout << "\n\nData setelah di urutkan (sort) : " << endl;
    cetakData();
    cout << "\n\nSorting Selesai";
    getch();    
}