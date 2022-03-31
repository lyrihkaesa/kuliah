#include <iostream.h>
#include <conio.h>
#include <stdio.h>

#define MAX 10
#define garisMinus "-----------------------------------\n"

int antrian[MAX];
int rear = -1;

//cek apakah antrian penuh..................
bool isFull(){
    return rear == MAX-1;
}

//cek apakah antrian kosong.................
bool isEmpty(){
    return rear ==-1;
}

//menambahkan data ke antrian...............
void enqueue(){
    if (isFull()){
        cout << "\nAntrian penuh ! ";
        getch();
    }
    else{
        int xantrian;
        cout << "\nMasukkan antrian : "; cin >> xantrian;
        rear++;
        antrian[rear] = xantrian;
    }
}

//mengambil data dari antrian..............
void dequeue(){
    if (isEmpty()){
        cout << "\nAntrian masih kosong ! ";
    }
    else{
        cout << "\nMengambil antrian \"" << antrian[0] << "\"" << endl;

        //menggeser data antrian...........
        for (int i = 0; i < rear; i++){
            antrian [i] = antrian [i + 1];
        }
        antrian[rear] = 0;
        rear--;
    }
    getch();
}

//menampilkan Queue.......................
void printQueue(){
    if (isEmpty()){
        cout << "\nAntrian kosong ! ";
    }
    else{
        cout << "Kondisi Antrian : \n\n";
        cout << "masuk => | ";
        for (int i = MAX-1; i >= 0; i--){
            if (antrian[i] == 0){
                cout << " | ";
            }
            else{
                cout << antrian[i] << " | ";
            }
        }
        cout << "=> keluar ";
        cout << "\n\nEnter kembali ke Menu ";
        getch();
    }
}

//program utama..........................
void main(){
    int pilih;
    do{
        //Tampilan menu..................
        clrscr();
        cout << garisMinus;
        cout << "Menu Pilihan\n";
        cout << garisMinus;
        cout << "[1] Enqueue / Tambah Antrian \n";
        cout << "[2] Denqueue / Hapus Antrian \n";
        cout << "[3] Print Dequeue / Cetak Antrian \n";
        cout << "[4] Exit / Keluar \n\n";
        cout << garisMinus;
        cout << "Masukkan pilihan : "; cin >> pilih;
        switch (pilih){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQueue();
                break;
            default:
                cout << "Pilihan tidak tersedia ! ";
                break;
        }
    }while (pilih != 4);
}