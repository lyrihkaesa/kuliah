#include <iostream.h>
#include <stdio.h>
#include <conio.h>

int nip[10], gaji[10], lembur[10], a = 0, total = 0;
char nama[10][30], lagi[1];

void main()
{
    do {
        clrscr();
        cout<<"Input Data Pegawai\n";
        cout<<"=======================================\n";
        cout<<"1. NIP         : "; cin>>nip[a];
        cout<<"2. Nama        : "; gets(nama[a]);
        cout<<"3. Gaji        : "; cin>>gaji[a];
        cout<<"4. Lembur (jam): "; cin>>lembur[a];

        cout<<"\n Lagi [y/t] : "; cin>>lagi;
        a++;
    } while (strcmp("y", lagi) == 0);

    int no, len = a, brs = 3, klm = 0;
    // Cetak Data.................................
    clrscr();
    // Output Tambahan "Total"...............................................................
    cout<<"No NIP        Nama                           Gaji       Lembur      Total     \n";
    cout<<"------------------------------------------------------------------------------\n";
    for (int pss = 0; pss < len; pss++)
    {
        no = pss + 1;
        // Proses Tambahan "Total".........................
        total = gaji[pss] + lembur[pss];
        gotoxy((klm+1), brs); cout<<no;
        gotoxy((klm+4), brs); cout<<nip[pss];
        gotoxy((klm+15), brs); cout<<nama[pss];
        gotoxy((klm+46), brs); cout<<gaji[pss];
        gotoxy((klm+57), brs); cout<<lembur[pss];
        // Output Tambahan "Total".........................
        gotoxy((klm+69), brs); cout<<total;
        brs++;
    }
    cout<<"\n------------------------------------------------------------------------------\n";
    getch();
}