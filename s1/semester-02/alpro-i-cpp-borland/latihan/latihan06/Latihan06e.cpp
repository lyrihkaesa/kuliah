#include <iostream.h>
#include <stdio.h>
#include <conio.h>

int nip[10], gaji[10], lembur[10], a = 0;
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
    // cetak data.................................
    clrscr();
    cout<<"No NIP        Nama                           Gaji       Lembur     \n";
    cout<<"-------------------------------------------------------------------\n";
    for (int pss = 0; pss < len; pss++)
    {
        no = pss + 1;
        gotoxy((klm+1), brs); cout<<no;
        gotoxy((klm+4), brs); cout<<nip[pss];
        gotoxy((klm+15), brs); cout<<nama[pss];
        gotoxy((klm+46), brs); cout<<gaji[pss];
        gotoxy((klm+57), brs); cout<<lembur[pss];
        brs++;
    }
    cout<<"\n-------------------------------------------------------------------\n";
    getch();
}