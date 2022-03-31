#include <iostream.h>
#include <conio.h>
#include <iomanip.h> // setw() | set width | atur lebar kolom pada baris.

int const n = 10;
int data[n] = {5, 8, 80, 3, 6, 8, 1, 10, 15, 75};

void tukar(int a, int b) {
    int temp;
    temp = data[b];
    data[b] = data[a];
    data[a] = temp;
}

void bubbleSort() {
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(data[j] > data[j+1]) {
                tukar(j, j+1);
            }
        }
    }
}

void cetakData() {
     for (int i = 0; i < n; i++) {
        cout << setw(5) << data[i];
    }
}

void main() {
    cout << "===PROGRAM BUBBLE SORT===" << endl;
    // tampilkan data awal....................
    cout << "\n\nCetak data awal : " << endl;
    cetakData();
    
    // proses pengurutan data.................
    bubbleSort();

    // tampilkan data setelah diurutkan.......
    cout << "\n\nData setelah di urutkan (sort) : " << endl;
    cetakData();
    cout << "\n\nSorting Selesai";
    getch();    
}