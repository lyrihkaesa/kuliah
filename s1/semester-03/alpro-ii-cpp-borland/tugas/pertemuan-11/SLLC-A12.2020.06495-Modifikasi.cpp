#include <iostream.h> // cin, cout, endl
#include <conio.h> // clrscr(), getche(), getch(), gotoxy()
#include <iomanip.h> // setw(), setiosflags() -> tambahan
#include <stdio.h>
// #include <kaesa.h> // header buatan sendiri
#define margin 4

struct Node{
    int notest, nilai;
    char nama[255]; // nama[20] -> nama[255]
    Node *next;
};

Node *head = NULL, *tail = NULL, *temp;

// -> tambahan/modifikasi/mulai

// menghitung panjang huruf dari tipe data char
int lengthCharMax(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

// garis vertikal
void lineVertical(int x, int y, int amount, char c = '|'){
    for (int i = 0; i < amount; i++){
        gotoxy(x, y+i); cout << c;
    }
}

// garis horizontal
void lineHorizontal(int x, int y, int amount, char c = '-'){
    for(int i = 0; i < amount; i++){
        gotoxy(x+i, y); cout << c;
    }
}

// menu kiri
int vLineLeft1 = margin+1;
int vLineLeft2;
int stringLeft = vLineLeft1+margin+1;
int yInputSelect;
int lDescSelect = 0;

void menuLeft(){
    const int lchar = 9;
    yInputSelect = lchar+4;
    char menuLeftList[lchar][255] = {
        "--Menu Pilihan (SLLC)--",
        "[1] Tambah Depan", 
        "[2] Tambah Belakang",
        "[3] Hapus Depan",
        "[4] Hapus Belakang",
        "[5] Cetak Linked List", 
        "[6] Tambah Depan Baru",
        "[7] Tambah Belakang Baru",
        "[8] Keluar"};
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
    char descSelect[255] = "Masukkan pilihan : ";
    lDescSelect = strlen(descSelect);
    gotoxy(stringLeft, yInputSelect); cout << descSelect;
    lineHorizontal(vLineLeft1, yInputSelect+1, lMenuHorizontal);
}

void menuDown(){
    int lengthName = 4;
    temp = head;
    int amountDatas = 0;
    if(temp == NULL){
        gotoxy(stringLeft, yInputSelect+8);
        cout << "Link List Kosong!";
    } else {
        do{
            lengthName = lengthCharMax(strlen(temp->nama), lengthName);
            temp = temp->next;
        } while (temp != head);
        do{
            gotoxy(stringLeft, yInputSelect+8+amountDatas);
            cout << setiosflags(ios::left) 
                << setw(margin+7) << temp->notest
                << setw(margin+lengthName) << temp->nama
                << setw(margin+5) << temp->nilai;
            temp = temp->next;
            amountDatas = amountDatas + 1;
        } while (temp != head);
    }
    int vLineDown2 = stringLeft+lengthName+7+5+margin+margin;
    gotoxy(stringLeft, yInputSelect+6); 
    cout << setiosflags(ios::left) 
        << setw(margin+7) << "No_Test"
        << setw(margin+lengthName) << "Nama"
        << setw(margin+5) << "Nilai";
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

void menuRight(char title[255]){
    int vLineRight1 = vLineLeft2+margin+1;
    int stringRight = vLineRight1+margin+1;
    const int aCharRight = 3;
    const int lCharRight = 11;
    char menuLeftList[aCharRight][lCharRight] = {
        "No Test : ",
        "Nama    : ",
        "Nilai   : "};
    
    int vLineRight2 = stringRight+lCharRight+40;
    int hLineRight3 = vLineRight2-vLineRight1+1;
    int hLineRight4 = aCharRight+4;
    lineVertical(vLineRight1, 1, hLineRight4);
    lineVertical(vLineRight2, 1, hLineRight4);
    lineHorizontal(vLineRight1, 1, hLineRight3);
    gotoxy(stringRight, 2); cout << title;
    lineHorizontal(vLineRight1, 3, hLineRight3);
    lineHorizontal(vLineRight1, hLineRight4, hLineRight3);
    for (int i = 0; i < 3; i++){
        gotoxy(stringRight, 4+i); cout << menuLeftList[i];
    }

    // masukan data................................
    gotoxy(stringRight+lCharRight-1, 4); cin >> temp->notest;
    gotoxy(stringRight+lCharRight-1, 5); gets(temp->nama);
    gotoxy(stringRight+lCharRight-1, 6); cin >> temp->nilai;
    temp->next = temp;
}

// tambah node
void addFirstNew(){
    temp = new Node;
    menuRight("Tambah Depan Baru");
    if (head == NULL){
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
        tail->next = head;
    }
}

void addLastNew(){
    temp = new Node;
    menuRight("Tambah Belakang Baru");
    if (head == NULL){
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }
}

// -> tambahan/modifikasi/selesai

void addFirst(){
    Node *temp;
    // masukkan data..................................
    temp = new Node;
    clrscr();
    cout << "Isikan Data Simpul Baru\n";
    cout << "====================================\n";
    cout << "No Test : "; cin >> temp->notest;
    cout << "Nama    : "; gets(temp->nama);
    cout << "Nilai   : "; cin >> temp->nilai;
    temp->next = temp;
    cout << endl;

    // set up link to this node...................
    if (head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
        tail->next = head;
    }
}

void addLast(){
    Node *temp;
    // masukkan data................................
    temp = new Node;
    clrscr();
    cout << "Isikan Data Simpul Baru\n";
    cout << "====================================\n";
    cout << "No Test : "; cin >> temp->notest;
    cout << "Nama    : "; gets(temp->nama);
    cout << "Nilai   : "; cin >> temp->nilai;
    temp->next = temp;
    cout << endl;

    // set up link to this node.........................
    if (head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }

}

void deleteFirst(){
    Node *temp;
    temp = head;
    // cek apakah kosong, 1 node, atau beberapa node....
    if (head == NULL){
        cout << "\nLinked List Kosong ! [Enter] ";
        getch();
    }
    else{
        // jika ada sebuah node.........................
        if (head->next == head){
            head = NULL;
            tail = NULL;
        }
        else{
            // jika node lebih dari 1...................
            head = head->next;
            tail->next = head;
        }
        delete temp;
    }
}

void deleteLast(){
    Node *temp1, *temp2;
    temp2 = tail;
    // cek apakah kosong, 1 node, atau beberapa node......
    if (head == NULL){
        cout << "\nLinked List Kosong ! [Enter] ";
        getch();
    }
    else{
        // jika ada sebuah node...........................
        if (head->next == head){
            head = NULL;
            tail = NULL;
        }
        else{
            // jika node lebih dari 1.....................
            temp1 = head;
            while(temp1->next != tail){
                temp1 = temp1->next;
            }
            tail = temp1;
            tail->next = head;
        }
        delete temp2;
    }
}

void printNode(){
    Node *temp;
    temp = head;
    if (temp == NULL){
        cout << "\nEmpty List ! [Enter] ";
    }
    else{
        clrscr();
        cout << "\nIsi Linked List\n";
        cout << "=====================================\n";

        do{
            cout << "No Test : " << temp->notest;
            cout << ", nama  : " << temp->nama;
            cout << ", nilai : " << temp->nilai << endl;
            temp = temp->next;
        } while (temp != head);
        cout << "========================================\n";
    }
    getch();
}

// program utama.......................................
void main(){
    int select;
    do{
        // tampilan Menu...............................
        clrscr();
        menuLeft();
        menuDown();
        gotoxy(stringLeft+lDescSelect, yInputSelect); cin >> select;
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
                addFirstNew();
                break;
            case 7:
                addLastNew();
                break;
            default:
                cout << "\n Pilihan tidak tersedia!";
                break;
        }
    } while (select != 8);
}