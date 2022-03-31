#include <iostream.h> // cin, cout, endl
#include <conio.h> // clrscr(), getche(), getch().
#include <iomanip.h> // setw(), setiosflags()
#include <stdio.h>
#define pading 2
#define margin 2

struct Node{
    int notest, nilai;
    char nama[255];
    Node *next, *bantu;
};

Node *head = NULL;
Node *tail = NULL;
Node *baru;
Node *hapus = head; 
Node *bantu;
int d;
int amountA = 27;
int jumlahData = 0;
int panjangNama = 4;

int lEmpty(){
    if (head == NULL)
        return 1;
    else
        return 0;
}

int panjangHuruf(int a, int b){
    int hasil;
    if(a > b){
        hasil = a;
    } else {
        hasil = b;
    }
    return hasil;
}

// start fungsi modifikasi
void printNodeMenu(int x, int y){
    bantu = head;
    jumlahData = 0;
    if (lEmpty() == 0){
        while (bantu != NULL){
            gotoxy(x, y+jumlahData);
            panjangNama = panjangHuruf(strlen(bantu->nama), panjangNama);
            cout << setw(margin+7) << bantu->notest;
            cout << setw(margin+panjangNama) << bantu->nama;
            cout << setw(margin+5) << bantu->nilai << endl;
            bantu = bantu->next;
            jumlahData = jumlahData + 1;
        }
    } else {
        gotoxy(x, y); cout << "Data Kosong";
    }
}

void garisVertikal(int x, int y, int amount, char c = '|'){
    for (int i = 0; i < amount; i++){
        gotoxy(x, y+i); cout << c;
    }
}

void garisHorizontal(int x, int y, int amount, char c = '-'){
    for(int i = 0; i < amount; i++){
        gotoxy(x+i, y); cout << c;
    }
}

void menuKiri(){
    garisVertikal(amountA, 1, 14);
    garisHorizontal(1, 1, amountA);
    gotoxy(1, 2); cout << " Menu Pilihan (SLLNC) ";
    garisHorizontal(1, 3, amountA);
    char a[10][255] = {" [1] Tambah Depan", 
        " [2] Tambah Belakang",
        " [3] Hapus Depan",
        " [4] Hapus Belakang",
        " [5] Cetak Linked List", 
        " [6] Tambah Depan Baru",
        " [7] Tambah Belakang Baru",
        " [8] Keluar"};

    for (int i = 0; i < 8; i++){
        gotoxy(1, 4+i); cout << a[i];
    }
    garisHorizontal(1, 12, amountA);
    gotoxy(1, 13); cout << " Masukkan pilihan : ";
    garisHorizontal(1, 14, amountA);
}

void menuKanan(){
    int amountB = amountA+pading+1;
    printNodeMenu(amountB+margin, 6);
    if(jumlahData == 0){
        panjangNama = 4;
    }
    int amountC = amountB+20+panjangNama;
    int amountD = 21+panjangNama;
    if(jumlahData == 0){
        garisHorizontal(amountB, 7, amountD);
        garisVertikal(amountB, 1, 6);
        garisVertikal(amountC, 1, 6);
    } else {
        garisHorizontal(amountB, 6+jumlahData, amountD);
        garisVertikal(amountB, 1, 5+jumlahData);
        garisVertikal(amountC, 1, 5+jumlahData);
    }
    garisHorizontal(amountB, 1, amountD);
    garisHorizontal(amountB, 3, amountD);
    gotoxy(amountB+margin, 4);
    cout << setiosflags(ios::left) << setw(margin+7) << "No_Test";
    cout << setw(margin+panjangNama) << "Nama";
    cout << setw(margin+5) << "Nilai";
    garisHorizontal(amountB, 5, amountD);
    gotoxy(amountB+margin, 2);
    cout << "Isi Linked List [" << jumlahData << "]";
}

char field[10][255] = {
    " No_Test : ", 
    " Nama    : ",
    " Nilai   : "};

int amountE = 16, amountF = 12;

void judulTambah(char a[255]){
    garisVertikal(amountA, amountE, 6);
    garisHorizontal(1, amountE, amountA);
    gotoxy(1, amountE+1); cout << a;
    garisHorizontal(1, amountE+2, amountA);
    garisHorizontal(1, amountE+6, amountA);
}

// masukkan data.............................
void masukanData(){
    for (int i = 0; i < 3; i++){
        gotoxy(1, amountE+3+i); cout << field[i];
    }

    garisHorizontal(12, amountE+3, 7, '.');
    garisHorizontal(12, amountE+4, 14, '.');
    garisHorizontal(12, amountE+5, 5, '.');
    
    gotoxy(amountF,amountE+3); cin >>baru->notest;
    gotoxy(amountF,amountE+4); gets(baru->nama);
    gotoxy(amountF,amountE+5); cin >> baru->nilai;
}

