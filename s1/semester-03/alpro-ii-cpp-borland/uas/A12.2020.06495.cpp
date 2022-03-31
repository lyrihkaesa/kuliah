// NIM      : A12.2020.06495
// Nama     : Kukuh Setya Arumansyah
// Kelompok : A12.6306
// Jika kurang lengkap saat "tampilkan data"
// Silahkan "ubah tampilan" ke 1 atau 2, defaultnya = 0.

#include <iostream.h> // cin, cout, endl
#include <conio.h> // clrscr(), getche(), getch(), gotoxy()
#include <iomanip.h> // setw(), setiosflags() -> tambahan
#include <stdio.h> // gets()
// #include <cmath.h> // jika error compillernya silahkan diaktifkan yang ini.
#define margin 2

// Source Code version 2.0.0

// default tampilan
int theme = 0;

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
        "Menu Admin Data Pelanggan Air (DLLC)",
        " ",
        "[1]  + Tambah Data dari Depan", 
        "[2]  + Tambah Data pada Current",
        "[3]  + Tambah Data dari Belakang",
        "[4]  x Hapus Data dari Depan",
        "[5]  x Hapus Data Current", 
        "[6]  x Hapus Data dari Belakang",
        "[7]  p Tampil Semua Data",
        "[8]  ^ Current Pindah Ke-Atas",
        "[9]  ^ Current Pindah Ke-Bawah",
        "[10] o Current Pindah Tertentu",
        "[11] x Hapus Semua Data",
        "[12] $ Ubah Tampilan",
        "[13] ! Keluar"
};

char subMenuList[255][255] = {
    "Tambah Data dari Depan",
    "Tambah Data dari Belakang",
    "Tambah Data pada Current",
};

char textInputDatas[255][255] = {
    "No Pelanggan        : ",
    "Nama                : ",
    "Kelompok [1/2/3]    : ",
    "Harga per m^3       : ",
    "Pemakaian Per Bulan : ",
    " ",
    "Total Biaya         : ",
    "PPN                 : ",
    "Subsidi             : ",
    " ",
    "Total Bayar         : ",
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

void dotNum(int x, int y, int amountDot, int amountSpace, int &value, int option1, int option2);
void dotChar(int x, int y, int amountDot, int amountSpace, char (& value)[255], unsigned int option1, unsigned int option2);
void changeTheme();

int costPerM3(int lGroup);
int totalCost(int lCostPerM3, int lCostPerMounth);
int ppn(int lGroup, int lTotalCost);
int subsidi(int lGroup, int lTotalCost);
int totalPay(int lTotalCost, int lPpn, int lSubsidi);

struct Node{
    char noPelanggan[255], nama[255];    
    int group, monthUse;
    int oCostPerM3, oTotalCost, oPpn, oSubsidi, oTotalPay;
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
        tableInput(pading, 18, '-', '|', 42, -1, "Masukan Pilihan Menu: ", -1, " ", -1, " ", -1, margin, false, true);
        cin >> select;
        switch (select){
            case 1:
                addFirst();
                break;
            case 2:
                addCurrent();
                break;
            case 3:
                addLast();
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteCurrent();
                break;
            case 6:
                deleteLast();
                break;
            case 7:
                printNode();
                break;
            case 8:
                upCurrent();
                break;
            case 9:
                downCurrent();
                break;
            case 10:
                positionCurrent();
                break;
            case 11:
                deleteAll();
                break;
            case 12:
                changeTheme();
                break;
            default:
                break;
        }
    } while (select != 13);
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
    tableInput(pading+47, 10, '-', '|', 45, -1, "Linked List Masih Kosong", -1, " ", -1, " ", -1, margin, false, false);
    getch();
}

void check2(char c[255]){
    tableInput(pading+47, 10, '-', '|', 45, -1, c, -1, " ", -1, " ", -1, margin, false, false);
    getch();
}

