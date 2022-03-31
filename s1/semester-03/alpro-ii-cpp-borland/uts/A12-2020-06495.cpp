#include <conio.h> // clrscr(), getche(), getch().
#include <stdio.h>
#include <iostream.h> // cin, cout, endl
#include <iomanip.h> // setw(), setiosflags()
// #include <string> // tipe data string, tidak saya gunakan karena saya menggunakan char.
#define margin 2
#define lenNoPelanggan 6
#define lenNama 200
#define maxTagihan 100
#define judulProgram " Program Bubble Sort"
#define nimPembuat " A12.2020.06495"
#define namaPembuat " Kukuh Setya Arumansyah "
#define kelompok " A12.6306"

char lagi;
int jumlah = 0, garisData;
int unsigned panjangHeader = 0, panjangNama = 0;
struct spdam{
    char noPelanggan[lenNoPelanggan], golongan;
    char nama[lenNama];
    int gajiPokok, tunjangan, gajiKotor, potongan, gajiBersih;
} datatagihan[maxTagihan];

void garisVertikal(int x, int y, int count, char c = '|'){
    for (int i = 0; i < count; i++){
        gotoxy(x, y+i); cout << c;
    }
}

void tukar (int a, int b){
spdam temp;
temp = datatagihan[b];
datatagihan[b] = datatagihan[a];
datatagihan[a] = temp;
}

int hitungPanjangHeader(){
    for(int i = 0; i < 4; i++){
        if(strlen(judulProgram) > panjangHeader){
            panjangHeader = strlen(judulProgram);
        } else if(strlen(namaPembuat) > panjangHeader){
            panjangHeader = strlen(namaPembuat);
        } else if(strlen(nimPembuat) > panjangHeader){
            panjangHeader = strlen(nimPembuat);
        }  else if(strlen(kelompok) > panjangHeader){
            panjangHeader = strlen(kelompok);
        } else {
            panjangHeader = panjangHeader;
        }   
    }
    return panjangHeader;
}

void garis(int a, char b = '-'){
    for(int i = 0;i < a;i++){
        cout << b;
    }
    cout << endl;
}

void bubbleSort(){
    for (int i=1;i<jumlah;i++) {
        for (int j=0;j<jumlah-1;j++) {
            if(datatagihan[j].golongan>datatagihan[j+1].golongan)
                tukar(j,j+1);
        }
    }
}

//proses penghitungan gaji pokok dan tunjangan
void gajiTunjangan(){
    switch(datatagihan[jumlah].golongan) {
        case '1':
            datatagihan[jumlah].gajiPokok = 1000000;
            datatagihan[jumlah].tunjangan = 0.25 * datatagihan[jumlah].gajiPokok;
            break;
        case '2':
            datatagihan[jumlah].gajiPokok = 2000000;
            datatagihan[jumlah].tunjangan = 0.5 * datatagihan[jumlah].gajiPokok;
            break;
        case '3':
            datatagihan[jumlah].gajiPokok = 3000000;
            datatagihan[jumlah].tunjangan = 0.5 * datatagihan[jumlah].gajiPokok;
            break;
        }
}

//proses penghitungan gaji kotor
void prosesGajiKotor(){
    datatagihan[jumlah].gajiKotor = datatagihan[jumlah].gajiPokok + datatagihan[jumlah].tunjangan;
}

//proses penghitungan Gaji bersih
void prosesGajiBersih(){
    datatagihan[jumlah].gajiBersih = datatagihan[jumlah].gajiKotor - datatagihan[jumlah].potongan;
}

void judul(){
    garis(garisData);
    // cout<<"----------------------------------------------------------------------"<<endl;
    // cout<<"No   NIP  Nama    Gol    Gaji Kotor Potongan Gaji_Bersih "<<endl;
    cout << setiosflags(ios::left) << setw(4+margin) << " No";
    cout << setw(lenNoPelanggan+margin) << "NIP";
    cout << setw(panjangNama+margin) << "Nama";
    cout << setw(4+margin) << "Gol";
    cout << setw(11+margin) << "Gaji Kotor";
    cout << setw(9+margin) << "Potongan";
    cout << setw(12+margin) << "Gaji_Bersih";
    cout << endl;
    garis(garisData);
    // cout<<"----------------------------------------------------------------------"<<endl;
}

void data(){
    for (int i=0; i<jumlah; i++) {
        cout << setw(1) << ' ';
        cout << setw(3+margin) << (i+1);
        cout << setw(lenNoPelanggan+margin) << (datatagihan[i].noPelanggan);
        cout << setw(panjangNama+margin) << (datatagihan[i].nama);
        cout << setw(4+margin) << (datatagihan[i].golongan);
        cout << setw(11+margin) << (datatagihan[i].gajiKotor);
        cout << setw(9+margin) << (datatagihan[i].potongan);
        cout << setw(12+margin) << (datatagihan[i].gajiBersih);
        cout <<endl;
    }
    garis(garisData);
}

void headerProgram(){
    cout << judulProgram << endl;
    cout << nimPembuat << endl;
    cout << namaPembuat << endl;
    cout << kelompok << endl;
}

void main(){
    // input data pelanggan
    // tampilkan data awal
    do {
        clrscr();
        garis(hitungPanjangHeader());
        headerProgram();
        garis(hitungPanjangHeader());
        garisVertikal(1, 1, 6);
        garisVertikal(hitungPanjangHeader(), 1, 6);
        cout << "\n\n Masukkan data index ke-[" << jumlah <<"]:\n";
        cout << " No Pelanggan : "; cin >> datatagihan[jumlah].noPelanggan;
        cout << " Nama         : "; gets(datatagihan[jumlah].nama);
        if (panjangNama < strlen(datatagihan[jumlah].nama)){
             panjangNama = strlen(datatagihan[jumlah].nama);
        }
        cout << " Golongan     : "; cin >> datatagihan[jumlah].golongan;

        gajiTunjangan();

        cout << " Gaji Pokok   : " << datatagihan[jumlah].gajiPokok << endl;
        cout << " Tunjangan    : " << datatagihan[jumlah].tunjangan << endl;

        prosesGajiKotor();

        cout << " Gaji Kotor   : " << datatagihan[jumlah].gajiKotor << endl;
        cout << " Potongan     : "; cin >> datatagihan[jumlah].potongan; 

        prosesGajiBersih();

        cout << " Gaji Bersih : " << datatagihan[jumlah].gajiBersih << endl;

        // keterangan tipe otomatis muncul setelah mengisi tipe
        jumlah++;
        cout << "\n Tambah Data Lagi [y/t] :";
        lagi = getche();
        garis(hitungPanjangHeader());
    } while (strchr("Yy",lagi) !=NULL);

    // tampilkan data
    garisData = margin*7+panjangNama+40+lenNoPelanggan;
    clrscr();
    garis(garisData, '=');
    headerProgram();
    garis(garisData, '=');
    // tampilkan data setelah diurutkan
    cout <<"\n Data sebelum di sort :"<<endl;
    judul();
    data();
    // proses pengurutan data
    bubbleSort();
    // tampilkamn data setelah diurutkan
    cout << endl;
    garis(garisData, '=');
    cout <<"\n Data setelah di sort :"<<endl;
    judul();
    data();
    cout << "\n Sorting Selesai..." << endl;
    garis(garisData, '=');
    garisVertikal(1, 1, 23+(jumlah*2));
    garisVertikal(garisData+1, 1, 23+(jumlah*2));
    getch();
}