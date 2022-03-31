#include <conio.h>
#include <iostream.h>

void main() {
    int arr[] = {10, 14, 19, 26, 27, 31, 14, 35, 42, 44};
    int key, loc;

    cout << "Array yang dimasukan adalah ";
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }

    cout << "\nMasukan kunci untuk mencari (searched): "; cin >> key;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            loc = i+1;
            cout << "Kunci ditemukan pada posisi: " << loc << " di dalam array\n";
        }
        if(loc == 0) {
            cout << "Kunci tidak ditemukan didalam array";
        }
    }
    getch();

}