void tambahDepanBaru(){
    baru = new Node;
    baru->next = NULL;

    judulTambah(" Tambah Depan Baru");

    masukanData();

    if (lEmpty() == 1){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
    cout << "\n\nData masuk\n";
}

void tambahBelakangBaru(){
    baru = new Node;
    baru->next = NULL;

    judulTambah(" Tambah Belakang Baru");

    masukanData();

    if(lEmpty() == 1){
        head=baru;
    }
    else{
        bantu=head;
        while(bantu->next != NULL){
	        bantu=bantu->next;
        }
        bantu->next = baru;
    }
    cout << "\n\nData masuk\n";
}

// end fungsi modifikasi

void tambahDepan(){
    baru = new Node;
    baru->next = NULL;
    // masukkan data.............................
    clrscr();
    cout << "Isikan Data Simpul Baru\n";
    cout << "==========================================\n";

    cout << "No Test   : "; cin >>baru->notest;
    cout << "Nama      : "; gets(baru->nama);
    cout << "Nilai     : "; cin >> baru->nilai;
    cout << endl;

    if (lEmpty() == 1){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
    cout << "Data masuk\n";
}

void tambahBelakang(){
    // Node *next, *bantu;
    baru = new Node;
    baru->next = NULL;
    // masukkan data.............................
    clrscr();
    cout << "Isikan Data Simpul Baru\n";
    cout << "==========================================\n";

    cout << "No Test   : "; cin >>baru->notest;
    cout << "Nama      : "; gets(baru->nama);
    cout << "Nilai     : "; cin >> baru->nilai;
    cout << endl;

    if(lEmpty() == 1){
        head=baru;
    }
    else{
        bantu=head;
        while(bantu->next != NULL){
	        bantu=bantu->next;
        }
        bantu->next = baru;
    }
    cout << "Data masuk\n";
}

void hapusDepan(){
    // Node *hapus, *tail;
    // hapus = head;
    // int d;
    // jika kosong.........
    if (lEmpty() == 0){
        // jika node lebih dari 1......
        if (head != tail){
            hapus = head;
            d = hapus->notest;
            head = head->next;
            delete hapus;
        } else {
            // jika node hanya 1.......
            d = tail->notest;
            head = tail = NULL;
        }
        cout << "\nData No Test : [" << d << "] terhapus";
    } else {
        cout << "\n Data Masih kosong...";
    }
    getch();
}

void hapusBelakang(){
    // Node *hapus, *tail;
    // hapus = head;
    // int d;

    // jika kosong.........
    if (lEmpty() == 0){
        // jika node lebih dari 1......
        if (head->next != NULL){
            tail = head;
            while(tail->next->next!=NULL){	  
                tail = tail->next;  // geser bantu 		
            }
            hapus = tail->next;
            d = hapus->notest;
            tail->next = NULL;
            delete hapus;

        }
        else{
            // jika node hanya 1.......
            d = tail->notest;
            head = tail = NULL;
        }
        cout << "\nData No Test : [" << d << "] terhapus";
    } else {
        cout << "\n Data Masih kosong...";
    }
    getch();
}

void printNode(){
    bantu = head;
    if (lEmpty() == 0){
        clrscr();
        cout << "\nIsi Linked List\n";
        cout << "==============================\n";
        while (bantu != NULL){
            cout << "No test   : " << bantu->notest;
            cout << ", Nama    : " << bantu->nama;
            cout << ", Nilai   : " << bantu->nilai << endl;
            bantu = bantu->next;
        }
    } else {
        cout << "\n Data Masih Kosong...";
    }
    getch();
}

// program utama.............................
void main(){
    int pilih;
    do{
        // Tampilan Menu...........................
        clrscr();
        menuKiri();
        menuKanan();
        gotoxy(amountA-6, 13); cin >> pilih;
        switch (pilih){
            case 1:
                tambahDepan();
                break;
            case 2:
                tambahBelakang();
                break;
            case 3:
                hapusDepan();
                break;
            case 4:
                hapusBelakang();
                break;
            case 5:
                printNode();
                break;
            case 6:
                tambahDepanBaru();
                break;
            case 7:
                tambahBelakangBaru();
                break;
            default:
                cout << "\n Pilihan tidak tersedia ! ";
                break;
        }
    } while (pilih != 8);
}