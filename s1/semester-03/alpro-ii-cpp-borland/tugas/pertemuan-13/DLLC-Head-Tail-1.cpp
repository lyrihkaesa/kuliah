//=====PROGRAM DLLC HEAD dan TAIL======//

#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>

struct TNode
{
int nopel;
	char nama[20];
   int kel,harga,bulan,biaya,subsidi,ppn,bayar;
	TNode *prev;
	TNode *next;
   TNode *bantu;
};

TNode *head = NULL;
TNode *tail = NULL;

int isEmpty()
{
	if(tail==NULL)
		return 1;
	else
		return 0;
}

void tambahDepan()
{
	TNode *baru;
	baru = new TNode;
   baru = new TNode;
	// masukkan data...........................
   clrscr();
   cout << "Isikan Data Simpul Baru\n";
	cout << "====================================\n";
   // memasukkan data no pelanganggan
	cout << "No Pelanggan : "; cin >> baru->nopel;
   // memasukkan data nama pelanggan
	cout << "Nama 	: "; gets(baru->nama);
   //memasukkan data kelompok pengguna
	cout << "Kelompok [1/2/3]: "; cin >> baru->kel;

   // menentukan harga untuk masing-masing jenis
   if (baru->kel == 1)
   {
		baru->harga = 5000;
 	}
 	else if (baru->kel == 2)
 	{
     baru->harga = 4000;
   }
   else if (baru->kel == 3)
	{
		baru->harga = 3500;
   }
	else
	{
		cout<<"Kelompok Salah!";
	}

   // memasukkan data harga, perbulan
   cout<<"Harga per m3	: "; cout << baru->harga;
   //memasukkan data pemakaian perbulan
   cout<<"\nPemakaian per bulan: "; cin >> baru->bulan;
   //menghitung biaya
 	baru->biaya = baru->harga * baru->bulan;
 	cout<<"Total Biaya:"; cout << baru->biaya;
   cout<<"\nPPN : "; cin >> baru->ppn;
   cout<<"Subsidi: "; cin >> baru->subsidi;
   baru->bayar = baru->biaya - (baru->ppn + baru->subsidi);
   cout<<"Total Bayar: "; cout << baru->bayar;

	baru->prev = baru;
	baru->next = baru;
	cout << endl;

   if(isEmpty()==1)
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
		baru->next = head;
		head->prev = baru;
		head = baru;
		head->prev = tail;
		tail->next = head;
	}
 	cout<<"Data masuk\n";
 	getch();
}

void tambahTengah()
{}

void tambahBelakang()
{
	TNode *baru;
	baru = new TNode;
	baru->next = baru;
	baru->prev = baru;
	clrscr();

   cout << "Isikan Data Simpul Baru\n";
	cout << "====================================\n";
	cout << "No Pelanggan : "; cin >> baru->nopel;
	cout << "Nama : "; gets(baru->nama);
	cout << "Kelompok [1/2/3] : "; cin >> baru->kel;

   if (baru->kel == 1)
   {
		baru->harga = 5000;
 	}
 	else if (baru->kel == 2)
 	{
		 baru->harga = 4000;
   }
   else if (baru->kel == 3)
	{
		baru->harga = 3500;
   }
	else
	{
		cout<<"Kelompok Salah!";
	}

   cout<<"Harga per m3 : "; cout << baru->harga;
   cout<<"\nPemakaian per bulan : "; cin >> baru->bulan;

 	baru->biaya = baru->harga * baru->bulan;
 	cout<<"Total Biaya :"; cout << baru->biaya;

   if (baru->kel == 1)
   {
      baru->ppn = baru->biaya * 3 / 100;
      baru->subsidi = baru->biaya * 5 / 10;
 	}
 	else if ( baru->kel == 2 )
 	{
       baru->ppn = baru->biaya * 2 / 100;
       baru->subsidi = baru->biaya * 3 / 10;
   }
   else if (baru->kel == 3)
	{
      baru->ppn = baru->biaya * 1 / 100;
      baru->subsidi = baru->biaya * 10 /100;
   }

   cout<<"\nPPN : "; cout << baru->ppn;
   cout<<"\nSubsidi : "; cout << baru->subsidi;

   baru->bayar = baru->biaya - (baru->ppn + baru->subsidi);
   cout<<"\nTotal Bayar : "; cout << baru->bayar;

	baru->prev = baru;
	baru->next = baru;
	cout << endl;

 	if(isEmpty()==1)
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
	cout<<"Data masuk\n";
   getch();
}

void hapusDepan()
{
	TNode *hapus;
	int d;
	hapus=head;
	if (isEmpty()==0)
   {
 		if(head != tail)
 		{
 			hapus = head;
 			d = hapus->nopel;
 			head = head->next;
 			tail->next = head;
 			head->prev = tail;
 			delete hapus;
 		}
 		else
 		{
 			d = head->nopel;
 			head = NULL;
 			tail = NULL;
 		}
 		cout<<d<<" terhapus\n";
	}
	else
	cout<<"Masih kosong\n";
}
void hapusTengah()
{}

void hapusBelakang()
{
	TNode *hapus;
	int d;
 	if (isEmpty()==0)
   {
 		if(head != tail)
      {
 			hapus = tail;
 			d = hapus->nopel;
	 		tail = tail->prev;
 			tail->next = head;
 			head->prev = tail;
 			delete hapus;
		}
		else
		{
		   d = head->nopel;
 			head = NULL;
 			tail = NULL;
		}
 		cout<<d<<" terhapus\n";
 	}
 	else
 	cout<<"Masih kosong\n";
}

void tampil()
{
	TNode *baru;
	baru = head;
	if(isEmpty()==0)
   {
 		do
   	{
 			clrscr;
			cout << "\nNo Pelanggan : " << baru->nopel;
			cout << "\nNama : " << baru->nama;
			cout << "\nKelompok : " << baru->kel;
 			cout << "\nHarga per m3 : " << baru->harga;
 			cout << "\nPemakaian per bulan : " << baru->bulan;
 			cout << "\nTotal Biaya : " << baru->biaya;
         cout << "\nPPN :" << baru->ppn;
         cout << "\nSubsidi :" << baru->subsidi;
         cout << "\nTotal Bayar : " << baru->bayar;
         cout << endl;
         cout << endl;

			cout << endl;
 			baru=baru->next;
 		}
 		while(baru!=tail->next);
 		cout<<endl;
 	}
   else cout<<"Masih kosong\n";
 	getch();
}

void clear()
{
	TNode *bantu,*hapus;
	if (isEmpty()==0)
   {
		bantu = head;
		while(bantu->next!=head)
      {
			hapus = bantu;
			bantu = bantu->next;
			delete hapus;
		}
		head = NULL;
	}
}

//program utama ...........................................
void main()
{
	int pilih;
	do
   {
		//Tampilan menu....................................
		clrscr();
		cout << "----------------------------------\n"
		<< " Menu Admin Data Pelenggan Air \n"
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

      switch (pilih)
		{
			case 1:
				tambahDepan();
				break;
         case 2:
				tambahTengah();
				break;
			case 3:
				tambahBelakang();
				break;
 			case 4:
				hapusDepan();
				break;
			case 5:
         	hapusTengah();
				break;
         case 6:
         	hapusBelakang();
				break;
			case 7:
				tampil();
				break;
			default:
				cout << "Pilihan tidak tersedia ! ";
				break;
		}
	}
   while (pilih != 7);
}