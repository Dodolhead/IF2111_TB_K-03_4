#include <stdio.h>
#include "mesinangka.h"
#include "mesinkarakter.h" // Menggunakan Mesin Karakter sebagai dasar

int currentAngka;
boolean EOPAngka;

void STARTANGKA() {
    START(); // Inisialisasi Mesin Karakter
    EOPAngka = false;
    ADVANGKA(); // Cari angka pertama
}

void ADVANGKA() {
    while (!IsEOP() && (GetCC() < '0' || GetCC() > '9')) {
        ADV(); // Lewati karakter non-angka
    }
    if (IsEOP()) {
        EOPAngka = true;
    } else {
        currentAngka = GetCC() - '0'; // Konversi karakter angka ke integer
        ADV(); // Pindah ke karakter berikutnya
    }
}

int bacaAngka(){
    int total=0;
    while (!IsEOPAngka()) {
        total = total * 10 + currentAngka;
    ADVANGKA();
    }
    return total;
}

boolean IsEOPAngka() {
    return EOPAngka;
}

int GetAngka() {
    return currentAngka;
}
