#include <iostream.h>
#include <conio.h>

void main ()
{
    int i = 1;
    int total = 0;

    while (i <= 10)
    {
        cout<<i<<endl;
        total = total + i;
        i = i + 1;
    }

    cout<<"=============== +"<<endl;
    cout<<"Total : "<<total<<endl;
    getch();
}