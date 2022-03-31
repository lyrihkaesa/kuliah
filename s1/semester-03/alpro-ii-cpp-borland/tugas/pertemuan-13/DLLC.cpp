#include <iostream.h> // cin, cout, endl
#include <conio.h> // clrscr(), getche(), getch(), gotoxy()
#include <iomanip.h> // setw(), setiosflags() -> tambahan
// #include <stdio.h>
#define margin 2

// Source Code version 1.0.0

int pading = margin+1;
int position, amountDatas;
int lengthCharMax(int a, int b);
int aData(char inputCHar[255][255]);
int loopLCM(int inputLC, char inputChar[255][255]);
void lineVertical(int x, int y, int amount, char c = '|');
void lineHorizontal(int x, int y, int amount, char c = '-');
void table(int x, int y, char xc, char yc, char title[255][255], int marginL, bool b = false, int amount = 0);
void tableInput(int x, int y, char xc, char yc, int amount, int ld, char lc[255], int md1, char mc[255], int md2, char rc[255], int rd, int marginL, bool b = false, bool goxymiddle = false);
void tabelInputSub(int x, int y, char c[255], int marginL);
void tableHD(int x, int y, char title[255][255], int marginL, bool b = false, bool goxymiddle = false);
char menuLeftList[255][255] = {
        "Menu Double Linked List Circular (DLLC)",
        " ",
        "[1]  + Tambah Depan", 
        "[2]  + Tambah Belakang",
        "[3]  x Hapus Depan",
        "[4]  x Hapus Belakang",
        "[5]  P Cetak Linked List", 
        "[6]  ^ Current Pindah Ke-atas",
        "[7]  v Current Pindah Ke-bawah",
        "[8]  o Current Pindah Tertentu",
        "[9]  + Tambah Current",
        "[10] x Hapus Current",
        "[11] x Hapus Semua",
        "[12] ! Keluar"
};

char subMenuList[255][255] = {
    "Tambah Depan",
    "Tambah Belakang",
    "Tambah Current",
};

char textInputDatas[255][255] = {
    "Nomor  : ",
    "Nama   : "
};

void inputDatas(int x, int y, char title[255][255]);
void printInputDatas(int x, int y, char title[255], char subTitle[255][255], int marginL, int b = false, int amount = 0);
void allInputDatas(int x, int y, char title[255]);
void tablePrintDatas(int x, int y, int marginL, bool b = false);
void printNodeOut();

void addFirst();
void addLast();
void deleteFirst();
void deleteLast();
void printNode();
void upCurrent();
void downCurrent();
void positionCurrent();
void addCurrent();
void deleteCurrent();
void deleteAll();

struct Node{
    char nama[255];
    // int kelompok, harga, bulan, biaya, subsidi, ppn, bayar;
    int nomor;
    Node *prev;
    Node *next;
};

Node *head, *tail, *current = NULL;
Node *temp;

void main(){
    int select;
    do{
        clrscr();
        tableHD(pading, 2, menuLeftList, margin);
        tablePrintDatas(pading, 21, margin);
        tableInput(pading, 17, '-', '|', 45, -1, "Masukan Pilihan Menu: ", -1, " ", -1, " ", -1, margin, false, true);
        cin >> select;
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
                upCurrent();
                break;
            case 7:
                downCurrent();
                break;
            case 8:
                positionCurrent();
                break;
            case 9:
                addCurrent();
                break;
            case 10:
                deleteCurrent();
                break;
            case 11:
                deleteAll();
                break;
            default:
                break;
        }
    } while (select != 12);
}

