#include <iostream.h>
#include <conio.h>

void main ()
{
    int i = 1;
    int nilai, total = 0;

    cout<<"Masukkan 5 Buah Nilai\n";
    cout<<"=====================\n";
    do
    {
        cout<<"Nilai ke-"<<i<<" = "; cin>>nilai;
        total = total + nilai;
        i++;
    } while (i <= 5);
    
    cout<<"===================== +"<<endl;
    cout<<"Total : "<<total<<endl;
    cout<<""<<endl;
    getch();
}