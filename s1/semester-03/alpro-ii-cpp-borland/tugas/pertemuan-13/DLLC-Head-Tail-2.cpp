#include <iostream.h>
#include <conio.h>
#include <stdio.h>
	
struct Node
{
int notest;
char nama[20];
int nilai;
Node *prev; 
Node *next;		
};

Node *head = NULL;
Node *tail = NULL;
Node *current = NULL;	

void tambahdepan()
{
Node *temp; 
// masukkan data...........................
temp = new Node;
clrscr();
cout << "Isikan Data Simpul Baru\n";
cout << "====================================\n";
cout << "No Test  : "; cin >> temp->notest;
cout << "Nama     : "; gets(temp->nama);
cout << "Nilai    : "; cin >> temp->nilai;
temp->prev = temp;
temp->next = temp;
cout << endl;

// Set up link to this node........................
if (head == NULL)
{
    head = temp;
    tail = temp;
    current = head;
}
else
{
    temp->next = head;
    head->prev = temp;
    temp->prev = tail;
    tail->next = temp;
    head = temp;
}
} 	

void tambahbelakang()
{
Node *temp; 
// masukkan data...........................
temp = new Node;
clrscr();
cout << "Isikan Data Simpul Baru\n";
cout << "====================================\n";
cout << "No Test  : "; cin >> temp->notest;
cout << "Nama     : "; gets(temp->nama);
cout << "Nilai    : "; cin >> temp->nilai;
temp->prev = temp;
temp->next = temp;
cout << endl;

// Set up link to this node........................
if (head == NULL)
{
    head = temp;
    tail = temp;
}
else
{
    tail->next = temp;
    temp->prev = tail;
    head->prev = temp;
    temp->next = head;
    tail = temp;
}	
}	


void hapusdepan()
{
Node *temp;
temp = head;
// cek apakah kosong, 1 node, atau bbrp node.......
if (head == NULL){
    cout << "\nLinked List Kosong ! [Enter] ";
    getch();
} else {
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
    current = head;
}
} 

void hapusbelakang()
{
Node *temp;
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
    current = head;
}		
}	

void hapuscurrent()
{
Node *temp;
temp = NULL;
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
        //jika didepan.............................
        if (current == head)
        {
            temp = current;
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        //jika dibelakang..........................
        if (current == tail)
        {
            temp = current;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }				
        //jika ditengah.............................
        if ((current != head) && (current != tail))
        {
            temp = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }				
    }
    delete temp;
    current = head;
}		
}

void print_node()
{
Node *temp;
temp = head;

if(temp == NULL) 
    cout << "\nEmpty List !, [Enter]";
else
{
    clrscr();
    cout << "\nIsi Linked List\n";
    cout << "============================\n";
    do
    {
        cout << "No test : " << temp->notest;
        cout << ", nama : " << temp->nama;
        cout << ", nilai : " << temp->nilai;
        if (temp == current)
            cout << " <-- Current Node";
        cout << endl;  
        temp = temp->next; 
    } while(temp != head); 
    cout << "============================\n";
    cout << "[Enter]";
}        
getch();
} 	

void move_current_on()
{ 
if (head != NULL)
{
    if (current == tail)
        cout << "You are at the end of the list." << endl;
    else
        current = current->next;
}
}

void move_current_back()
{ 
if (head != NULL)
{
    if (current == head)
        cout << "You are at the start of the list" << endl;
    else
        current = current->prev;
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
        << " Menu Pilihan (DLLC)\n"
        << "----------------------------------\n"
        << " [1] Tambah Depan \n"
        << " [2] Tambah Belakang \n"
        << " [3] Hapus Depan \n"
        << " [4] Hapus Belakang \n"
        << " [5] Hapus Current \n"
        << " [6] Cetak Linked List \n"
        << " [7] move On \n"
        << " [8] move Back \n"				
        << " [9] Keluar \n\n"
        << "----------------------------------\n"
        << "Masukkan pilihan : "; cin >> pilih;
    switch (pilih)
    {
        case 1:
            tambahdepan();
            break;
        case 2:
            tambahbelakang();
            break;
        case 3:
            hapusdepan();
            break;
        case 4:
            hapusbelakang();
            break;			
        case 5:
            hapuscurrent();
            break;						
        case 6:
            print_node();
            break;		
        case 7:
            move_current_on();
            break;					
        case 8:
            move_current_back();
            break;						
        default:
            cout << "Pilihan tidak tersedia ! ";
            break;
    }
} while (pilih != 9);
}