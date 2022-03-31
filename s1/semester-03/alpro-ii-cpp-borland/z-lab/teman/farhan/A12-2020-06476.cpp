// Nama : Farhan Taqi Abdussalam
// NIM : A12.2020.06476
// program mungkin mengalami bug jika melakukan input data tengah, ketika data kurang dari 2.

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define lengthMenu 20
#define lengthInput 65
#define lengthNode 96
#define margin 2
#define foundationMenu 5
#define foundationInput 40

struct Node{
    char noPelanggan[6];
    char nama[20];
    int kelompok;
    int hargaPerM;
    int pakaiPerBln;
    int totalBiaya;
    int PPN;
    int subsidi;
    int totalBayar;
    Node *prev;
    Node *next;
};

Node *childHead = NULL;
Node *childTail = NULL;
Node *childCurrent = NULL;
Node *childTemp = NULL;
Node *childBantu = NULL;
Node *childBantu2 = NULL;
Node *childHapus = NULL;

void hLine(int x, int y, int length, char c = '-');
void vLine(int x, int y, int length, char c = '|');
void displayLineMenu();
void displayMenu();
void menuTable();
void inputMenu(int *a);
void displayLineInput();
void displayInput();
void input();
void inputTable();
void pakaiPerBulan(int *a, int *b); // a = kelompok, b = pakaiPerBulan
void totalBiaya(int *a, int *b, int *c); // a = hargaPerM, b
void PPN(int *a, int *b, int *c);
void subsidi(int *a, int *b, int *c);
void totalBayar(int *a, int *b, int *c, int *d);
void addFront();
void insertMiddle(int *a);
void addMiddle();
void addBehind();
void deleteFront();
void deleteMiddle();
void deleteBehind();
void linePrintNode();
void headerPrintNode();
void printNode();


void main(){
    int choice;
    do{
        clrscr();
        menuTable();
        inputMenu(&choice);
        switch(choice){
            case 1:
                addFront();
                break;
            case 2:
                addMiddle();
                break;
            case 3:
                addBehind();
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteMiddle();
                break;
            case 6:
                deleteBehind();
                break;
            case 7:
                printNode();
                break;
            case 8:
                break;
        }
    }while(choice != 8);
}

void hLine(int x, int y, int length, char c){
    for(int i = 0; i < length; i++){
        gotoxy(x+i, y); cout << c;
    }
}

void vLine(int x, int y, int length, char c){
    for(int i = 0; i < length; i++){
        gotoxy(x, y+i); cout << c;
    }
}

void displayLineMenu(){
    hLine(foundationMenu,3,10+lengthMenu,'='); //top header horizontal
    hLine(foundationMenu,5,10+lengthMenu, '='); //bot header horizontal
    hLine(foundationMenu,14,10+lengthMenu); //middle horizontal
    hLine(foundationMenu,16,10+lengthMenu); //bottom horizontal
    vLine(foundationMenu,3,14); //left vertical
    vLine(foundationMenu+10+lengthMenu,3,14); //right vertical
}

void displayMenu(){
    gotoxy(foundationMenu+margin, 4); cout << "Menu";
    gotoxy(foundationMenu+margin, 6); cout << "[1] Tambah Depan"; //done
    gotoxy(foundationMenu+margin, 7); cout << "[2] Tambah Tengah";
    gotoxy(foundationMenu+margin, 8); cout << "[3] Tambah Belakang"; //done
    gotoxy(foundationMenu+margin, 9); cout << "[4] Hapus Depan"; //done
    gotoxy(foundationMenu+margin, 10); cout << "[5] Hapus Tengah";
    gotoxy(foundationMenu+margin, 11); cout << "[6] Hapus Belakang"; //done
    gotoxy(foundationMenu+margin, 12); cout << "[7] Tampilkan Data"; //done
    gotoxy(foundationMenu+margin, 13); cout << "[8] Exit"; //done
    gotoxy(foundationMenu+margin, 15); cout << "Masukkan Pilihan : "; //done
}

void inputMenu(int *a){
    gotoxy(foundationMenu+margin+20, 15); cin >> *a;
}

void menuTable(){
    displayLineMenu();
    displayMenu();
}

void displayLineInput(){
    hLine(foundationInput,3,10+lengthInput, '='); //top header horizontal
    hLine(foundationInput,5,10+lengthInput, '='); //bot header horizontal
    hLine(foundationInput,11,10+lengthInput); //top footer horizontal
    hLine(foundationInput,13,10+lengthInput); //bot footer horizontal
    vLine(foundationInput,3,11); //left vertical
    vLine(foundationInput+10+lengthInput,3,11); //right vertical
}

