#include <iostream> // MinGW - cin(), cout(), << endl;
using namespace std; // << kode ini untuk <iostream> untuk MinGW.
#include <iostream.h> // Borland - cin(), cout(), << endl;
#include <conio.h> // Borland - getch(), getche(), clrscr(), gotoxy()
#include <stdio.h> // Borland - gets(), printf(), scanf()
#include <stdlib.h> // MinGW - system("pause"), system("cls")
#include <windows.h> // MinGW - gotoxy() << Membuat secara manual;
#include <string.h> // Borland - strcpy(), strlen(), strcmp()

gotoxy(x,y); // borland:conio.h - fungsi atau prosedur untuk memposisikan kursor berdasarkan (X,Y), X pada horizontal, dan Y pada vertikal relatif terhadap "jendela asal saat ini (origin of the current windows)"
// MinGW:windows.h - dibawha ini awal kodingan manual untuk gotoxy().
COORD coord = {0,0};
void gotoxy(int x, int y) {
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// akhir kodingan manual untuk gotoxy().

getch(); // borland:conio.h - memberitahu konsol menunggu (pause) beberapa saat sampai tombol keyboard ditekan atau menghentikan program sementara sampai tombol keybord ditekan.
system("pause"); // MinGW:stdlib.h - sama dengan fungsi getch();
cin.get(variabel, panjangChar); // MinGW:iostream | Borland:iostream.h - sama dengan fungsi getch();
clrscr(); // borland:conio.h - [clrscr] clear screen digunakan untuk menghapus layar konsol (console screen).
system("cls"); // MinGW:stdlib.h - sama dengan fungsi clrscr().
cin >> variabel; // borland:iostream.h | MinGW:iostream - masukan data (input data), tapi untuk tipe data char tidak boleh ada "spasi" saat memasukan data.
cout << variabel << "huruf/kata/kalimat"; // borland:iostream.h | MinGW:iostream - mengeluarkan data (output data).
cout << endl << "\n"; // borland:iostream.h | MinGW:iostream - endl (end line) atau "\n" {sama seperti "enter" pada tombol keyboard atau (new line) baris baru}.
cout << "\t"; // borland:iostream.h | MinGW:iostream - "\t" {sama seperti "tab" pada tombol keyboard}
gets(variabel); // borland:stdio.h - memasukan tipe data char dengan "spasi".
char variabel[panjangChar]; // untuk cin.getline(variabel, panjangChar);
cin.ignore(); // dibutuhkan cin.getline() untuk menghapus "\n" pada fungsi cin, jika tidak akan error saat input data, berikan diatasnya kodingan cin.getline().
cin.getline(variabel, panjangChar); // MinGW:iostream sama dengan gets() - memasukan tipe data char dengan "spasi".

// MinGW:Main Program
int main(){
	// masukan kodingan
	return 0; // return 0 supaya program berhenti dengan baik.
};

// Borland:Main Program
#include <conio.h>
void main(){
	// masukan kodingan
	getch(); // butuh conio.h
};

// Menghitung Jumlah Huruf (Jumlah Character) yang dimasukan
int jumlahHuruf(const char *temp){
    int x = 0;
    for( ;*temp != '\0'; temp++) ++x;
    return x;

}

strcpy(variabel_tujuan, "string"); // borland:string.h - menyalin string ke variabel_tujuan.
strlen(variabel); // borland:string.h - Menghitung jumlah huruf (lenght character).
strcmp(string1, string2); // borland:string.h - Membandingkan dua string hasil true or false.