#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include "mesinkarakter.h"
#include "mesinkata.h"

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define MAX_LEN 100
#define InitialSize 10

typedef int IdxType;

// ADT Barang
typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

// ADT Array Dinamis
typedef struct {
    Barang *A;
    int Capacity;
    int Neff;
} ArrayDin;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin();

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Barang Get(ArrayDin array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array);

/**
 * Fungsi untuk memasukkan list barang ke dalam array dinamis
 * Prekondisi: array sembarang
 */
void ListBarang(ArrayDin *array);

#endif