void displayInput(){
    gotoxy(foundationInput+margin, 4);  cout << "Input Data";
    gotoxy(foundationInput+margin, 6);  cout << "No Pelanggan     : ";
    gotoxy(foundationInput+margin, 7);  cout << "Nama             : ";
    gotoxy(foundationInput+margin, 8);  cout << "Kelompok [1/2/3] : ";
    gotoxy(foundationInput+margin, 9);  cout << "Harga per M      : "; //otomatis
    gotoxy(foundationInput+margin, 10); cout << "Pemakaian/Bulan  : ";
    gotoxy(foundationInput+margin+40, 6); cout << "Total Biaya : "; //otomatis
    gotoxy(foundationInput+margin+40, 7); cout << "PPN         : "; //otomatis
    gotoxy(foundationInput+margin+40, 8); cout << "Subsidi     : "; //otomatis
    gotoxy(foundationInput+margin, 12); cout << "Total Bayar   : "; //otomatis
}

void input(){
    childTemp = new Node;
    gotoxy(foundationInput+21,6); gets(childTemp->noPelanggan);
    gotoxy(foundationInput+21,7); gets(childTemp->nama);
    gotoxy(foundationInput+21,8); cin >> childTemp->kelompok;

    pakaiPerBulan(&childTemp->kelompok, &childTemp->hargaPerM);
    gotoxy(foundationInput+21,9); cout << childTemp->hargaPerM;

    gotoxy(foundationInput+21,10); cin >> childTemp->pakaiPerBln;

    totalBiaya(&childTemp->hargaPerM, &childTemp->pakaiPerBln, &childTemp->totalBiaya);
    gotoxy(foundationInput+56,6); cout << childTemp->totalBiaya;

    PPN(&childTemp->kelompok, &childTemp->totalBiaya, &childTemp->PPN);
    gotoxy(foundationInput+56,7); cout << childTemp->PPN;

    subsidi(&childTemp->kelompok, &childTemp->totalBiaya, &childTemp->subsidi);
    gotoxy(foundationInput+56,8); cout << childTemp->subsidi;

    totalBayar(&childTemp->totalBiaya, &childTemp->PPN, &childTemp->subsidi, &childTemp->totalBayar);
    gotoxy(foundationInput+18,12); cout << childTemp->totalBayar;

    childTemp->prev = childTemp;
    childTemp->next = childTemp;
    getch();
}

void pakaiPerBulan(int *a, int *b){
    switch(*a){
        case 1:
            *b = 5000;
            break;
        case 2:
            *b = 4000;
            break;
        case 3:
            *b = 3500;
            break;
        default:
            *b = 0;
            break;
    }
}

void totalBiaya(int *a, int *b, int *c){
    *c = *a * *b;
}

void PPN(int *a, int *b, int *c){
    switch(*a){
        case 1:
            *c = *b * 3/100;
            break;
        case 2:
            *c = *b * 2/100;
            break;
        case 3:
            *c = *b * 1/100;
            break;
    }
}

void subsidi(int *a, int *b, int *c){
    switch(*a){
        case 1:
            *c = 0.50 * *b;
            break;
        case 2:
            *c = 0.30 * *b;
            break;
        case 3:
            *c = 0.10 * *b;
            break;
    }
}

void totalBayar(int *a, int *b, int *c, int *d){
    *d = *a - (*b + *c);
}

void inputTable(){
    displayLineInput();
    displayInput();
    input();
}

void addFront(){
    inputTable();
    if(childHead == NULL){
        childHead = childTemp;
        childTail = childTemp;
        childCurrent = childHead;
    }
    else{
        childTemp->next = childHead;
        childHead->prev = childTemp;
        childTemp->prev = childTail;
        childTail->next = childTemp;
        childHead = childTemp;
    }
}

void addBehind(){
    inputTable();
    if(childHead == NULL){
        childHead = childTemp;
        childTail = childTemp;
        childCurrent = childTail;
    }
    else{
        childTail->next = childTemp;
        childTemp->prev = childTail;
        childHead->prev = childTemp;
        childTemp->next = childHead;
        childTail = childTemp;
    }
}

void deleteFront(){
    childTemp = childHead;
    // cek node kosong
    if(childHead == NULL){
        cout << "\nLinked List Kosong ! [Enter] ";
        getch();
    }
    else{
        // Jika hanya ada 1 node
        if(childHead == childTail){
            childHead == NULL;
            childTail == NULL;
        }
        // jika lebih dari 1 node
        else{
            childHead = childHead->next;
            childHead->prev = childTail;
            childTail->next = childHead;
        }
        delete childTemp;
        childCurrent = childHead;
    }
}

