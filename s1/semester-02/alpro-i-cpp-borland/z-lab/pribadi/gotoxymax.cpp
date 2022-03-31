#include <conio.h> // getch()
#include <iostream.h> // cout, cin


void main(){
    for (int i = 0; i < 200; i++){
        int a = i;
        gotoxy(i, 3); cout <<i;
    }
    getch();
    
}