// ==============================// PROGRAM DLLNC// ==============================
#include <iostream.h>
#include <conio.h>
// #include <stdio.h>
// #include <stdlib.h>

int pil;
void pilih();
void buat_baru();
void tambah_belakang();
void tambah_depan();
void hapus_belakang();
void hapus_depan();
void tampil();
void tambah_tengah();
void hapus_tengah();

struct TNode { // pembuatan struc bernama Tnode
    char nama[20];
    int data;
    int umur;
    float tinggi;
    TNode *next; // Pointer Next dari TNote
    TNode *prev; // Pointer Prev dari TNote
};
TNode *baru, *head = NULL, *hapus, *bantu, *bantu2;


void main(){
    do{
        clrscr();
        cout << "--------------------------------" << endl;
        cout << "DOUBLE LINKED LIST NON CIRCULAR" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Tambah dari Depan" << endl;
        cout << "2. Tambah dari Belakang" << endl;
        cout << "3. Hapus dari Depan" << endl;
        cout << "4. Hapus dari Belakang" << endl;
        cout << "5. Tampil Data" << endl;
        cout << "6. Tambah dari Tengah" << endl;
        cout << "7. Hapus dari Tengah" << endl;
        cout << "8. Selesai" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilihan [1 s/d 8] : ";
        cin >> pil;
        cout << "\n--------------------------------" << endl;
        pilih();
    } while (pil != 8);
}

void pilih(){
    if (pil == 1)
        tambah_depan();
    else if (pil == 2)
        tambah_belakang();
    else if (pil == 3)
        hapus_depan();
    else if (pil == 4)
        hapus_belakang();
    else if (pil == 5)
        tampil();
    else if (pil == 6)
        tambah_tengah();
    else if (pil == 7)
        hapus_tengah();
    else 
        cout << "selesai";
}

void buat_baru(){
    baru = new (TNode);
    cout << "input nama : "; gets(baru->nama);
    cout << "input umur : "; cin >> baru->umur;
    cout << "input tinggi : "; cin >> baru->tinggi;
    baru->prev = NULL;
    baru->next = NULL;
}
void tambah_depan(){
    buat_baru();
    if (head == NULL)
    {
        head = baru;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data masuk di link list\n";
    tampil();
}

void tambah_belakang(){
    buat_baru();
    if (head == NULL)
    {
        head = baru;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        bantu = head;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->prev = bantu;
    }
    cout << "Data masuk\n";
    tampil();
}

void hapus_depan(){
    TNode *hapus; 
    // int d;                            
    //if (isEmpty()==0){
    if(head->next != NULL){
        hapus = head;
        //d = hapus->data;
        head = head->next;
        head->prev = NULL;
        delete hapus;
    }
    else {
        //d = head->data;
        head = NULL;}
        //cout<<d<<" terhapus\n";
        tampil();
    }

void hapus_belakang(){
    TNode *hapus;
    //int d;
    if(head->next != NULL){
        hapus = head;
        while(hapus->next!=NULL){
            hapus = hapus->next;
        }
        //d = hapus->data;
        hapus->prev->next = NULL;
        delete hapus;
    } 
    else {
        //d = head->data;
        head = NULL;
    }
    //cout<<d<<" terhapus\n";
    tampil();
}

void tampil(){
    if (head==NULL)
        cout << "Kosong";
    else{
        bantu = head;
        cout << "\nData yang dimasukkan\n";
        while (bantu != NULL){
            cout << " nama : " << bantu->nama;
            cout << " umur : " << bantu->umur;
            cout << " tinggi : " << bantu->tinggi << endl;
            bantu = bantu->next;
        }
    }
    cout << "\n Tekan Enter kembali ke pilihan menu utama";
    getch();
}
void tambah_tengah(){
    int sisip;
    cout << "Masukan Posisi Sisip Anda : "; cin >> sisip;
    bantu = head; // bantu diletakan di head dulu   
    for(int i=1;i<sisip-1;i++){
        bantu=bantu->next; // menggeser hingga didapat data cari
    }
    buat_baru();
    bantu2 = bantu->next; // menghubungkan ke node setelah yang dicari
    bantu->next = baru;
    baru->prev = bantu;
    baru->next = bantu2; // menghubungkan node baru
    bantu2->prev = baru;
    tampil();
}

void hapus_tengah(){
    int sisip;
    cout<<"Masukan Posisi Sisip Anda : "; cin >> sisip;
    bantu=head;
    for(int i=1;i<sisip-1;i++){
        bantu=bantu->next;
    }
    hapus = bantu->next;
    bantu2 = hapus->next;
    bantu->next = hapus->next;
    bantu2->prev = bantu;
    delete hapus;
    tampil();
}