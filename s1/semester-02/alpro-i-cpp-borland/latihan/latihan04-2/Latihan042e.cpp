#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main ()
{
    int klm, klmi, brs, nip, anak, tanak, gaji, total, terima, pajak;
    char nama[30], bagian[10], lagi[1], jenis_kelamin[15];
    
    do
    {
        clrscr();
        klm = 20;
        klmi = klm + 20;
        brs = 5;
        gotoxy(klm, brs++); cout<<"Hitung Gaji Pegawai";
        gotoxy(klm, brs++); cout<<"==========================================";
        gotoxy(klm, brs++); cout<<"1. NIP            :                       ";
        gotoxy(klm, brs++); cout<<"2. Nama           :                       ";
        // Tambahan Jenis Kelamin..............................................
        gotoxy(klm, brs++); cout<<"3. Jenis Kelamin  :                       ";
        gotoxy(klm, brs++); cout<<"4. Bagian         :                       ";
        gotoxy(klm, brs++); cout<<"5. Jml. Anak      :                       ";
        gotoxy(klm, brs++); cout<<"6. Gaji           :                       ";
        gotoxy(klm, brs++); cout<<"   Tunj. Anak     :                       ";
        gotoxy(klm, brs++); cout<<"                  ======================== +";
        gotoxy(klm, brs++); cout<<"   Total          :                       ";
        // Tambahan Pajak & Terima.............................................
        gotoxy(klm, brs++); cout<<"   Pajak          :                       ";
        gotoxy(klm, brs++); cout<<"                  ======================== -";
        gotoxy(klm, brs++); cout<<"   Terima         :                       ";

        brs -= 12;
        gotoxy(klmi, brs++); cin>>nip;
        gotoxy(klmi, brs++); gets(nama);
        gotoxy(klmi, brs++); gets(jenis_kelamin);
        gotoxy(klmi, brs++); gets(bagian);
        gotoxy(klmi, brs++); cin>>anak;
        gotoxy(klmi, brs++); cin>>gaji;

        // Hitung tunjangan anak...................
        if (anak > 3)
            tanak = 3 * 100000;
        else
            tanak = anak * 100000;
        
        total = gaji + tanak;

        // Hitung pajak & terima...................
        if (total > 1000000)
            pajak = total * 0.05;
        else
            pajak = 0;
        
        terima = total - pajak;
        
        gotoxy(klmi, brs++); cout<<tanak;
        brs++;
        gotoxy(klmi, brs++); cout<<total;
        // Keluaran pajak & terima.................
        gotoxy(klmi, brs++); cout<<pajak;
        brs++;
        gotoxy(klmi, brs++); cout<<terima;

        brs++;
        gotoxy(klmi, brs++); cout<<"Lagi [y/t] : "; cin>>lagi;

    } while (strcmp(lagi, "y") == 0);
}