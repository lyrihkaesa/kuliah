#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

void main()
{
    int nilai[] = { 20, 40, 93, 99, 11, 45, 42, 45, 
                    1, 2, 5, 6, 8, 3, 7, 9, 3, 45,
                    90, 50, 44, 55, 66, 88, 90, 45 };

    int len;
    len = sizeof(nilai)/sizeof(nilai[0]);

    cout<<"Nilai Genap "<<endl;
    cout<<"============"<<endl;
    for (int pss=0; pss < len; pss++)
    {
        if (nilai[pss] % 2 == 0)
            cout<<setw(7)<<nilai[pss]<<endl;
    }
    getch();
}