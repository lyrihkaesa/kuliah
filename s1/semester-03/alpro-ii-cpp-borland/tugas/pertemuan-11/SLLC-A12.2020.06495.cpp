#include <iostream.h> // cin, cout, endl
#include <conio.h> // clrscr(), getche(), getch().
#include <stdio.h>

struct Node{
    int notest, nilai;
    char nama[20];
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void tambahDepan(){
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

void tambahBelakang(){
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

void hapusDepan(){
    Node *temp;
    temp = head;
    // cek apakah kosong, 1 node, atau beberapa node....
    if (head == NULL){
        cout << "\n\nLinked List Kosong ! [Enter] ";
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

void hapusBelakang(){
    Node *temp1, *temp2;
    temp2 = tail;
    // cek apakah kosong, 1 node, atau beberapa node......
    if (head == NULL){
        cout << "\n\nLinked List Kosong ! [Enter] ";
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
        cout << "\n\nEmpty List ! [Enter] ";
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
    int pilih;
    do{
        // tampilan Menu...............................
        clrscr();
        cout << "-----------------------------------------\n"
             << "Menu Pilihan (SLLC)\n"
             << "-----------------------------------------\n"
             << " [1] Tambah Depan \n"
             << " [2] Tambah Belakang \n"
             << " [3] Hapus Depan \n"
             << " [4] Hapus Belakang \n"
             << " [5] Cetak Linked List \n"
             << " [6] Keluar \n"
             << "-----------------------------------------\n"
             << "Masukkan pilihan : "; cin >> pilih;

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