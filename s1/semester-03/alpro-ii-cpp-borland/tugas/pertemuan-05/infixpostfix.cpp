/*
 Nama Anggota Kelompok:
 1. 06476 Farhan Taqi Abdussalam 
 2. 06492 Andreas Marcelino Andriawan
 3. 06495 Kukuh Setya Arumansyah
*/


// header program.....................................
#include <iostream.h> // cout(), cin(), endl
#include <conio.h> // getch(), 
#include <stdio.h> // gets(), getchar()
#include <stdlib.h> // exit()
#include <ctype.h> // isdigit(), isalpha()
#include <string.h> // strcat()

#define SIZE 100 // konstanta "SIZE" yang mendefinisikan maksimum panjang karakter (max lenght char) dengan nilai 100.

char stack[SIZE]; // variabel dengan tipe data char dengan nama stack yang dapat di isi dengan maksimal panjang karakter 100, digunakan sebagai wadah data tumpukan.
int top = -1; // variabel dengan tipe data integer (bilangan bulat) dengan nama top (atas) yang bernilai -1, dimana top = -1 adalah kodisi tumpukan masih kosong.

// define push operation, fungsi push (mendorong) digunakan untuk mendorong/menekan/menambah data ke dalam tumpukan, yang didalamnya terdapat parameter faktual tipe data char item.
void push(char item) {
    if (top >= SIZE-1) { // jika nilai top kurang dari 99 atau (SIZE - 1), maka jalankan block kode ini
        cout << "\nStack Penuh! "; // tampilkan string ini ke layar, sebelum itu buat bari baru (enter/newline) karena \n
    }
    else { // jika percabangan diatas salah, maka jalankan block kode ini
        top += 1; // top = top + 1, top ditambah 1.
        stack[top] = item; // memasukan nilai item kedalam variabel stack di index top
    }
}

// define pop operation, fungsi pop (letusan) digunakan untuk mengeluarkan/menghilangkan/mengambil nilai/data yang ada dalam tumpukan.
char pop(){
    char item; // deklarasi variabel item, dimana variabel ini digunakan untuk menampung sementara data yang diambil pada stack (data temporer).
    if (top < 0){ // jika variabel top lebih besar dari nol, maka jalankan block kode ini
        cout << "Stack Kosong ! "; // mengeluarkan string ini ke layar
        getchar(); // menghentikan program sementara sampai tombol keybord ditekan
        exit(1); // memberikan status EXIT_FAILURE karena nilai pada parameternya/argumentnya itu 1, supaya program berhenti dengan normal.
    }
    else { // jika percabangan diatas salah, maka jalankan block kode ini
        item = stack[top]; // memasukan nilai stack index top kedalam variabel item.
        top -= 1; // top = top - 1, top dikurangi 1
    }
    return(item); // mengembalikan data pada variabel item
}

// operator yang diijinkan, fungsi isOperator (adalah operator) digunakan untuk mengecek nilai parameter faktual yang dimasukan adalah ^, *, /, +, -. Maka akan mengembalikan nilai (1/true/benar).
int isOperator(char symbol){
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-'){ // jika variabel symbol sama dengan "^" atau "*" atau "/" atau "+" atau "-", maka jalankan blok dibawah ini
        return 1; // mengembalikan nilai '1' yang artinya benar (true)
    }
    else { // jika percabangan diatas salah, maka jalankan block kode ini
        return 0; // mengembalikan nilai '0' yang artinya salah (false)
    }
}

// fungsi precedence (hak lebih tinggi/derajat) digunakan untuk mengecek derajat dari operator.
int precedence(char symbol){ 
    if (symbol == '^'){ // jika variabel symbol sama dengan "^", maka jalankan block kode ini
        return 3; // mengembalikan nilai '3'
    }
    else if (symbol == '*' || symbol == '/'){ // jika variabel symbol sama dengan "*" atau "/", maka jalankan block kode ini
        return 2; // mengembalikan nilai '2'
    }
    else if (symbol == '+' || symbol == '-'){ // jika variabl symbol sama dengan "+" atau "-", maka jalankan block kode ini
        return 1; // mengembalikan nilai '1'
    }
    else { // jika percabangan diatas salah, maka jalankan block kode ini
        return 0; // mengembalikan nilai '0'
    }
}

