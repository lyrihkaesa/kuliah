#include <iostream.h>
#include <conio.h>

void main ()
{
    int klm, klmi, brs, nilai1, nilai2;
    float rata2;
    char ket[5];
    char lagi[1];
    
    do
    {
        clrscr();
        klm = 20;
        klmi = klm + 15;
        brs = 5;
        gotoxy(klm, brs++); cout<<"Berhitung (Tambah)";
        gotoxy(klm, brs++); cout<<"====================";
        gotoxy(klm, brs++); cout<<"Nilai 1    :        ";
        gotoxy(klm, brs++); cout<<"Nilai 2    :        ";
        gotoxy(klm, brs++); cout<<"====================";
        gotoxy(klm, brs++); cout<<"Rata-rata  :         ";
        gotoxy(klm, brs++); cout<<"Keterangan :";

        brs -= 5;
        gotoxy(klmi, brs++); cin>>nilai1;
        gotoxy(klmi, brs++); cin>>nilai2;

        rata2 = (nilai1 + nilai2) / 2;

        if (rata2 >= 60)
            strcpy(ket,"Lulus");
        else
            strcpy(ket,"Gagal");

        brs++;
        gotoxy(klmi, brs++); cout<<rata2;
        gotoxy(klmi, brs++); cout<<ket;

        brs++;
        gotoxy(klmi, brs++); cout<<"Lagi [y/t] : "; cin>>lagi;

    } while (strcmp(lagi, "y") == 0);
    getch();
}