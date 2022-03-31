#include <conio.h> // getch()
#include <stdio.h> // gets()
#include <iostream.h> // cout, cin
#define maxHuruf 16 // Constanta maxHuruf untuk char.

struct structDataPegawai {
    char nama[maxHuruf]; // masukan nama, tipe data char, dan maksimal huruf 16 sesuai dengan nilai maxHuruf.
    char kota[maxHuruf]; // masukan kota, tipe data char, dan maksimal huruf 16 sesuai dengan nilai maxHuruf.
    int gajiPokok; // masukan gaji pokok, tipe data int/float/double
    int totalJamLembur; // masukan jam lembur, tipe data int/float/double
    int taripLembur; // proses hitung (2% * Gaji Kotor), tipe data int/float/double
    int terimaLembur; // proses hitung (totalJamLembur * totalJamLembur), tipe data int/float/double
};

// Bedanya 
