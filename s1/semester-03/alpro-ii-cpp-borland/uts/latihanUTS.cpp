#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <iomanip.h>
#include <string>
int const n=5;
int jml;
struct spdam
{
 char nopelanggan[5];
 string nama;
 char tipe;
 string kettipe;
 int byadm,jmlpakai,bypajak,bypotongan,hrg;
 int totalbayar;
};
spdam datatagihan[n];
void tukar (int a, int b)
{
spdam temp;
temp=datatagihan[b];
datatagihan[b] =datatagihan[a];
datatagihan[a]=temp;
}
void bubbleSort()
{
 for (int i=1;i<jml;i++)
 {
 for (int j=0;j<jml-1;j++)
 {
 if(datatagihan[j].tipe>datatagihan[j+1].tipe)
 tukar(j,j+1);
 }
 }
}
void main()
{
// input data pelanggan
cout<<"==Program Buble Sort=="<<endl;
//tampilkan data awal
jml=0;
while (jml<n)
 {
 cout << "\n\nMasukkan data index [" << jml <<"] :\n";
 cout << "No Pelanggan :";cin >>datatagihan[jml].nopelanggan;
cout << "Nama :"; cin >>datatagihan[jml].nama; // bisa tapi tanpa spasi
// cout << "Nama :"; gets(datatagihan[jml].nama); // bisa dengan spasi tapi hanya tipe data char
// cin.ignore();
// cout << "Nama :"; getline(cin, datatagihan[jml].nama); // bisa dengan spasi, tapi hanya bisa di comppile dengan BorlandC++ 5.5.1
//  cout << "Nama :"; cin.getline(datatagihan[jml].nama, 200); // bisa dengan spasi tapi hanya tipe data char dan konstan
 cout << "Tipe [1/2/3] :";cin >>datatagihan[jml].tipe;
 switch(datatagihan[jml].tipe)
 {
 case '1':
 datatagihan[jml].kettipe="Sangat Sangat Sederhana";
 datatagihan[jml].byadm = 50000;
 datatagihan[jml].bypajak =0;
datatagihan[jml].bypotongan = 0.025*datatagihan[jml].byadm;
 break;
 case '2':
 datatagihan[jml].kettipe ="Sangat Sederhana";
 datatagihan[jml].byadm = 60000;
 datatagihan[jml].bypajak = 0.025*datatagihan[jml].byadm;
 datatagihan[jml].bypotongan = 0;
 break;
 case '3':
datatagihan[jml].kettipe ="Sederhana";
 datatagihan[jml].byadm = 60000;
 datatagihan[jml].bypajak = 0.5*datatagihan[jml].byadm;
 datatagihan[jml].bypotongan = 0;
 break;
 default :
 datatagihan[jml].byadm = 50000;
 datatagihan[jml].bypajak =0;
datatagihan[jml].bypotongan = 0;
 break;
 }
 // keterangan tipe otomatis muncul setelah mengisi tipe
 cout << "Tipe :";cout<< datatagihan[jml].kettipe;
 cout << "\nJumlah Pemakaian :";cin >>datatagihan[jml].jmlpakai;
 datatagihan[jml].totalbayar=datatagihan[jml].byadm+datatagihan[jml].bypajak+datatagihan[jml].jmlpakai
 - datatagihan[jml].bypotongan;
 jml++;
 cout << "\n Tambah Data Lagi [y/t] :";
 char lagi =getche();
 if(strchr("Tt",lagi) !=NULL)
 break;
 }
//tampilkan data
clrscr();
cout <<"\nData Awal :"<<endl;
 //tampilkamn data setelah diurutkan
cout <<"\n\nData sebelum di sort :"<<endl;
cout<<"-------------------------------------------------=--------------------"<<endl;
cout<<"No NoPel Nama Tipe b.Admin Pajak Potongan total "<<endl;
cout<<"----------------------------------------------------------------------"<<endl;
for (int i=0; i<jml; i++)
{
 cout << setiosflags(ios::right)<<setw(2)<<(i+1);
 cout << setiosflags(ios::right)<<setw(3) << (datatagihan[i].nopelanggan);
 cout << setiosflags(ios::right)<<setw(8)<< (datatagihan[i].nama);
 cout << setiosflags(ios::right)<<setw(15) << (datatagihan[i].tipe);
 cout << setiosflags(ios::right)<<setw(9) << (datatagihan[i].byadm);
 cout << setiosflags(ios::right)<<setw(7) << (datatagihan[i].bypajak);
 cout << setiosflags(ios::right)<<setw(10) << (datatagihan[i].bypotongan);
 cout << setiosflags(ios::right)<<setw(10) << (datatagihan[i].totalbayar);
 cout <<endl;
}
//proses pengurutan data
bubbleSort();
//tampilkamn data setelah diurutkan
cout <<"\n\nData setelah di sort :"<<endl;
cout<<"----------------------------------------------=-------------------------"<<endl;
cout<<"No NoPel Nama Tipe b.Admin Pajak Potongan total "<<endl;
cout<<"------------------------------------------------------------------------"<<endl;
for (int a=0; a<jml;a++)
{
 cout << setiosflags(ios::right)<<setw(2) << (a+1);
 cout << setiosflags(ios::right)<<setw(3) << (datatagihan[a].nopelanggan);
 cout << setiosflags(ios::right)<<setw(8)<< (datatagihan[a].nama);
 cout << setiosflags(ios::right)<<setw(15) << (datatagihan[a].tipe);
 cout << setiosflags(ios::right)<<setw(9) << (datatagihan[a].byadm);
 cout << setiosflags(ios::right)<<setw(7) << (datatagihan[a].bypajak);
 cout << setiosflags(ios::right)<<setw(10) << (datatagihan[a].bypotongan);
 cout << setiosflags(ios::right)<<setw(10) << (datatagihan[a].totalbayar);
 cout <<endl;
 }
 cout << "\n\nSorting Selesai";
 getch();
}