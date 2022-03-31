#include <conio.h> // getch()
#include <iostream.h> // cout, cin

int a = 5, b;

void satu(){
    b = b + a;
    cout << "Nilai B yang tercetak = " << b << endl;
}

int dua(int x, int y = 10){
    // cout << "1. x = " << x << ", y = " << y << ", a =" << a << ", b = " << b << endl;
    x *= 2;
    // cout << "2. x = " << x << ", y = " << y << ", a =" << a << ", b = " << b << endl;
    // cout << "3. if(" << x << " <= " << y << " && " << (x%2) << " < 1)" << endl;
    if(x <= y && (x%2 < 1))
    // {
    // cout << "4. if(" << x << " <= " << y << " && " << (x%2) << " < 1" << endl;
    // cout << "5. x = " << x << ", y = " << y << ", a =" << a << ", b = " << b << endl;
        a = a + b + x;
    // cout << "6. x = " << x << ", y = " << y << ", a =" << a << ", b = " << b << endl;
    // }
    else
    // {
        a = b + a + y;
    // cout << "7. x = " << x << ", y = " << y << ", a =" << a << ", b = " << b << endl;
    // }
    satu();
    // cout << "8. x = " << x << ", y = " << y << ", a =" << a << ", b = " << b << endl;
    return(a+b);
}

void main(){
    for (int i = 0; i < 20; i++){
        a = 5;
        b = 0;
        cout << dua(i) << endl << "------------------" << endl;
    }
    getch();
}