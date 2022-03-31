//Ujian Akhir Semester Praktik
//Nama      : Faustina Maureen Widjojo
//NIM       : A12.2020.06526
//Kelompok  : A12.6305

//Program DLLC Transaksi Restaurant

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int pil;
void pilih();
void buat_baru();
void tambah_belakang();
void tambah_depan();
void hapus_belakang();
void hapus_depan();
void tampil();
void tambah_tengah();
void hapus_tengah();

struct TNode{
    char nopel[5];
    char nama[20];
    int klp, harga, bulan, biaya, subsidi, ppn, bayar;
    TNode *prev;
    TNode *next;
};

TNode *head = NULL;
TNode *tail = NULL;
TNode *baru;

int main(){
	int pilih;
	do {
		//Tampilan menu....................................
		system("CLS");
		cout << "----------------------------------\n"
		<< " Menu Admin Data Pelanggan Air \n"
        << " Dengan Double Link List Circular \n"
		<< "----------------------------------\n"
		<< " [1] Tambah dari Depan \n"
        << " [2] Tambah dari Tengah \n"
        << " [3] Tambah dari Belakang \n"
		<< " [4] Hapus dari Depan \n"
		<< " [5] Hapus dari Tengah \n"
        << " [6] Hapus dari Belakang \n"
        << " [7] Tampil semua Data \n"
		<< " [8] Selesai \n\n"
		<< "----------------------------------\n"
		<< "Masukkan pilihan : "; cin >> pilih;

        switch (pilih){
            case 1:
                tambah_depan();
                break;
            case 2:
                tambah_tengah();
                break;
            case 3:
                tambah_belakang();
                break;
            case 4:
                hapus_depan();
                break;
            case 5:
                hapus_tengah();
                break;
            case 6:
                hapus_belakang();
                break;
            case 7:
                tampil();
                break;
            default:
                return 0;
                break;
		}
	} while (pilih != 8);
    getch();
	return 0;
}

void buat_baru(){
	baru = new TNode;
	system("CLS");

    cout << "====================================\n";
    cout << "        Input Data Pelanggan\n";
    cout << "====================================\n";
    cout << "Nomor Pelanggan        : "; cin >> baru->nopel;                                         //menginputkan data nomor pelanggan
    cout << "Nama                   : "; cin >> baru->nama;                                          //menginputkan data nama pelanggan
    cout << "Kelompok [1/2/3]       : "; cin >> baru->klp;                                           //menginputkan kelompok pelanggan
    
//     if(baru->klp == 1)                                          //membuat kondisi apabila kelompok pelanggan adalah 1
//     {
//         baru->harga = 5000;                                     //maka untuk variabel harga adalah 5000
//     }
//     else if(baru->klp == 2)                                     //jika kode pelanggan adalah 2
//     {
//         baru->harga = 4000;                                     //maka untuk variabel harga adalah 4000
//     }
//     else if(baru->klp == 3)                                   //jika kode pelanggan adalah 3
//     {
//         baru->harga = 3500;                                     //maka untuk variabel harga adalah 3500
//     }
//     else                                                        //jika kondisi 1,2,3 tidak terpenuhi
//     {
//         cout << "Input kelompok tidak valid!";                  //maka akan menampilkan pesan "Input kelompok tidak valid!"
//     };
//     cout << "Harga per m3           : ";
//     cout << baru->harga;                                        //menampilkan harga per m3
//     cout << "\nPemakaian per bulan    : ";
//     cin >> baru->bulan;                                         //menginputkan pemakaian perbulan
//     cout << endl;
//     //menghitung biaya
//     baru->biaya = baru->harga * baru->bulan;
//     cout << "Total Biaya    : ";
//     cout << baru->biaya;
//         if (baru->klp == 1)
//    {
//       baru->ppn = baru->biaya * 3 / 100;
//       baru->subsidi = baru->biaya * 5 / 10;
//  	}
//  	else if ( baru->klp == 2 )
//  	{
//        baru->ppn = baru->biaya * 2 / 100;
//        baru->subsidi = baru->biaya * 3 / 10;
//    }
//    else if (baru->klp == 3)
// 	{
//       baru->ppn = baru->biaya * 1 / 100;
//       baru->subsidi = baru->biaya * 10 /100;
//    }
//     cout << "\nPPN            : ";
//     cout << baru->ppn;
//     cout << "\nSubsidi        : ";
//     cout << baru->subsidi;
//     cout << "\n                 ---------------- ";
//     baru->bayar = baru->biaya - (baru->ppn + baru->subsidi);
//     cout << "\nTotal Bayar     : ";
//     cout << baru->bayar;

	baru->prev = baru;
    baru->next = baru;
}

