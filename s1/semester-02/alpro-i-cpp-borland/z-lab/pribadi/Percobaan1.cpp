/* program pertukaran */
/* mempertukarkan nilai A dan B, nilai A dan B dibaca terlebih dahulu */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//ini adalah perpustakaan untuk memanggil buku system("cls")&("pause").

main(){
/* DEKLARASI */
int A,B,C;
/* ALGORITMA*/
system("cls"); // clrscr(); ini tidak bisa digunakan jadi saya menggantinya.
printf("A = ");
scanf("%d",&A);
printf("B = ");
scanf("%d",&B);
/* proses pertukaran */
C = A;/* simpan nilai A ke variabel penampung C */
A = B;/* Isi nilai variabel A dengan nilai variabel B */
B = C;/* Isi nilai variabel B dengan nilai variabel C (C berisi Nilai semula A *
/* tulis nilai setelah pertukaran */
printf("A = %d \n",A);
printf("B = %d \n",B);
system("pause"); //getch(); ini tidak bisa digunakan jadi saya menggantinya.
}
