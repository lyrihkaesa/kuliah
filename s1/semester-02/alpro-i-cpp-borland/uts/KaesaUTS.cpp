#include <iostream.h>
#include <stdio.h>
#include <conio.h>

char Nomor_Pelanggan[10][10], Nama_Pelanggan[10][30], Lagi[1], Keterangan_Kriteria[10][20];
int Kriteria[10], a = 1;
double Tarif_Dasar[10], Jumlah_Pemakaian[10], Tarif_Pemakaian[10], Jumlah_Bayar[10], Grand_Total_Jumlah_Pemakaian, Grand_Total_Tarif_Pemakaian, Grand_Total_Jumlah_Bayar;

void main()
{
    // Masukan Data.........................................
    int baris_a = 2, kolom_a = 10;
    do {
        clrscr();
        gotoxy((kolom_a+1), baris_a); cout<<"TAGIHAN PERUSAHAAN AIR MINUM";
        gotoxy(kolom_a, (baris_a+1)); cout<<"------------------------------";
        gotoxy(kolom_a, (baris_a+3)); cout<<"Data ke- : "<<a<<endl;
        gotoxy(kolom_a, (baris_a+4)); cout<<"1. Nomor Pelanggan       : "; gets(Nomor_Pelanggan[a]);
        gotoxy(kolom_a, (baris_a+5)); cout<<"2. Nama Pelanggan        : "; gets(Nama_Pelanggan[a]);
        do
        {   
            gotoxy((kolom_a+27), (baris_a+6)); cout<<"        ";
            gotoxy(kolom_a, (baris_a+6)); cout<<"3. Kriteria [1..5]       : "; cin>>Kriteria[a];
            if (Kriteria[a] == 1) {
                gotoxy((kolom_a+35), (baris_a+6)); cout<<"                               ";
                strcpy (Keterangan_Kriteria[a],"Rumah Tangga");
                Tarif_Dasar[a] = 4000;
            }
            else if (Kriteria[a] == 2) {
                gotoxy((kolom_a+35), (baris_a+6)); cout<<"                               ";
                strcpy (Keterangan_Kriteria[a],"Industri");
                Tarif_Dasar[a] = 15000;
            }
            else if (Kriteria[a] == 3) {
                gotoxy((kolom_a+35), (baris_a+6)); cout<<"                               ";
                strcpy (Keterangan_Kriteria[a],"Instansi Pemerintah");
                Tarif_Dasar[a] = 1000;
            }
            else if (Kriteria[a] == 4) {
                gotoxy((kolom_a+35), (baris_a+6)); cout<<"                               ";
                strcpy (Keterangan_Kriteria[a],"Lembaga Sosial");
                Tarif_Dasar[a] = 500;
            }
            else if (Kriteria[a] == 5) {
                gotoxy((kolom_a+35), (baris_a+6)); cout<<"                               ";
                strcpy (Keterangan_Kriteria[a],"Warung Air");
                Tarif_Dasar[a] = 10000;
            }
            else {
                // strcpy (Keterangan_Kriteria[a],"Salah Memasukan Kriteria");
                gotoxy((kolom_a+35), (baris_a+6)); cout<<"Ket : Salah memasukan Kriteria";
            }
        gotoxy((kolom_a+35), (baris_a+6)); cout<<"Ket : "<<Keterangan_Kriteria[a];
        } while (Kriteria[a] > 5 || Kriteria[a] < 1);
        gotoxy(kolom_a, (baris_a+7)); cout<<"4. Tarif Dasar           : "<<Tarif_Dasar[a];
        gotoxy(kolom_a, (baris_a+8)); cout<<"5. Jumlah Pemakaian      : "; cin>>Jumlah_Pemakaian[a]; 
        gotoxy((kolom_a+30), (baris_a+8)); cout<<" M3";
        if (Jumlah_Pemakaian[a] <= 60) {
            Tarif_Pemakaian[a] = Jumlah_Pemakaian[a] * 200;
        }
        else if (Jumlah_Pemakaian[a] > 60 && Jumlah_Pemakaian[a] <= 100) {
            Tarif_Pemakaian[a] = Jumlah_Pemakaian[a] * 215;
        }
        else if (Jumlah_Pemakaian[a] > 100) {
            Tarif_Pemakaian[a] = Jumlah_Pemakaian[a] * 225;
        }
        gotoxy(kolom_a, (baris_a+9)); cout<<"6. Tarif Pemakaian       : "; cout<<Tarif_Pemakaian[a];
        Jumlah_Bayar[a] = Tarif_Dasar[a] + Tarif_Pemakaian[a];
        gotoxy(kolom_a, (baris_a+10)); cout<<"7. Jumlah Bayar          : "; cout<<Jumlah_Bayar[a];

        gotoxy((kolom_a+10), (baris_a+12));cout<<"Input Data Lagi [y/t] : "; cin>>Lagi;
        a++;
    } while (strcmp("y", Lagi) == 0 || strcmp("Y", Lagi) == 0);

    int kaesa = a, baris = 3, kolom = 0;
    // Cetak Data.................................
    clrscr();
    char divinder[200] = "\n-------------------------------------------------------------------------------------------------------------";
    gotoxy((kolom+15), baris); cout<<"DAFTAR TAGIHAN PERUSAHAAN AIR MINUM | Kukuh Setya Arumansyah | A12.2020.06495\n";
    gotoxy(kolom, (baris+3)); cout<<divinder<<endl;
    gotoxy(kolom, (baris+4)); cout<<"No No.plg     Nama Pelanggan                 Kriteria            T.Dasar     Jml.Pakai  Trf.Pakai  Bayar     ";
    gotoxy(kolom, (baris+6)); cout<<divinder;
    baris = baris + 5;
    for (int ksa = 1; ksa < kaesa; ksa++)
    {
        gotoxy((kolom+1), baris); cout<<ksa;
        gotoxy((kolom+4), baris); cout<<Nomor_Pelanggan[ksa];
        gotoxy((kolom+15), baris); cout<<Nama_Pelanggan[ksa];
        gotoxy((kolom+46), baris); cout<<Keterangan_Kriteria[ksa];
        gotoxy((kolom+67), baris); cout<<Tarif_Dasar[ksa];
        gotoxy((kolom+78), baris); cout<<Jumlah_Pemakaian[ksa];
        gotoxy((kolom+89), baris); cout<<Tarif_Pemakaian[ksa];
        gotoxy((kolom+100), baris); cout<<Jumlah_Bayar[ksa];
        Grand_Total_Jumlah_Pemakaian = Grand_Total_Jumlah_Pemakaian + Jumlah_Pemakaian[ksa];
        Grand_Total_Tarif_Pemakaian = Grand_Total_Tarif_Pemakaian + Tarif_Pemakaian[ksa];
        Grand_Total_Jumlah_Bayar = Grand_Total_Jumlah_Bayar + Jumlah_Bayar[ksa];
        baris++;
    }
    gotoxy(kolom, baris); cout<<divinder;
    kolom = kolom + 60;
    baris++;
    gotoxy(kolom, baris); cout<<"Grand Total";
    gotoxy((kolom+18), baris); cout<<Grand_Total_Jumlah_Pemakaian;
    gotoxy((kolom+29), baris); cout<<Grand_Total_Tarif_Pemakaian;
    gotoxy((kolom+40), baris); cout<<Grand_Total_Jumlah_Bayar;
    getch();
}