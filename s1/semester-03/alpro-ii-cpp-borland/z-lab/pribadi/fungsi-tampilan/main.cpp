#include <iostream.h> // cin, cout, endl
#include <conio.h> // clrscr(), getche(), getch(), gotoxy()
#include <iomanip.h> // setw(), setiosflags() -> tambahan
// #include <stdio.h>
#define margin 2

int lengthCharMax(int a, int b);
int aData(char inputCHar[255][255]);
int loopLCM(int inputLC, char inputChar[255][255]);
void lineVertical(int x, int y, int amount, char c = '|');
void lineHorizontal(int x, int y, int amount, char c = '-');
void table(int x, int yl, char xc, char yc, char title[255][255], int marginL, bool b = false);
void tableInput(int x, int y, char xc, char yc, int amount, int ld, char lc[255], int md1, char mc[255], int md2, char rc[255], int rd, int marginL, bool b = false);
void tableHD(int x, int y, char title[255][255], int marginL, bool b = false);
char menuLeftList[255][255] = {
        "Modular Title Database In ",
        " ",
        "[1] Tambah dari Depan", 
        "[2] Tambah dari Belakang",
        "[3] Hapus dari Depan",
        "[4] Hapus dari Belakang",
        "[5] Tampil Data", 
        "[6] Tambah dari Tengah",
        "[7] Hapus dari Tengah",
        "[8] Selesai",
        "[9] Belum Selesai"};

void main(){
    tableHD(5, 5, menuLeftList, 4);
    // table(1, 1, '-', '|', menuLeftList, margin);
    // int xR1 = loopLCM(aData(menuLeftList), menuLeftList) + (margin*2)+2;
    // tableInput(1, 1, '=', '|', xR1, 0, menuLeftList[0], 0, " ", 0, " ", 0, margin);
    // table(xR1+3, 1, '-', '|', menuLeftList, margin);
    getch();    
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
void table(int x, int y, char xc, char yc, char title[255][255], int marginL, bool b){
    int amountDatas = aData(title);
    int lLineH1 = loopLCM(amountDatas, title)+(marginL*2)+2;
    int lLineV1 = amountDatas+2;
    int lLineH2 = lLineH1+x-1;
    int lLineV2 = lLineV1+y-1;
    lineVertical(x, y, lLineV1, yc);
    lineVertical(lLineH2, y, lLineV1, yc);
    lineHorizontal(x, y, lLineH1, xc);
    lineHorizontal(x, lLineV2, lLineH1, xc);
    for (int i = 0; i < amountDatas; i++){
        gotoxy(x+marginL+1, y+1+i); cout << title[i];
    }
    if(b){
        lineHorizontal(lLineH2, lLineV2, 1, '?');
        gotoxy(lLineH2+1, lLineV2); cout << " -> (" << lLineH2 << ", " << lLineV2 << ")";
    }
}

// tabel dengan isi tipedata char dan input integer
void tableInput(int x, int y, char xc, char yc, int amount,  int ld, char lc[255], int md1, char mc[255], int md2, char rc[255], int rd, int marginL, bool b){
    int lLineH = x + amount-1;
    int lLineV = y+2;
    lineVertical(x, y, lLineV, yc);
    lineVertical(lLineH, y, lLineV, yc);
    lineHorizontal(x, y, amount, xc);
    lineHorizontal(x, lLineV, amount, xc);
    gotoxy(x+marginL+1, y+1);
    if(ld > 0){
        cout << ld;
    }
    cout << lc;
    if(md1 > 0){
        cout << md1;
    }
    cout << mc;
    if(md2 > 0){
        cout << md2;
    }
    cout << rc;
    if(rd > 0){
        cout << rd;
    }
    if(b){
        lineHorizontal(lLineH, lLineV, 1, '?');
        gotoxy(lLineH+1, lLineV); cout << " -> (" << lLineH << ", " << lLineV << ")";
    }
}

// table dengan isi tipedata char array + judul
void tableHD(int x, int y, char title[255][255], int marginL, bool b){
    table(x, y, '-', '|', title, marginL, b);
    int xR1 = loopLCM(aData(title), title) + (marginL*2)+2;
    tableInput(x, y, '=', '|', xR1, 0, title[0], 0, " ", 0, " ", 0, marginL, b);
}