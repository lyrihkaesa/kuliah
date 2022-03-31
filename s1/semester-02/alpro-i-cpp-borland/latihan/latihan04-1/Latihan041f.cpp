#include <iostream.h>
#include <conio.h>

void main()
{
    int hari;
    cout<<"Masukkan angka 1 sd 7 : ";cin>>hari;
    clrscr();
    for(int hari = 9; hari > 0; hari--){
    cout<<""<<endl;
    cout<<"Masukkan angka 1 sd 7 : "<<hari<<endl;
    cout<<"Nama hari             : ";
    switch (hari)
    {
        case 1:
            cout<<"Senin";
            break;
        case 2:
            cout<<"Selasa";
            break;
        case 3:
            cout<<"Rabu";
            break;
        case 4:
            cout<<"Kamis";
            break;
        case 5:
            cout<<"Jum'at";
            break;
        case 6:
            cout<<"Sabtu";
            break;
        case 7:
            cout<<"Minggu";
            break;
        default:
            cout<<"Bukan 1, 2, .., atau 7";
    }
    cout<<endl;
    }
    getch();
}