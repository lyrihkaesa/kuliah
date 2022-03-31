#include <stdio.h>
#include <conio.h>
#include <iostream.h>

struct Node{
		  int data;
		  Node *kiri;
		  Node *kanan;
   };

void tambah(Node **root,int databaru){
  if((*root) == NULL){
		Node *baru;
		baru = new Node;
		baru->data = databaru;
		baru->kiri = NULL;
		baru->kanan = NULL;
		(*root) = baru;
		(*root)->kiri = NULL;
		(*root)->kanan = NULL;
		printf("Data bertambah!");
	}
   else if(databaru < (*root)->data)
		tambah(&(*root)->kiri,databaru);
	else if(databaru > (*root)->data)
		tambah(&(*root)->kanan,databaru);
	else if(databaru == (*root)->data)
		printf("Data sudah ada!");
}

void inOrder(Node *root){
	if(root != NULL){
		inOrder(root->kiri);
		printf("%d ",root->data);
		inOrder(root->kanan);
	}
}

void preOrder(Node *root){
	if(root != NULL){
		printf("%d ",root->data);
		preOrder(root->kiri);
		preOrder(root->kanan);
	}
}


void postOrder(Node *root){
	if(root != NULL){
		postOrder(root->kiri);
		postOrder(root->kanan);
		printf("%d ",root->data);
	}
}

void main(){
	int pil,c;
	Node *pohon,*t;
	pohon = NULL;

do{
		clrscr();
		int data;
		cout<<"MENU\n";
		cout<<"1. Tambah\n";
		cout<<"2. Lihat in-order\n";
		cout<<"3. Lihat pre-order\n";
		cout<<"4. Lihat post-order\n";
		cout<<"5. Exit\n";
		cout<<"Pilihan : ";
      cin>>pil;
		switch(pil){
			case 1:  cout<<"Data baru : ";
         	cin>>data;
				tambah(&pohon,data);
				break;
			case 2:
         if(pohon!=NULL)
            inOrder(pohon);
			else
         cout<<"Masih kosong!";
			break;
			case 3:
         if(pohon!=NULL)
             preOrder(pohon);
			else
             cout<<"Masih kosong!";
					break;
			case 4:
         if(pohon!=NULL)
         	postOrder(pohon);
				else
            cout<<"Masih kosong!";
					break;
		}
		getch();
	}while(pil!=5);
}