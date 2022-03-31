// ==============================// PROGRAM DLLNC// ==============================
#include <iostream.h> // cin, cout, endl
#include <conio.h> // clrscr(), getche(), getch(), gotoxy()
#include <stdio.h>
#include <iomanip.h> // setw(), setiosflags() -> tambahan
#include <stdlib.h>
#define margin 3


int vLineLeft1 = margin+1; 
int vLineLeft2;
int stringLeft = vLineLeft1+margin+1;
int yInputSelect;
int vLineRight1, vLineRight2, stringRight, hLineRight3, hLineRight4;
int lDescSelect = 0;
int select;
int position;
int amountDatas = 0;

int lengthCharMax(int a, int b);
void lineVertical(int x, int y, int amount, char c = '|');
void lineHorizontal(int x, int y, int amount, char c = '-');
void menuLeft();
void menuDown();
void choice();
void addNew(int x, int y);
void menuRight(char title[255]);
void tableInfo(int x, int y, int amount, char title[255], int mrg, int data);
void tableInfo1();
void tableInfo2();

void addFirst();
void addLast(); 
void deleteFirst();
void deleteLast();
void printNode();
void addMiddle();
void deleteMiddle();


struct TNode { // pembuatan struc bernama Tnode
    char nama[255];
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
        menuLeft();
        menuDown();
        gotoxy(stringLeft+lDescSelect, yInputSelect); cin >> select;
        choice();
    } while (select != 8);
}

