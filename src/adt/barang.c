#include <stdio.h>
#include "barang.h"

/* ********** KONSTRUKTOR BARANG ********** */
Barang MakeBarang(char* name, int price) {
/* Membentuk sebuah Barang dari komponen-komponennya */
/* Prekondisi (tidak perlu dicek): */
/* Name terdiri dari maksimal 100 karakter  */
/* price terdiri dari bilangan bulat */
/* I.S. name, price terdefinisi */
/* F.S. Barang terbentuk dengan name dan price yang sesuai */
    // KAMUS
    Barang b;
    // ALGORITMA
    copyString(b.name, name);
    b.price = price;

    return item; 
}

/* ********** SELEKTOR ********** */
int HargaBarang(Barang b) {
/* Mengirimkan harga barang */
    return b.price;
}

char* NamaBarang(Barang b) {
/* Mengirimkan nama barang */
    return b.name;
}