// fungsi infixToPostfix dengan tipe data void, mempunyai parameter faktual char infix_exp dan char postfix_exp digunakan untuk (convert) mengubah infix ke postfix
void infixToPostfix(char infix_exp[], char postfix_exp[]) {
    int i = 0, j = 0; // variabel i & j dengan tipe data bilangan bulat digunakan untuk menampung nilai index untuk array char infix_exp & postfix_exp, bernilai '0'.
    char item; // variabel item dengan tipe data char digunakan untuk menampung sementara yang dibaca
    char x; // variabel x dengan tipe data char yang digunakan untuk menampung data yang dikeluarkan dari tumpukan.

    push('('); // memasukan data kurung buka "(" ke tumpukan.
    strcat(infix_exp, ")"); // menambahkan string: kurung tutup ")" dibelakangnya variabel char infix_exp.

    // i = 0, j = 0; // baris kode ini tidak digunakan, karna sudah diganti pada baris code 83.
    item = infix_exp[i]; // memasukan nilai infix_exp di index i ke dalam variabel item
    while(item != '\0') { // ketika variabel item tidak sama dengan NULL (kosong), maka jalankan block kode ini 
        // jika yang dibaca kurung buka.......................
        if(item == '(') { // jika variabel item sama dengan kurung buka, maka jalankan block kode ini
            push(item); // masukan data item kedalam tumpukan.
        } else if(isdigit(item) || isalpha(item)) { // jika nilai dalam variabel item adalah digit atau alfabet, maka jalankan block kode ini
            postfix_exp[j] = item; // masukan nilai item ke dalam variabel postfix_exp pada index j
            j++; // j = j + 1, j ditambah 1
        } else if(isOperator(item) == 1) { // jika nilai dalam variabel item adalah operator, maka jalankan block kode dibawah ini
            x = pop(); // memasukan nilai pop() atau nilai yang dikeluarkan dari tumpukan kedalam variabel x.
            while (isOperator(x) == 1 && precedence(x) >= precedence(item)) { // jika nilai dalam x adalah operator dan derajat dari x lebih besar sama dengan derajat dari item, maka jalankan block kode dibawah ini
                postfix_exp[j] = x; // masukan nilai x kedalam variabel postfix_exp pada index j
                j++; // j = j + 1, j ditambah 1.
                x = pop(); // memasukan nilai pop() atau nilai yang dikeluarkan dari tumpukan kedalam variabel x.
            }
            push(x); // memasukan nilai x kedalam tumpukan
            push(item); // memasukan nilai item kedalam tumpukan 
        } else if(item == ')') { // jika variabel item sama dengan kurung tutup, maka jalankan block kode ini
            x = pop(); // memasukan nilai pop() atau nilai yang dikeluarkan dari tumpukan kedalam variabel x.
            while (x != '(') { // ketika variabel x tidak sama dengan kurung buka, maka jalankan block kode ini
                postfix_exp[j] = x; // masukan nilai x kedalam variabel postfix_exp pada index j
                j++; // j = j + 1, j ditambah 1.
                x = pop(); // memasukan nilai pop() atau nilai yang dikeluarkan dari tumpukan kedalam variabel x.
            }
        } else if(item == ' ') { // jika item sama dengan spasi / ' ', maka jalankan block kode ini, maskudnya spasi diabaikan.
 
        } else { // jika percabangan diatas salah, maka jalankan block kode ini
            cout << "\nEkspresi infix tidak valid! \n"; // newline lalu tampilkan string ini ke layar lalu newline lagi
            getchar(); // menghentikan program sementara sampai tombol keybord ditekan
            exit(1); // memberikan status EXIT_FAILURE karena nilai pada parameternya/argumentnya itu 1, supaya program berhenti dengan normal.
        }
        i++; // i = i + 1, i ditambah 1
        item = infix_exp[i]; // memasukan nilai infix_exp pada index i ke dalam variabel item
    }
    if(top > 0) { // jika variabel top lebih besar dari 0, maka jalankan block kode ini
        cout << "\nEkspresi infix tidak valid! \n"; // newline lalu tampilkan string ini ke layar lalu newline lagi
        getchar(); // menghentikan program sementara sampai tombol keybord ditekan
        exit(1); // memberikan status EXIT_FAILURE karena nilai pada parameternya/argumentnya itu 1, supaya program berhenti dengan normal.
    }
    postfix_exp[j] = '\0'; // memasukan nilai NULL (kosong) kedalam variabel postfix_exp pada index j, dimana index j disini adalah index terakhir.
}

// program utama / fungsi utama (main function).
void main() {
    char infix[SIZE], postfix[SIZE]; // mendefinisikan variabel infix dan postfix dengan tipedata char yang memiliki panjang char maksimal 100 sesuai dengan nilai konstanta dari SIZE.

    cout << "Program Konvesi Infix ke Postfix\n"; // menampilkan "Program Konvesi Infix ke Postfix" pada layar setelah itu enter/new line (baris baru).
    cout << "\nMasukkan notasi Infix: "; // enter/new line (baris baru) lalu menampilkan "Masukan notasi Infix" pada layar.
    gets(infix); // fungsi yang ada pada header <stdio.h> yang digunakan untuk memasukan (input) data/nilai character (huruf) yang ada spasinya, supaya spasinya bisa masuk kedalam variabel.
    
    // konversikan infix ke postfix............................
    infixToPostfix(infix, postfix); // fungsi ini digunakan untuk mengubah/konversi data/nilai dari masukan(inputan) infix ke postfix, dimana memiliki 2 parameter yaitu infix, postfix.
    
    cout << "Postfix yang terbentuk : " << postfix; // menampilkan dilayar/terminal "Postfix yang terbentuk : " dan isi dari variabel postfix yang didapatkan dari fungsi infixToPostfix;
    getch(); // ini dugunakan untuk menghentikan sementara sampai salah satu tombol pada keyboard ditekan.
}