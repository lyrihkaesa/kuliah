#include <iostream.h>
#include <stdio.h>
#include <conio.h>

char d[200] = "_________________________________________________________________________________________________________\n";
char nip[25], nama[25], jenis_kelamin[1], nama_jabatan[10], nama_status[15], nama_jenis_kelamin[10];
int status = 0, golongan, jabatan, gaji_pokok, tunj_istri, tunj_anak, tunj_jabatan, gaji_kotor, pajak, biaya_jabatan, gaji_bersih;

void main()
{
    cout<<d<<"\n PT. Terang Benerang\n Jl. Merdeka Raya 17\n Semarang\n"<<d;
    // Gari bagian paling bawah
    int klm = 1, brs = 1;
    gotoxy(klm, (brs+15)); cout<<d;
     // Garis bagian Kanan
    klm = klm + 105;
    for (brs = 16; brs > 1; brs--) {
        gotoxy(klm, brs); cout<<"|";
    }
    int baris = 7, kolom = 5;
    gotoxy((kolom+38), baris); cout<<"Input Gaji Pegawai";
    baris++;
    // Input/Masukan NIM, Nama, Jenis Kelamin, Status, Golongan, Jabatan.
    gotoxy(kolom, (baris+1)); cout<<"1. NIP            = "; gets(nip);
    gotoxy(kolom, (baris+2)); cout<<"2. Nama           = "; gets(nama);
    gotoxy(kolom, (baris+3)); cout<<"3. Jenis Kelamin  = "; gets(jenis_kelamin);
    // Pilihan Jika P/p = Pria, jika W/w = Wanita, selain itu keluar "Input harus P/W"
    int jk_k = strcmp("P", jenis_kelamin) == 0;
    int jk_b = strcmp("p", jenis_kelamin) == 0;
    if (jk_k || jk_b) {
        strcpy (nama_jenis_kelamin,"(Pria)");
    }
    else if (strcmp("W", jenis_kelamin) == 0 || strcmp("w", jenis_kelamin) == 0) {
        strcpy (nama_jenis_kelamin,"(Wanita)");
    }
    else {
        strcpy (nama_jenis_kelamin,"Input harus P/W");
    }
    // Output/Keluaran P/p = Pria & W/w = Wanita
    gotoxy((kolom+22), (baris+3)); cout<<nama_jenis_kelamin;
    gotoxy(kolom, (baris+4)); cout<<"4. Status         = "; cin>>status;
    // Pilihan Status.
    if (status == 0) {
        strcpy (nama_status,"(Belum Menikah)");
    }
    else if (status == 1) {
        strcpy (nama_status,"(Menikah anak 1)");
    }
    else if (status == 2) {
        strcpy (nama_status,"(Menikah anak 2)");
    }
    else if (status == 3) {
        strcpy (nama_status,"(Menikah anak 3)");
    }
    else if (status == 4) {
        strcpy (nama_status,"(Menikah anak 4)");
    }
    // Output Keterangan Status
    gotoxy((kolom+22), (baris+4)); cout<<nama_status;
    gotoxy(kolom, (baris+5)); cout<<"5. Golongan       = "; cin>>golongan;
    // Pilihan gaji pokok berdasarkan golongan
    if (golongan == 1) {
        gaji_pokok = 1000000;
    }
    else if (golongan == 2) {
        gaji_pokok = 2000000;
    }
    else if (golongan == 3) {
        gaji_pokok = 3500000;
    }
    gotoxy(kolom, (baris+6)); cout<<"6. Jabatan        = "; cin>>jabatan;
    // Pilihan Keterangan Jabatan, Tunjangan jabatan berdasarkan jabatan yang ditempuh.
    if (jabatan == 1) {
        strcpy (nama_jabatan,"(Direktur)");
        tunj_jabatan = 5000000;
    }
    else if (jabatan == 2) {
        strcpy (nama_jabatan,"(Ka Bag)");
        tunj_jabatan = 2000000;
    }
    else if (jabatan == 3) {
        strcpy (nama_jabatan,"(Staff)");
        tunj_jabatan = 0;
    }
    // Output Keterangan Jabatan & Gaji Pokok berdasarkan Golongan
    gotoxy((kolom+22), (baris+6)); cout<<nama_jabatan;
    gotoxy(kolom, (baris+7)); cout<<"   Gaji Pokok     = "<<gaji_pokok;

    // Kolom Ke-2.............................
    kolom = kolom + 50;
    // Pilihan jika P/p/Pria akan mendapatakn tunjangan istri & anak
    if (jk_k || jk_b) {
        tunj_istri = 0.1 * gaji_pokok;
        tunj_anak = 0.05 * gaji_pokok * status;
    }
    else {
        tunj_istri = 0;
        tunj_anak = 0;
    }
    
    // Output Tunjangan Istri, Anak, Jabatan
    gotoxy(kolom, (baris+1)); cout<<"Tunjangan Istri   = "; cout<<tunj_istri;
    gotoxy(kolom, (baris+2)); cout<<"Tunjangan Anak    = "; cout<<tunj_anak;
    gotoxy(kolom, (baris+3)); cout<<"Tunjangan Jabatan = "; cout<<tunj_jabatan;
    // Rumus Dan Output Gaji Kotor
    gaji_kotor = gaji_pokok + tunj_istri + tunj_anak + tunj_jabatan;
    gotoxy(kolom, (baris+4)); cout<<"Gaji Kotor        = "; cout<<gaji_kotor;
    // Rumus Dan Output Pajak
    pajak = 0.05 * gaji_kotor;
    gotoxy(kolom, (baris+5)); cout<<"Pajak             = "; cout<<pajak;
    // Pilihan biaya jabatan berdasarkan jabatan
    if (jabatan == 1) {    
        biaya_jabatan = 0.1 * gaji_kotor;
    }
    else if (jabatan == 2) {
        biaya_jabatan = 0.05 * gaji_kotor;
    }
    else if (jabatan == 3) {
        biaya_jabatan = 0;
    }
    // Output Biaya jabatan
    gotoxy(kolom, (baris+6)); cout<<"Biaya Jebatan     = "; cout<<biaya_jabatan;
    // Rumus & output Gaji Bersih
    gaji_bersih = gaji_kotor - pajak + biaya_jabatan;
    gotoxy(kolom, (baris+7)); cout<<"Gaji Bersih       = "; cout<<gaji_bersih;

    getch();
}