#include <iostream.h>
#include <conio.h>
#include <dos.h>

char nama[] = "Semarang Kota Atlas";
int klm = 1, brs;

void main ()
{
    cout<<nama;
    int len = sizeof(nama)/sizeof(nama[0]);

    for (int pss=0; pss < len; pss++)
    {
        brs = 0;
        do
        {
            gotoxy(klm, brs); cout << " ";
            brs += 1;
            gotoxy(klm, brs); cout << nama[pss];
            sleep(1);
        } while (brs < 20);
        klm += 1;        
    }
    getch();
}