int isEmpty(){
	if(head==NULL)
        return 1;
	else
        return 0;
}

 void tambah_depan(){
    system("CLS");
    buat_baru();
    if(head == NULL) {
 		head=baru;
 		tail=baru;
 //		head->next = head;
 //		head->prev = head;
 //		tail->next = tail;
 //		tail->prev = tail;
    } else {
		baru->next = head;
		head->prev = baru;
		baru->prev = tail;
		tail->next = baru;
		head = baru;
	}
 	cout<<"\nData berhasil diinputkan ke sistem!\n";
 	getch();
 }

 void tambah_tengah()
 {
    TNode *baru, *bantu, *bantu2;
    system("CLS");
    int sisip;
    if(head != NULL)
    {
        cout << "Posisi sisip : ";
        cin >> sisip;
    baru->next = NULL;
    baru->prev = NULL;
    bantu = head;
    for (int i=1; i<sisip-1; i++)
    {
        bantu = bantu->next;
    }

    baru->prev = baru;
	baru->next = baru;
	cout << endl;

	buat_baru();

    bantu2 = bantu->next;
    baru->next = bantu2;
    bantu2->prev = baru;
    bantu->next = baru;
    baru->prev = bantu;
    }
        else
    {
        cout <<"\nBelum ada data pada sistem!"<<endl;
    }
    cout << endl;
    getch();
 }

void tambah_belakang()
 {
    TNode *baru;
	baru->next = baru;
	baru->prev = baru;
	system("CLS");
     buat_baru();
     if(head == NULL)
 	{
		head=baru;
 		tail=baru;
 		head->next = head;
 		head->prev = head;
 		tail->next = tail;
 		tail->prev = tail;
 	}
	else
    {
        tail->next = baru;
 		baru->prev = tail;
 		tail = baru;
 		tail->next = head;
 		head->prev = tail;
	}
	cout<<"\nData masuk\n";
    getch();
 }

void hapus_depan()
{
		TNode *temp, *baru;
		temp = head;
		// cek apakah kosong, 1 node, atau bbrp node.......
		if (head == NULL)
		{
			cout << "\nLinked List Kosong ! [Enter] ";
			getch();
		}
		else
		{
			//jika ada sebuah node.........................
			if(head == tail)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				//jika node lebih dari 1...................
				head = head->next;
				head->prev = tail;
				tail->next = head;
			}
			delete temp;
			baru = head;
			cout << "Data Depan Terhapus!";
			getch();
		}
}

void hapus_tengah()
{
    TNode *baru, *bantu, *bantu2, *hapus;
    int sisip;
    hapus = head;
    if(head != NULL)
    {
        cout << "Posisi sisip : ";
        cin >> sisip;
    baru = new TNode;
    baru->next = NULL;
    baru->prev = NULL;
    bantu = head;
    for (int i=1; i<sisip-1; i++)
    {
        bantu = bantu->next;
    }
    hapus=bantu->next;
    bantu2=hapus->next;
    bantu->next=hapus->next;
    bantu2->prev=bantu;
    delete hapus;
    cout << "Data " << sisip << " Terhapus!\n";
    getch();
    }
}


void hapus_belakang()
{
	TNode *temp, *baru;
		temp = tail;
		// cek apakah kosong, 1 node, atau bbrp node.......
		if (head == NULL)
		{
			cout << "\nLinked List Kosong ! [Enter] ";
			getch();
		}
		else
		{
			//jika ada sebuah node.........................
			if(head == tail)
			{
				head = NULL;
				tail = NULL;

			}
			else
			{
				//jika node lebih dari 1...................
				tail = tail->prev;
				tail->next = head;
				head->prev = tail;
			}
			delete temp;
			baru = head;
			cout << "Data Belakang Terhapus!" <<endl;
}
getch();
}



void tampil(){
    TNode *temp;
    temp = head;
	if(head == NULL){
        cout << "\nData Kosong! [ENTER]";
    } else {
        // system("CLS");
        cout << "\nIsi Linked List\n";
        cout << "===================\n";
        do
        {
            cout << "\nNo Pelanggan : " << temp->nopel;
            cout << "\nNama : " << temp->nama;
            cout << "\nKelompok : " << temp->klp;
            cout << "\nHarga per m3 : " << temp->harga;
            cout << "\nPemakaian per bulan : " << temp->bulan;
            cout << "\nTotal Biaya : " << temp->biaya;
            cout << "\nPPN :" << temp->ppn;
            cout << "\nSubsidi :" << temp->subsidi;
            cout << "\nTotal Bayar : " << temp->bayar;
            cout <<endl;
            temp = temp->next;
        } while(temp != head);
        cout << "==================================\n";
        cout << "[ENTER]";
    }
    getch();
}
