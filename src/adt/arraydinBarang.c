#include <stdio.h>
#include <stdlib.h>
#include "arraydinBarang.h"


/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
boolean IsEmpty(ArrayDin array) {
    return (array.Neff == 0);
}

ArrayDin MakeArrayDin() {
    ArrayDin A;
    A.Capacity = InitialSize;
    A.A = (Barang*) malloc(A.Capacity * sizeof(Barang));
    A.Neff = 0;
    return A;
}

void DeallocateArrayDin(ArrayDin *array) {
    free(array->A);
    array->Capacity = 0;
    array->Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array) {
    // KAMUS LOKAL
    // ALGORITMA
    return (array.Neff == 0);
}

boolean IsArrFull(ArrayDin array) {
    return (array.Neff == array.Capacity);
}

int ArrLength(ArrayDin array) {
    return (array.Neff);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Barang Get(ArrayDin array, IdxType i) {
    // KAMUS LOKAL
    // ALGORITMA
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array) {
    // KAMUS LOKAL
    // ALGORITMA
    return (array.Capacity);
}

void ArrInsertAt(ArrayDin *array, char* name, int harga, IdxType i) {
    IdxType j;
    for (j = ArrLength(*array) - 1; j >= i; j--) {
        (*array).A[j + 1].price = HargaBarang(GetArrDin((*array), j));
        for (int k = 0; NamaBarang(&((*array).A[j]))[k] != '\0'; k++) {
            (*array).A[j + 1].name[k] = NamaBarang(&((*array).A[j]))[k];
        }
        (*array).A[j + 1].name[MAX_LEN - 1] = '\0';

    }

    (*array).A[i] = MakeBarang(name, harga);
    (*array).Neff++;
}

void ArrInsertLast(ArrayDin *array, char* name, int harga) {
    ArrInsertAt(array, name, harga, (array->Neff));
}

void ArrDeleteAt(ArrayDin *array, char* name) {
    IdxType j, k;
    boolean found = false;

    for (j = 0; j < ArrLength(*array) && !found; j++) {
        int equal = 1; // Flag untuk perbandingan manual string
        for (int c = 0; name[c] != '\0' || NamaBarang(&((*array).A[j]))[c] != '\0'; c++) {
            if (name[c] != NamaBarang(&((*array).A[j]))[c]) {
                equal = 0;
                break;
            }
        }

        if (equal) { // Jika nama sama
            found = true;
            for (k = j; k < ArrLength(*array) - 1; k++) {
                (*array).A[k].price = HargaBarang(GetArrDin((*array), k + 1));
                for (int c = 0; NamaBarang(&((*array).A[k + 1]))[c] != '\0'; c++) {
                    (*array).A[k].name[c] = NamaBarang(&((*array).A[k + 1]))[c];
                }
                (*array).A[k].name[MAX_LEN - 1] = '\0';

            }
        }
    }

    if (found) {
        (*array).Neff--;
    }
}

void ListBarang(ArrayDin *array, char filename[]) {
    int i, j, items = 0, baris = 0;
    int harga = 0, panjang = 0;

    START(filename);
    ADVWORD();

    for (i = 0; i < currentWord.Length; i++) {
        items = items * 10 + (currentWord.TabWord[i] - '0');
    }

    if (items > 0) {
        while (baris < items && baris < GetCapacityArrDin(*array)) {
            harga = 0;
            ADVWORD();
            for (i = 0; i < currentWord.Length; i++) {
                harga = harga * 10 + (currentWord.TabWord[i] - '0');
            }
            (*array).A[baris].price = harga;

            ADVWORD();
            for (j = 0; j < currentWord.Length; j++) {
                (*array).A[baris].name[j] = currentWord.TabWord[j];
            }
            panjang = currentWord.Length;

            while (GetCC() != '\n' && GetCC() != MARK) {
                ADVWORD();
                (*array).A[baris].name[panjang] = BLANK;
                panjang++;
                for (j = 0; j < currentWord.Length; j++) {
                    (*array).A[baris].name[j + panjang] = currentWord.TabWord[j];
                }
                panjang += currentWord.Length;
            }
            (*array).A[baris].name[panjang] = '\0';
            baris++;
        }
    }
    (*array).Neff = baris;
}
