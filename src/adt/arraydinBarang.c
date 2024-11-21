#include <stdio.h>
#include <stdlib.h>
#include "arraydinBarang.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    // KAMUS
    ArrayDin A;
    // ALGORITMA
    A.Capacity = InitialSize;
    A.A = (Barang*) malloc (A.Capacity * sizeof(Barang));
    A.Neff = 0;

    return A;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array) {
    // KAMUS LOKAL
    // ALGORITMA
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

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array) {
    // KAMUS LOKAL
    // ALGORITMA
    if (IsEmpty(array)) {
        return 0;
    } else {
        return (array.Neff);
    }
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

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, char* name, int harga, IdxType i) {
    // KAMUS LOKAL
    IdxType j;
    
    // ALGORITMA
    // Memindahkan barang
    for (j = Length(*array)-1; j >= i; j--) {
        (*array).A[j+1].price = HargaBarang(Get((*array,j)));
        copyString((*array).A[j+1].name, NamaBarang(Get((*array),j)))
    }

    // Masukkan barang
    (*array).A[i] = MakeBarang(name, harga);
    (*array).Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, char* name, int harga) {
    // KAMUS
    // ALGORITMA
    InsertAt(array, name, harga, (array->Neff));
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, char* name) {
    // KAMUS
    IdxType j, k;
    boolean found = false;
    // ALGORITMA
    for (j = 0; j < Length(*array) && !found; j++) {
        if (!stringEquals(NamaBarang(Get((*array),j)), name)) {  // Match found
            found = true;

            for (k = j; k < Length(*array) - 1; k++) {
                (*array).A[k].price = HargaBarang(Get((*array),k+1));

                copyString((*array).A[k].name, NamaBarang(Get((*array),k+1)))
            }
        }
    }

    if (found) {
        (*array).Neff--;
    }
}


/**
 * Fungsi untuk memasukkan list barang ke dalam array dinamis
 * Prekondisi: array sembarang
 */
void ListBarang(ArrayDin *array) {
    // KAMUS
    int i, j, items = 0, baris = 0;
    int harga = 0, panjang = 0;
    // ALGORITMA
    STARTWORD();

    // Mengecek jumlah barang dalam toko
    for (i = 0; i < CurrentWord.Length; i++) {
        items = items * 10 + ((CurrentWord.TabWord[i]) - '0');
    }

    // Mencetak barang dalam toko
    if (items > 0) {

        // Menyalin harga dan nama barang ke array dinamis
        while (baris < items && baris <= GetCapacity(*array)) {
            harga = 0;
            panjang = 0;

            // Menyalin harga barang
            ADVWORD();
            for (i = 0; i < CurrentWord.Length; i++) {
                if (CurrentWord.TabWord[i] >= '0' && CurrentWord.TabWord[i] <= '9') {
                    harga = harga * 10 + ((CurrentWord.TabWord[i]) - '0');
                }
            }
            (*array).A[baris].price = harga;

            // Menyalin kata pertama dari nama barang
            ADVWORD();
            for (j = 0; j < CurrentWord.Length; j++) {
                (*array).A[baris].name[j] = CurrentWord.TabWord[j];
            }
            panjang = CurrentWord.Length;

            // Menyalin barang yang memiliki lebih dari satu kata
            while (GetCC() != '\n') {
                ADVWORD();

                (*array).A[baris].name[panjang] = BLANK;
                panjang++;

                for (j = 0; j < CurrentWord.Length; j++) {
                    (*array).A[baris].name[j+panjang] = CurrentWord.TabWord[j];
                }
                panjang = panjang + CurrentWord.Length;

            }
            (*array).A[baris].name[panjang] = '\0';
            baris++;
        }
    }
    (*array).Neff = baris;

}