void inputDatas(int x, int y, char title[255][255]){
    temp = new Node;
    int amountDataTitles = aData(title);
    int lText = loopLCM(amountDataTitles, title);
    int lText1 = lText + 1;

    lineHorizontal(x-2, y+5, 50, '-');
    lineHorizontal(x-2, y+9, 50, '-');
    // ----- Masukan variabel masukan -----
    // No Pelanggan
    dotChar(x+lText1, y, 5, 20, temp->noPelanggan, 1, 5);
    // gotoxy(x+lText1, y); gets(temp->noPelanggan);
    
    // Nama Pelanggan
    dotChar(x+lText1, y+1, 23, 23, temp->nama, 5, 24);
    // gotoxy(x+lText1, y+1); gets(temp->nama);

    // Kelompok [1/2/3]
    dotNum(x+lText1, y+2, 1, 20, temp->group, 1, 3);
    // gotoxy(x+lText1, y+2); cin >> temp->group;

    // Harga per m^3
    temp->oCostPerM3 = costPerM3(temp->group);
    gotoxy(x+lText1, y+3); cout << temp->oCostPerM3;

    // Pemakaian Per Bulan
    dotNum(x+lText1, y+4, 4, 24, temp->monthUse, 1, 9999);
    // gotoxy(x+lText1, y+4); cin >> temp->monthUse;

    // Total Biaya
    temp->oTotalCost = totalCost(temp->oCostPerM3, temp->monthUse);
    gotoxy(x+lText1, y+6); cout << temp->oTotalCost;

    // PPN
    temp->oPpn = ppn(temp->group, temp->oTotalCost);
    gotoxy(x+lText1, y+7); cout << temp->oPpn;

    // Subsidi
    temp->oSubsidi = subsidi(temp->group, temp->oTotalCost);
    gotoxy(x+lText1, y+8); cout << temp->oSubsidi;

    // Total Bayar
    temp->oTotalPay = totalPay(temp->oTotalCost, temp->oPpn, temp->oSubsidi);
    gotoxy(x+lText1, y+10); cout << temp->oTotalPay;

    temp->prev = temp;
    temp->next = temp;
    
    // Pause
    getch();
}

void printInputDatas(int x, int y, char title[255], char subTitle[255][255], int marginL, int b, int amount){
    table(x, y+2, '-', '|', subTitle, marginL, b, amount);
    tableInput(x, y, '=', '|', amount, -1, title, -1, " ", -1, " ", -1, margin, b);
}

void allInputDatas(int x, int y, char title[255]){
    printInputDatas(x, y, title, textInputDatas, margin, false, 50);
    inputDatas(x+margin, y+3, textInputDatas);
}

