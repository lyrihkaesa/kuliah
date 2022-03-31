#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main ()
{
    int klm, klmi, brs, nip, anak, tanak, gaji, total;
    char nama[30], bagian[10], lagi[1];
    
    do
    {
        clrscr();
        klm = 20;
        klmi = klm + 20;
        brs = 5;
        gotoxy(klm, brs++); cout<<"Hitung Gaji Pegawai";
        gotoxy(klm, brs++); cout<<"===============================";
        gotoxy(klm, brs++); cout<<"1. NIP           :             ";
        gotoxy(klm, brs++); cout<<"2. Nama          :             ";
        gotoxy(klm, brs++); cout<<"3. Bagian        :             ";
        gotoxy(klm, brs++); cout<<"4. Jml. Anak     :             ";
        gotoxy(klm, brs++); cout<<"5. Gaji          :             ";
        gotoxy(klm, brs++); cout<<"   Tunj. Anak    :             ";
        gotoxy(klm, brs++); cout<<"                 ============ +";
        gotoxy(klm, brs++); cout<<"   Total         :             ";

        brs -= 8;
        gotoxy(klmi, brs++); cin>>nip;
        gotoxy(klmi, brs++); gets(nama);
        gotoxy(klmi, brs++); cin>>bagian;
        gotoxy(klmi, brs++); cin>>anak;
        gotoxy(klmi, brs++); cin>>gaji;

        // hitung tunjangan anak...................
        if (anak > 3)
            tanak = 3 * 100000;
        else
            tanak = anak * 100000;
        
        total = gaji + tanak;
        
        gotoxy(klmi, brs++); cout<<tanak;
        brs++;
        gotoxy(klmi, brs++); cout<<total;

        brs++;
        gotoxy(klmi, brs++); cout<<"Lagi [y/t] : "; cin>>lagi;

    } while (strcmp(lagi, "y") == 0);
}