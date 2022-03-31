#include <iostream.h>
#include <conio.h>
#define jumlah_huruf 100

void urutbuble(int arr[], int n) {
    //proses pengurutan data........
    int tempData;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            // lakukkan penukaran data.........
            cout << "index-" << j << ": " << arr[j] << " > " << arr[j+1] << " :" << (j+1) << "-index" << endl;
            if(arr[j] > arr[j+1]) { // jika ingin desc "<", asc ">"
                tempData = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tempData;
                for (int j=0;j<n;j++){
                    cout << arr[j] <<", ";
                }
                cout << endl;
            }
        }
        cout << "____________________________" << endl;
    }
    // mencetak keterangan (sudah diurutkan).........
    cout <<"\n Data sudah diurutkan !\n";
}

void urutbublech(char arr[][jumlah_huruf], int n) {
    char temp[jumlah_huruf];
    for (int i=0;i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            cout << "strcmp(arr[" << j << "], arr[" << (j+1) << "]): " << strcmp(arr[j], arr[j+1]) << " > 0" << endl;
            if (strcmp(arr[j], arr[j+1]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
                for (int j=0;j<n;j++){
                    cout << arr[j] <<", ";
                }
                cout << endl;
            }
        }
        cout << "____________________________" << endl;
    }
    // mencetak keterangan (sudah diurutkan).........
    cout <<"\n Data sudah diurutkan !\n";
}



void main() {
    int arr[] = {45, 7, 39, 37, 47, 65, 77, 97, 27};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n << " | " << sizeof(arr) << " || " << sizeof(arr[0]) << endl;
    cout<<"Given String is:: \n";
    for (int i = 0; i < n; i++) {
       cout << "index ke-" << i << ": " << arr[i] << "\n";
    }
    cout << endl;
    urutbuble(arr, n);
    cout << "\nBubble Sorted is As::\n";
    for (int i = 0; i < n; i++) {
      cout << i << ": " << arr[i] << endl;
    }
    cout << "\nBubble Sorted is Ds::\n";
    for (int a = n-1; a >= 0; a--) {
        cout << a << ": " << arr[a] << endl;
    }

    char arrch[][jumlah_huruf] = {"97","87","27","77","17", "67", "57", "37", "47"};
    int m = sizeof(arrch)/sizeof(arrch[0]);
    cout<<"Given String is:: \n";
    for (int i = 0; i < m; i++) {
       cout << "index ke-" << i << ": " << arrch[i] << "\n";
    }
    cout << endl;
    urutbublech(arrch, m);
    cout << "\nBubble Sorted is As::\n";
    for (int i = 0; i < m; i++) {
      cout << i << ": " << arrch[i] << endl;
    }
    cout << "\nBubble Sorted is Ds::\n";
    for (int a = m-1; a >= 0; a--) {
        cout << a << ": " << arrch[a] << endl;
    }
    getch();
}