// begin modifikasi
// menghitung panjang huruf dari tipe data char
int lengthCharMax(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

// garis vertikal
void lineVertical(int x, int y, int amount, char c){
    for (int i = 0; i < amount; i++){
        gotoxy(x, y+i); cout << c;
    }
}

// garis horizontal
void lineHorizontal(int x, int y, int amount, char c){
    for(int i = 0; i < amount; i++){
        gotoxy(x+i, y); cout << c;
    }
}

// menu kiri
void menuLeft(){
    const int lchar = 9;
    yInputSelect = lchar+4;
    char menuLeftList[lchar][255] = {
        "DOUBLE LINKED LIST NON CIRCULAR",
        "[1] Tambah dari Depan", 
        "[2] Tambah dari Belakang",
        "[3] Hapus dari Depan",
        "[4] Hapus dari Belakang",
        "[5] Tampil Data", 
        "[6] Tambah dari Tengah",
        "[7] Hapus dari Tengah",
        "[8] Selesai"};
    int lCharMenuList = 0;
    for (int i = 0; i < lchar; i++){
        lCharMenuList = lengthCharMax(strlen(menuLeftList[i]), lCharMenuList);
    }
    vLineLeft2 = lCharMenuList+stringLeft+margin;
    int lMenuHorizontal = lCharMenuList+(margin*2)+2;
    lineVertical(vLineLeft1, 1, 14);
    lineVertical(vLineLeft2, 1, 14);
    lineHorizontal(vLineLeft1, 1, lMenuHorizontal);
    gotoxy(stringLeft, 2); cout << menuLeftList[0];
    lineHorizontal(vLineLeft1, 3, lMenuHorizontal);
    for (int i = 1; i < lchar; i++){
        gotoxy(stringLeft, 3+i); cout << menuLeftList[i];
    }
  
    lineHorizontal(vLineLeft1, yInputSelect-1, lMenuHorizontal);
    char descSelect[255] = "Pilihan [1 s/d 8] : ";
    lDescSelect = strlen(descSelect);
    gotoxy(stringLeft, yInputSelect); cout << descSelect;
    lineHorizontal(vLineLeft1, yInputSelect+1, lMenuHorizontal);
}

// menu bawah
void menuDown(){
    int lengthName = 4;
    amountDatas = 0;
    if(head == NULL){
        gotoxy(stringLeft, yInputSelect+8);
        cout << "Kosong";
    } else {
        // mengecek panjang nama yang di masukan
        bantu = head;
        while(bantu != NULL){
            lengthName = lengthCharMax(strlen(bantu->nama), lengthName);
            bantu = bantu->next;
        };

        // cetak
        bantu = head;
        while (bantu != NULL){
            gotoxy(stringLeft, yInputSelect+8+amountDatas);
            cout << setiosflags(ios::left)
                << setw(margin+2) << (amountDatas+1)
                << setw(margin+lengthName) << bantu->nama
                << setw(margin+4) << bantu->umur
                << setw(margin+6) << bantu->tinggi
                << setw(margin+8) << bantu->prev
                << setw(margin+8) << bantu
                << setw(margin+8) << bantu->next;
            bantu = bantu->next;
            amountDatas = amountDatas + 1;
        };
    }
    
    // int vLineDown2 = stringLeft+lengthName+4+6+2+margin+margin+margin;
    int vLineDown2 = stringLeft+lengthName+4+6+2+(8*3)+(margin*3)+margin+margin+margin;
    gotoxy(stringLeft, yInputSelect+6); 
    cout << setiosflags(ios::left)
        << setw(margin+2) << "No"
        << setw(margin+lengthName) << "Nama"
        << setw(margin+4) << "Umur"
        << setw(margin+6) << "Tinggi"
        << setw(margin+8) << "Preview"
        << setw(margin+8) << "Now"
        << setw(margin+8) << "Next";
    if(amountDatas == 0){
        lineVertical(vLineLeft1, yInputSelect+3, amountDatas+7);
        lineVertical(vLineLeft1+vLineDown2-1, yInputSelect+3, amountDatas+7);
        lineHorizontal(vLineLeft1, yInputSelect+9+amountDatas, vLineDown2);
    } else {
        lineVertical(vLineLeft1, yInputSelect+3, amountDatas+6);
        lineVertical(vLineLeft1+vLineDown2-1, yInputSelect+3, amountDatas+6);
        lineHorizontal(vLineLeft1, yInputSelect+8+amountDatas, vLineDown2);
    }
    lineHorizontal(vLineLeft1, yInputSelect+3, vLineDown2);
    lineHorizontal(vLineLeft1, yInputSelect+5, vLineDown2);
    lineHorizontal(vLineLeft1, yInputSelect+7, vLineDown2);
    gotoxy(stringLeft, yInputSelect+4); cout << "Isi Link List [" << amountDatas << "]";
}

void tableInfo(int x, int y, int amount, char title[255], int mrg, int data){
    lineVertical(x, y, 3);
    lineVertical(x+amount+(mrg*2), y, 3);
    lineHorizontal(x, y, amount+(mrg*2)+1);
    lineHorizontal(x, y+2, amount+(mrg*2)+1);
    if(data > 0){
        gotoxy(x+mrg+1, y+1); cout << title << " [" << data << "]";
    } else {
        gotoxy(x+mrg+1, y+1); cout << title;
    }
}

// menu kanan
void menuRight(char title[255]){
    vLineRight1 = vLineLeft2+margin+1;
    stringRight = vLineRight1+margin+1;
    const int aCharRight = 3;
    const int lCharRight = 11;
    char menuLeftList[aCharRight][lCharRight] = {
        "Nama   : ",
        "Umur   : ",
        "Tinggi : "};
    
    vLineRight2 = stringRight+lCharRight+40;
    hLineRight3 = vLineRight2-vLineRight1+1;
    hLineRight4 = aCharRight+4;
    lineVertical(vLineRight1, 1, hLineRight4);
    lineVertical(vLineRight2, 1, hLineRight4);
    lineHorizontal(vLineRight1, 1, hLineRight3);
    gotoxy(stringRight, 2); cout << title;
    lineHorizontal(vLineRight1, 3, hLineRight3);
    lineHorizontal(vLineRight1, hLineRight4, hLineRight3);
    for (int i = 0; i < 3; i++){
        gotoxy(stringRight, 4+i); cout << menuLeftList[i];
    }

    if(select == 6 || select == 7){
        lineVertical(vLineRight1, hLineRight4+1, 1);
        lineVertical(vLineRight2, hLineRight4+1, 1);
        lineHorizontal(vLineRight1, hLineRight4+2, hLineRight3);
        gotoxy(stringRight, hLineRight4+1);
        cout << "Masukan Posisi Sisip Anda : "; cin >> position;
        if(position <= 1){
            tableInfo1();
        } else if(position >= amountDatas){
            tableInfo1();
        } else {
            addNew(stringRight+lCharRight-1, 4);    
        }
    } else {
        addNew(stringRight+lCharRight-1, 4);
    }
}

void tableInfo1(){
    if(position <= 1){
        tableInfo(vLineRight1, hLineRight4+2, hLineRight3-(margin*2)-1, "Posisi sisip 1 bukan data tengah", margin, 0);
    } else {
        tableInfo(vLineRight1, hLineRight4+2, hLineRight3-(margin*2)-1, "Posisi sisip bukan tengah, harus kurang dari", margin, amountDatas);
    }
    getch();
}

void tableInfo2(){
    tableInfo(vLineRight1, hLineRight4+2, hLineRight3-(margin*2)-1, "Data yang dibutuhkan minimal", margin, 3);
    getch();
}


// masukan data................................
void addNew(int x, int y){
    baru = new TNode;
    gotoxy(x, y); gets(baru->nama);
    gotoxy(x, y+1); cin >> baru->umur;
    gotoxy(x, y+2); cin >> baru->tinggi;
    baru->prev = NULL;
    baru->next = NULL;
}

// pilih sub menu
void choice(){
    switch (select){
        case 1:
            addFirst();
            break;
        case 2:
            addLast();
            break;
        case 3:
            deleteFirst();
            break;
        case 4:
            deleteLast();
            break;
        case 5:
            printNode();
            break;
        case 6:
            addMiddle();
            break;
        case 7:
            deleteMiddle();
            break;
        default:
            cout << "\n Pilihan tidak tersedia!";
            break;
    }
}

void addFirst(){
    menuRight("Tambah Depan");
    if(head == NULL)
    {
        head = baru;
        head->next = NULL;
        head->prev = NULL;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

void addLast(){
    menuRight("Tambah Belakang");
    if (head == NULL)
    {
        head = baru;
        head->next = NULL;
        head->prev = NULL;
    } else {
        bantu = head;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->prev = bantu;
    }
}

void printNode(){
    clrscr();
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

void deleteFirst(){
    if(head->next != NULL){
        hapus = head;
        head = head->next;
        head->prev = NULL;
        delete hapus;
    } else {
        head = NULL;
    }
        cout<<" terhapus\n";
}

void deleteLast(){
    if(head->next != NULL){
        hapus = head;
        while(hapus->next!=NULL){
            hapus = hapus->next;
        }
        hapus->prev->next = NULL;
        delete hapus;
    } else {
        head = NULL;
    }
    cout<<" terhapus\n";
}


void addMiddle(){
    if(amountDatas >= 3){
        menuRight("Tambah Tengah");
        if(position <= 1){
        }else if(position >= amountDatas){
        } else {
        bantu = head;
        for(int i = 1; i < position-1; i++){
            bantu=bantu->next;
        }
        bantu2 = bantu->next; // menghubungkan ke node setelah yang dicari
        bantu->next = baru;
        baru->prev = bantu;
        baru->next = bantu2; // menghubungkan node baru
        bantu2->prev = baru;
        }
    } else {
        tableInfo2();
    }
}

void deleteMiddle(){
    if(amountDatas >= 3){
        tableInfo(vLineRight1, hLineRight4, hLineRight3-(margin*2)-1, "Masukan Posisi Sisip Anda : ", margin, 0);
        gotoxy(vLineRight1+margin+29, hLineRight4+1); cin >> position;
        if(position <= 1){
            tableInfo1();
        } else if(position < amountDatas){
            bantu = head;
            for(int i = 1; i < position-1; i++){
                bantu=bantu->next;
            }
            hapus = bantu->next;
            bantu2 = hapus->next;
            bantu->next = hapus->next;
            bantu2->prev = bantu;
            delete hapus;
        } else {
            tableInfo1();
        }
    } else {
        tableInfo2();
    }
}
// end modifikasi