// menghitung panjang huruf dari tipe data char
int lengthCharMax(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

// menghitung jumlah data pada tipedata char array
int aData(char inputCHar[255][255]){
    int a = 0;
    for (int i = 0; i < 255; i++){
        if(strcmp(inputCHar[i], "")){
            a++;
        }
    }
    return a;
}

// menghitung panjang huruf setiap data dari tipedata char dalam bentuk array
int loopLCM(int inputLC, char inputChar[255][255]){
    int lengthChar = 0;
    for (int i = 0; i < inputLC; i++){
        lengthChar = lengthCharMax(strlen(inputChar[i]), lengthChar);
    }
    return lengthChar;
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

// tabel dengan isi tipedata char array
void table(int x, int y, char xc, char yc, char title[255][255], int marginL, bool b, int amount){
    int amountDataTitles = aData(title);
    int lLineH1 = lengthCharMax((loopLCM(amountDataTitles, title)+(marginL*2)+2), amount);
    int lLineV1 = amountDataTitles+2;
    int lLineH2 = lLineH1+x-1;
    int lLineV2 = lLineV1+y-1;
    lineVertical(x, y, lLineV1, yc);
    lineVertical(lLineH2, y, lLineV1, yc);
    lineHorizontal(x, y, lLineH1, xc);
    lineHorizontal(x, lLineV2, lLineH1, xc);
    for (int i = 0; i < amountDataTitles; i++){
        gotoxy(x+marginL+1, y+1+i); cout << title[i];
    }
    if(b){
        lineHorizontal(lLineH2, lLineV2, 1, '?');
        gotoxy(lLineH2+1, lLineV2); cout << " -> (" << lLineH2 << ", " << lLineV2 << ", " << lLineH1 << ")";
    }
}

// tabel dengan isi tipedata char dan input integer
void tableInput(int x, int y, char xc, char yc, int amount,  int ld, char lc[255], int md1, char mc[255], int md2, char rc[255], int rd, int marginL, bool b, bool goxymiddle){
    int lLineH = x + amount-1;
    int lLineV = y+2;
    lineVertical(x, y, 3, yc);
    lineVertical(lLineH, y, 3, yc);
    lineHorizontal(x, y, amount, xc);
    lineHorizontal(x, lLineV, amount, xc);
    gotoxy(x+marginL+1, y+1);
    if(ld > -1){
        cout << ld;
    }
    cout << lc;
    if(md1 > -1){
        cout << md1;
    }
    cout << mc;
    if(md2 > -1){
        cout << md2;
    }
    cout << rc;
    if(rd > -1){
        cout << rd;
    }
    if(b){
        lineHorizontal(lLineH, lLineV, 1, '?');
        gotoxy(lLineH+1, lLineV); cout << " -> (" << lLineH << ", " << lLineV << ", " << amount << ")";
    }
    if(goxymiddle){
        gotoxy(x+marginL+(strlen(lc)+1), y+1);     
    }
}

// input tambahan dari tabelInput
void tabelInputSub(int x, int y, char c[255], int marginL){
    gotoxy(x+marginL+(strlen(c)+1), y+1); 
}

// table dengan isi tipedata char array + judul
void tableHD(int x, int y, char title[255][255], int marginL, bool b, bool goxymiddle){
    table(x, y, '-', '|', title, marginL, b);
    int xR1 = loopLCM(aData(title), title) + (marginL*2)+2;
    tableInput(x, y, '=', '|', xR1, -1, title[0], -1, " ", -1, " ", -1, marginL, b, goxymiddle);
}

void check1(){
    tableInput(pading+47, 10, '!', '!', 45, -1, "Linked List Masih Kosong", -1, " ", -1, " ", -1, margin, true, false);
    getch();
}

void check2(char c[255]){
    tableInput(pading+47, 10, '!', '!', 45, -1, c, -1, " ", -1, " ", -1, margin, true, false);
    getch();
}

void inputDatas(int x, int y, char title[255][255]){
    temp = new Node;
    int amountDataTitles = aData(title);
    int lText = loopLCM(amountDataTitles, title);
    int lText1 = lText + 1;
    gotoxy(x+lText1, y); cin >> temp->nomor;
    gotoxy(x+lText1, y+1); gets(temp->nama);
    // Masukan variabel masukan

    temp->prev = temp;
    temp->next = temp;
}

void printInputDatas(int x, int y, char title[255], char subTitle[255][255], int marginL, int b, int amount){
    table(x, y+2, '-', '|', subTitle, marginL, b, amount);
    tableInput(x, y, '=', '|', amount, -1, title, -1, " ", -1, " ", -1, margin, b);
}

void allInputDatas(int x, int y, char title[255]){
    printInputDatas(x, y, title, textInputDatas, margin, false, 40);
    inputDatas(x+margin, y+3, textInputDatas);
}

void tablePrintDatas(int x, int y, int marginL, bool b){
    int lengthName = 4;
    int lLineH1 = x+marginL+1;
    int lLineV1 = y+4;
    amountDatas = 0;
    if(head == NULL){
        gotoxy(lLineH1, lLineV1+1);
        cout << "Linked List Kosong!";
    } else {
        temp = head;
        do{
            lengthName = lengthCharMax(strlen(temp->nama), lengthName);
            temp = temp->next;
        } while (temp != head);

        temp = head;
        do{
            int ll = lLineH1+(marginL*8)+5+lengthName+(8*3);
            int ly = lLineV1+1+amountDatas;
            gotoxy(lLineH1, ly);
            cout << setiosflags(ios::left)
                << setw(marginL+2) << (amountDatas+1)
                << setw(marginL+5) << temp->nomor
                << setw(marginL+lengthName) << temp->nama
                << setw(marginL+8) << temp->prev
                << setw(marginL+8) << temp
                << setw(marginL+8) << temp->next;

            if(temp == tail){
                lineHorizontal(ll, ly, 16+7, '.');
                gotoxy(ll+16+7, ly);
                cout << "< Tail";
            }
            if(temp == head){
                lineHorizontal(ll, ly, 16, '.');
                gotoxy(ll+16, ly);
                cout << "< Head ";
            }
            if(temp == current){
                gotoxy(ll, ly);
                cout << "<- Current Node ";
            }
            temp = temp->next;
            amountDatas = amountDatas + 1;
        } while (temp != head);        
    };

    int al = (marginL*8)+2+5+lengthName+(8*3);
    gotoxy(lLineH1, y+3);
    cout << setiosflags(ios::left)
        << setw(marginL+2) << "No"
        << setw(marginL+5) << "Nomor"
        << setw(marginL+lengthName) << "Nama"
        << setw(marginL+8) << "Preview"
        << setw(marginL+8) << "Now"
        << setw(marginL+8) << "Next";

    if(amountDatas == 0){
        lineVertical(x, y, 7);
        lineVertical(al+2, y, 7);
        lineHorizontal(x, lLineV1+2, al);
        if(b){
            lineHorizontal(x+al-1, lLineV1+2, 1, '?');
            gotoxy(x+al, lLineV1+2); cout << " -> (" << x+al-1 << ", " << lLineV1+2<< ", " << al << ")";
        }
    } else {
        lineVertical(x, y, 5+amountDatas);
        lineVertical(al+2, y, 5+amountDatas);
        lineHorizontal(x, lLineV1+1+amountDatas, al);
        if(b){
            lineHorizontal(x+al-1, lLineV1+1+amountDatas, 1, '?');
            gotoxy(x+al, lLineV1+1+amountDatas); cout << " -> (" << x+al-1 << ", " << lLineV1+1+amountDatas << ", " << al << ")";
        }
    }
    lineHorizontal(x, lLineV1, al, '=');
    tableInput(x, y, '=', '|', al, -1, "Isi Linked List: ", amountDatas, " ", -1, " ", -1, marginL, b, false);
    if(b){
        lineHorizontal(x+al-1, lLineV1, 1, '?');
        gotoxy(x+al, lLineV1); cout << " -> (" << x+al-1 << ", " << lLineV1 << ", " << al << ")";
    }
}

void addFirst(){
    allInputDatas(pading+47, 2, subMenuList[0]);
    if(head == NULL){
        head = temp;
        tail = temp;
        current = head;
    } else {
        temp->next = head;
        head->prev = temp;
        temp->prev = tail;
        tail->next = temp;
        head = temp;
    }
}

void addLast(){
    allInputDatas(pading+47, 2, subMenuList[1]);
    if(head == NULL){
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        head->prev = temp;
        temp->next = head;
        tail = temp;
    }
}

void deleteFirst(){
    temp = head;
    if(head == NULL){
        check1();
    } else {
        if(head == tail){
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        delete temp;
        current = head;
    }
}

void deleteLast(){
    temp = tail;
    if(head == NULL){
        check1();
    } else {
        if (head == tail){
            head = NULL;
            tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        delete temp;
        current = head;
    }
}

void printNode(){
   int n = 1;
    temp = head;
    clrscr();
    if(head == NULL){
        check1();
    } else {
        do{
            cout << n << ". " << temp->nomor << " | "<< temp->nama << " [ " << temp->prev << " | " << temp << " | " << temp->next << " ]";
            if(temp == current){
                cout << " <- Current Node";
            }
            cout << endl;
            temp = temp->next;
            n++;
        } while(temp != head);
    }
    getch();
}

void upCurrent(){
    if(head != NULL){
        if(current == head){
            check2("Saat ini Current Node ada pada Head");
        } else {
            current = current->prev;
        }
    }
}

void downCurrent(){
    if(head != NULL){
        if(current == tail){
            check2("Saat ini Current Node ada pada Tail");
        } else {
            current = current->next;
        }
    }
}

void positionCurrent(){
    if(head == NULL){
        check1();
    } else {
        tableInput(pading+47, 2, '-', '|', 45, -1, "Masukan posisi current: ", -1, " ", -1, " ", -1, margin, false, true);
        cin >> position;
        if(head != NULL){
            current = head;
            for(int i = 0; i < position-1; i++){
                current = current->next;
            }
        }
    }
}

void addCurrent(){
    allInputDatas(pading+47, 2, subMenuList[2]);
    if(head == NULL){
        head = temp;
        tail = temp;
        current = head;
    } else {
        temp->next = current;
        temp->prev = current->prev;
        current->prev->next = temp;
        current->prev = temp;
        current = temp;
        if (head == current->prev && current->next == head || current->prev == tail){
            tail = current;
        }
    }
}

void deleteCurrent(){
    temp = NULL;
    // apakah data kosong
    if(head == NULL){
        check1();
    } else {
        // jika hanya ada satu data
        if(head == tail){
            head = NULL;
            tail = NULL;
        } else {
            temp = current;
            if(current == head){
                // jika didepan
                head = head->next;
                head->prev = tail;
                tail->next = head;
                current = head;
            } else if(current == tail){
                // jika dibelakang
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
                current = tail;
            } else {
                // jika ditengah
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current = temp->next;
            }
        }
        delete temp;
    }
}

void deleteAll(){
    temp = head;
    if(head == NULL){
        check1();
    } else {
        while(head != NULL){
            deleteLast();
        }
    }
}