void tablePrintDatas(int x, int y, int marginL, bool b){
    int lengthName = 4;
    int lLineH1 = x+marginL+1;
    int lLineV1 = y+4;
    int addionalLenght;
    int pcn = (marginL*3)+(8*3);
    if(theme == 1){
        addionalLenght = (marginL*7)+3+9+12+11+7+7+11;
    } else if(theme == 2){
        addionalLenght = (marginL*7)+3+9+12+11+7+7+11+pcn;
    } else {
        addionalLenght = (marginL*2)+3+11;
    }
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
            int ll = lLineH1+(marginL*5)+12+lengthName+addionalLenght;
            int ly = lLineV1+1+amountDatas;
            gotoxy(lLineH1, ly);
            cout << setiosflags(ios::left)
                << setw(marginL+2) << (amountDatas+1)
                << setw(marginL+12) << temp->noPelanggan
                << setw(marginL+lengthName) << temp->nama
                << setw(marginL+3) << temp->group;
            if(theme == 1 || theme == 2){
                cout << setw(marginL+9) << temp->oCostPerM3
                    << setw(marginL+12) << temp->monthUse
                    << setw(marginL+11) << temp->oTotalCost
                    << setw(marginL+7) << temp->oPpn
                    << setw(marginL+7) << temp->oSubsidi;
                }
                cout << setw(marginL+11) << temp->oTotalPay;
            if(theme == 2){
                cout << setw(marginL+8) << temp->prev
                    << setw(marginL+8) << temp
                    << setw(marginL+8) << temp->next;
            }

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

    int al = (marginL*5)+2+12+lengthName+addionalLenght;
    gotoxy(lLineH1, y+3);
    cout << setiosflags(ios::left)
        << setw(marginL+2) << "No"
        << setw(marginL+12) << "No_Pelanggan"
        << setw(marginL+lengthName) << "Nama"
        // tambahan 7
        << setw(marginL+3) << "Klp";
    if(theme == 1 || theme == 2){
    cout << setw(marginL+9) << "Harga/M^3"
        << setw(marginL+12) << "Pemakaian/MM"
        << setw(marginL+11) << "Total_Biaya"
        << setw(marginL+7) << "PPN"
        << setw(marginL+7) << "Subsidi";
    }
    cout << setw(marginL+11) << "Total_Bayar";
        // tambahan 3
    if(theme == 2){
        cout << setw(marginL+8) << "Preview"
            << setw(marginL+8) << "Now"
            << setw(marginL+8) << "Next";
    }

    if(amountDatas == 0){
        lineVertical(x, y, 7);
        lineVertical(al+2, y, 7);
        lineHorizontal(x, lLineV1+2, al);
        if(b){
            lineHorizontal(x+al-1, lLineV1+2, 1, '?');
            gotoxy(x+al, lLineV1+2); cout << " -> (" << (x+al-1) << ", " << (lLineV1+2) << ", " << al << ")";
        }
    } else {
        lineVertical(x, y, 5+amountDatas);
        lineVertical(al+2, y, 5+amountDatas);
        lineHorizontal(x, lLineV1+1+amountDatas, al);
        if(b){
            lineHorizontal(x+al-1, lLineV1+1+amountDatas, 1, '?');
            gotoxy(x+al, lLineV1+1+amountDatas); 
            cout << " -> (" << (x+al-1) << ", "  << (lLineV1+1+amountDatas) << ", " << al << ")";
        }
    }
    lineHorizontal(x, lLineV1, al, '=');
    tableInput(x, y, '=', '|', al, -1, "Isi Linked List: ", amountDatas, " | ", -1, " Mode Tampilan: ", theme, marginL, b, false);
    if(b){
        lineHorizontal(x+al-1, lLineV1, 1, '?');
        gotoxy(x+al, lLineV1); 
        cout << " -> (" << (x+al-1) << ", " << lLineV1 << ", " << al << ")";
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
    clrscr();
    int tempTheme;
    tempTheme = theme;
    theme = 1;
    tablePrintDatas(pading, 1, margin);
    // int n = 1;
    // temp = head;
    // if(head == NULL){
    //     check1();
    // } else {
    //     do{
    //         cout << n << ". " 
    //             << temp->noPelanggan << " | "
    //             << temp->nama << " | "
    //             << temp->group << " | "
    //             << temp->oCostPerM3 << " | "
    //             << temp->oTotalCost << " | "
    //             << temp->oPpn << " | "
    //             << temp->oSubsidi << " | "
    //             << temp->oTotalPay;
    //             // << " [ " 
    //             // << temp->prev << " | " 
    //             // << temp << " | " 
    //             // << temp->next << " ]";
    //         if(temp == current){
    //             cout << " <- Current Node";
    //         }
    //         cout << endl;
    //         temp = temp->next;
    //         n++;
    //     } while(temp != head);
    // }
    getch();
    theme = tempTheme;
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


// fungsi tambahan pengecekan

void dotNum(int x, int y, int amountDot, int amountSpace, int &value, int option1, int option2){
    do {
        lineHorizontal(x, y, amountDot, '.');
        if(value < option1 || value > option2){
            lineHorizontal(x+amountDot, y, amountSpace-amountDot, ' ');
        }
        gotoxy(x, y); cin >> value;
    } while (value < option1 || value > option2);
}

void dotChar(int x, int y, int amountDot, int amountSpace, char (& value)[255], unsigned int option1, unsigned int option2){
     do {
        lineHorizontal(x, y, amountDot, '.');
        if(strlen(value) < option1 || strlen(value) > option2){
            lineHorizontal(x+amountDot, y, amountSpace-amountDot, ' ');
        }
        gotoxy(x, y); gets(value);
    } while (strlen(value) < option1 || strlen(value) > option2);
}

void changeTheme(){
    tableInput(pading+47, 2, '-', '|', 45, -1, "Masukan pilihan tampilan: ", -1, " ", -1, " ", -1, margin, false, true);
    cin >> theme;
}

// Fungsi proses

int costPerM3(int lGroup){
    if(lGroup == 1){
        return 5000;
    } else if(lGroup == 2){
        return 4000;
    } else if(lGroup == 3){
        return 3500;
    } else {
        return 0;
    }
}

int totalCost(int lCostPerM3, int lCostPerMounth){
    return lCostPerM3 * lCostPerMounth;
}

int ppn(int lGroup, int lTotalCost){
    if(lGroup == 1){
        // return ceil(lTotalCost * 0.03);
        // return lTotalCost * 0.03;
        return lTotalCost * 3/100;
    } else if(lGroup == 2){
        // return lTotalCost * 0.02;
        return lTotalCost * 2/100;
    } else if(lGroup == 3){
        // return lTotalCost * 0.01;
        return lTotalCost * 1/100;
    } else {
        return 0;
    }
}

int subsidi(int lGroup, int lTotalCost){
    if(lGroup == 1){
        return lTotalCost * 50/100;
        // return lTotalCost * 0.5;
    } else if(lGroup == 2){
        return lTotalCost * 30/100;
        // return lTotalCost * 0.3;
    } else if(lGroup == 3){
        return lTotalCost * 10/100;
        // return lTotalCost * 0.1;
    } else {
        return 0;
    }   
}

int totalPay(int lTotalCost, int lPpn, int lSubsidi){
    return lTotalCost-(lPpn+lSubsidi);
}