void deleteBehind(){
    childTemp = childTail;
    //cek node kosong
    if(childHead == NULL){
        cout << "\nLinked List Kosong ! [Enter] ";
        getch();
    }
    else{
        //jika ada 1 node
        if(childHead == childTail){
            childHead = NULL;
            childTail = NULL;
        }
        //jika ada lebih dari 1 node
        else{
            childTail = childTail->prev;
            childTail->next = childHead;
            childHead->prev = childTail;
        }
        delete childTemp;
        childCurrent = childHead;
    }
}
void linePrintNode(){
    hLine(foundationMenu,3,10+lengthNode,'='); //top header horizontal
    hLine(foundationMenu,5,10+lengthNode,'='); //bot header horizontal
    hLine(foundationMenu,16,10+lengthNode); //bot footer horizontal
    vLine(foundationMenu,3,14); //left vertical
    vLine(foundationMenu+14,3,14); //end No Pelanggan
    vLine(foundationMenu+margin+27,3,14); //end Nama
    vLine(foundationMenu+margin+36,3,14); //end kelompok
    vLine(foundationMenu+margin+48,3,14); //end Harga/M
    vLine(foundationMenu+margin+60,3,14); //end pakai/bulan
    vLine(foundationMenu+margin+72,3,14); //end Total Biaya
    vLine(foundationMenu+margin+80,3,14); //end PPN
    vLine(foundationMenu+margin+90,3,14); //end subsidi
    vLine(foundationMenu+10+lengthNode,3,14); //right vertical
}

void headerPrintNode(){
    gotoxy(foundationMenu+margin, 4); cout << "No Pelanggan";
    gotoxy(foundationMenu+margin+13, 4); cout << "Nama";
    gotoxy(foundationMenu+margin+28, 4); cout << "Kelompok";
    gotoxy(foundationMenu+margin+37, 4); cout << "Harga/M";
    gotoxy(foundationMenu+margin+49, 4); cout << "Pakai/Bulan";
    gotoxy(foundationMenu+margin+61, 4); cout << "Total Biaya";
    gotoxy(foundationMenu+margin+73, 4); cout << "PPN";
    gotoxy(foundationMenu+margin+81, 4); cout << "Subsidi";
    gotoxy(foundationMenu+margin+91, 4); cout << "Total Bayar";
}

void printNode(){
    childTemp = childHead;
    int x = foundationMenu+margin;
    int y = 6;

    if(childTemp == NULL){
        gotoxy(foundationMenu+margin, 17);cout << "Empty List! [Enter] ";
        getch();
    }
    else{
        clrscr();
        do{
            linePrintNode();
            headerPrintNode();
            gotoxy(x,y); cout << childTemp->noPelanggan;
            gotoxy(x+13,y); cout << childTemp->nama;
            gotoxy(x+28,y); cout << childTemp->kelompok;
            gotoxy(x+37,y); cout << childTemp->hargaPerM;
            gotoxy(x+49,y); cout << childTemp->pakaiPerBln;
            gotoxy(x+61,y); cout << childTemp->totalBiaya;
            gotoxy(x+73,y); cout << childTemp->PPN;
            gotoxy(x+81,y); cout << childTemp->subsidi;
            gotoxy(x+91,y); cout << childTemp->totalBayar;
            childTemp = childTemp->next;
            y++;
        }while(childTemp != childHead);
    }
    getch();
}

void insertMiddle(int *a){
    gotoxy(foundationInput+margin+40,4); cout << "Masukkan Posisi : "; cin >> *a;
}

void addMiddle(){
    int insert;
    insertMiddle(&insert);
    childBantu = childHead;

    for(int i = 1; i < insert-1; i++){
        childBantu = childBantu->next;
    }

    inputTable();
    childBantu2 = childBantu->next;
    childBantu->next = childTemp;
    childTemp->prev = childBantu;
    childTemp->next = childBantu2;
    childBantu2->prev = childTemp;
}

void deleteMiddle(){
    int insert;
    insertMiddle(&insert);
    childBantu = childHead;

    for(int i = 1; i < insert-1; i++){
        childBantu = childBantu->next;
    }
    childHapus = childBantu->next;
    childBantu2 = childHapus->next;
    childBantu->next = childHapus->next;
    childBantu2->prev = childBantu;
    delete childHapus;
}