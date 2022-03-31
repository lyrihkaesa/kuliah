#include <iostream.h>
#include <conio.h>

void main () {
    const int n = 7;
    int x[n] = {6, 8, 7, 4, 2, 5, 3};
    int temp;
    
    cout << "Nilai Awal     : \n \t\t";
    for(int a=0;a<n;a++) {
        cout << x[a] << "\t";
    }
    cout << "\n";

    for(int i = 0; i<n-1; i++) {
        cout<<"Tahab ( "<<(i+1) << " )  : \n";
        for(int j = i+1; j<n; j++) {
            cout << x[i] << " < " << x[j];
            if(x[i] > x[j]) {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
            cout << "\t\t";
            for(int a=0;a<n;a++) {
                cout << x[a]<<"\t";
            }
            cout << endl;
        }
    }
    cout << "Hasil          : \n \t\t";
    for(int a=0;a<n;a++) {
        cout << x[a] << "\t";
    }
    getch();
}