#include <conio.h>
#include <iostream.h>

void main() {
    int input, jumlah = 0, total = 0;
    cout << "masukan jumlah bari = "; cin >> input;
    
    
    for(int i = 1; i <= input; i++){
        for(int j = i; j <= input; j++){
            if(j != input) {
                cout << j << " + ";
                jumlah = jumlah + j;
            }
            else {
                jumlah = jumlah + j;
                cout << j << " = " << jumlah;
                total = total + jumlah;
                jumlah = 0;
            }
        }
        cout << endl;
    }
    cout << "-----+" << endl;
    cout << total;
    getch();
}