// contoh program SLLNC dengan Head
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

struct Node{
    int notest, nilai;
    char nama[20];
    Node *next, *bantu;
};
Node *head = NULL;

int lEmpty(){
    if (head == NULL)
        return 1;
    else
        return 0;
}

void tambahDepan(){
    Node *baru;
    baru = new Node;
    // masukkan data............................
    clrscr();
    cout << "Isikan Data Simpul Baru\n";
    cout << "============================================\n";
    cout << "No. Test  : "; cin >> baru->notest;
    cout << "Nama      : "; gets(baru->nama);
    cout << "Nilai     : "; cin >> baru->nilai;
    baru->next = NULL;
    cout << endl;

    // set up link to this node.........................
    if (head == NULL){
        head = baru;
        head->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}

void tambahBelakang(){
    Node *baru, *bantu;
    // masukkan data..................................
    baru = new Node;

    clrscr();
    cout << "Masukkan Data lengkap di bawah ini : " << endl;
    cout << "NIM    : "; cin >> baru->notest;
    cout << "Nama   : "; cin >> baru->nama;
    cout << "Nilai  : "; cin >> baru->nilai;
    baru->next = NULL;
    if (lEmpty() == 1){
        head = baru;
        head->next = NULL;
    }
    else{
        bantu = head;
        while (bantu->next != NULL){
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void hapusDepan(){
    Node *hapus;
    hapus = head;
    int d;
    // cek apakah kosong, 1 node, atau bbrp node....
    if (head == NULL){
        cout << "Linked List Kosong ! [Enter] ";
        getch();
    }
    else{
        // jika lebih dari sebuah node..............
        if (head->next != NULL){
            hapus = head;
            d = hapus->notest;
            head = head->next;
            delete hapus;
        } else {
            // jika hanya 1 node....................
            d = head->notest;
            head = NULL;
        }
        cout << " Data dihapus";
    }
    cout << " Data Kosong";
}

void hapusBelakang(){
    Node *bantu, *hapus;
    int d;
    bantu = head;
        if (lEmpty() == 0){
            if (head->next != NULL){
                bantu = head;
                while (bantu->next->next != NULL){
                    bantu = bantu->next;
                }
                hapus = bantu->next;
                d = hapus->notest;
                bantu->next = NULL;
                delete hapus;
            }
            else{
                d = head->notest;
                head = NULL;
            }
            cout << d << "Sudah terhapus... " << endl;
        }
        else{
            cout << "Data masih kosong..." << endl;
        }
        cout << "Tekan Enter untuk kembali ke Menu!";
        getch();
}

void printNode(){
    Node *bantu;
    bantu = head;

    if (bantu == NULL){
        cout << "Empty List !, [Enter]";
    }
    else{
        clrscr();
        cout << "\nIsi Linked List\n";
        cout << "=============================\n";
        while (bantu != NULL){
            cout << "No test  : " << bantu->notest;
            cout << ", nama   : " << bantu->nama;
            cout << ", nilai  : " << bantu->nilai << endl;
            bantu = bantu->next;
        }
    }
    getch();
}

// program utama.......................................
void main(){
    int pilih;
    do{
        // tampilan menu................................
        clrscr();
        cout << "------------------------------------\n"
             << "Menu Pilihan (SLLNC)\n"
             << " [1] Tambah Depan \n"
             << " [2] Tambah Belakang \n"
             << " [3] Hapus Depan \n"
             << " [4] Hapus Belakang \n"
             << " [5] Cetak Linked List \n"
             << " [6] Keluar \n\n"
             << "------------------------------------\n"
             "Masukkan pilihan : "; cin >> pilih;
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
            default:
                cout << "Pilihan tidak tersedia ! ";
                break;
        }
    } while (pilih != 6);
}