#ifndef BARANG_H
#define BARANG_H

#include "../../utilities.h"

#define MAX_LEN 100
#define EMPTY -1

typedef struct {
        char name[MAX_LEN];
        int price;
        int jumlahBarang;  
} Barang;

/* ********** KONSTRUKTOR BARANG ********** */
Barang MakeBarang(char* name, int price);
/* Membentuk sebuah Barang dari komponen-komponennya */
/* Prekondisi (tidak perlu dicek): */
/* Name terdiri dari maksimal 100 karakter  */
/* price terdiri dari bilangan bulat */
/* I.S. name, price terdefinisi */
/* F.S. Barang terbentuk dengan name dan price yang sesuai */

/* ********** SELEKTOR ********** */
int HargaBarang(Barang b);
/* Mengirimkan harga barang */

char* NamaBarang(Barang* b);
/* Mengirimkan nama barang */

#endif
