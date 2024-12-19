#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include "../../adt/mesinkarakter/mesinkarakter.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/barang/barang.h"
#include "../../../utilities.h"

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10

typedef int IdxType;

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
boolean IsArrDinEmpty(ArrayDin array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int ArrLength(ArrayDin array);

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
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void ArrInsertAt(ArrayDin *array, char* name, int harga, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void ArrInsertLast(ArrayDin *array, char* name, int harga);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void ArrDeleteAt(ArrayDin *array, char* name);

/**
 * Fungsi untuk memasukkan list barang ke dalam array dinamis
 * Prekondisi: array sembarang
 */
void ListBarang(ArrayDin *array, char filename[]);

#endif
