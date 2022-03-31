#include <conio.h> // getch()
#include <iostream.h>

void main(){
    char matriks[3][2][10] = {
        {"1", 3},
        {"5", 3},
        {"6", 2}
    };

    cout << "Isi Data pada indeks ke-(1,0): " << matriks[1][0] << matriks[1][1];
    getch();
}