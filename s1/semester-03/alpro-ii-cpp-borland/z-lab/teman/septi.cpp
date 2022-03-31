#include <iostream.h>
#include <conio.h>
#include <stdio.h>

#define MAX 10
#define garisMinus "-----------------------------------\n"

int antrian[MAX];
int front =-1;
int rear = -1;

//cek apakah antrian penuh..................
bool isFull(){
     if ((front == rear + 1) || (front == 0 && rear == MAX - 1)) {
       return true;
    }
    else
       return false;
}

//cek apakah antrian kosong.................
bool isEmpty(){
    return front == -1;
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

        if (front == -1)
            front = 0;

        rear = (rear + 1) % MAX;
        antrian[rear] = xantrian;
    }
}

//mengambil data dari antrian..............
void dequeue(){
     int xdequeue;
    if (isEmpty())
    {

        cout << "\nAntrian masih kosong ! ";
    }
    else{
        xdequeue = antrian[front];
        antrian[front] = 0;
        if (front == rear) {
            rear = -1;
        }
        else {
             front = (front + 1 ) % MAX;
        }
        cout << "\nMengambil antrian \"" << xdequeue << "\"";
        cout << endl;
     }
     getch();
}


//menampilkan isi antrian......................
void printQueue() {
    if (isEmpty()){
        cout << "\nAntrian kosong ! ";
    }
    else{
        cout << "Kondisi Antrian : \n\n";
        cout << " ==== | ";
        for (int i = MAX-1; i >= 0; i--){
            if (antrian[i] == 0){
                cout << " | ";
            }
            else{
                cout << antrian[i] << " | ";
            }
        }
        cout << " ==== \n";
        cout << "Front = " << front << endl;
        cout << "Rear = " << rear << endl;
        cout << "\nEnter kembali  ke menu ";
        }
        getch();
}

//program utama..........................
void main(){
    int pilih;
    do{
        //Tampilan menu..................
        clrscr();
        cout << "------------------------------------------\n";
        cout << "Menu Pilihan circulr Queue\n";
        cout << "------------------------------------------\n";
        cout << "[1] Enqueue / Tambah Antrian \n";
        cout << "[2] Denqueue / Hapus Antrian \n";
        cout << "[3] Print Dequeue / Cetak Antrian \n";
        cout << "[4] Exit / Keluar \n\n";
        cout << "------------------------------------------\n";
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
    } while (pilih != 4);
}