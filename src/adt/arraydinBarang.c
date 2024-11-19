#include <stdio.h>
#include "arraydinBarang.h"
#include "stdlib.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    ArrayDin A;

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
    free(array->A);
    array->Capacity = 0;
    array->Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array) {
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array) {
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
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array) {
    return (array.Capacity);
}

/**
 * Fungsi untuk memasukkan list barang ke dalam array dinamis
 * Prekondisi: array sembarang
 */
void ListBarang(ArrayDin *array) {
    int i, j, items = 0, baris = 0;
    STARTWORD();

    // Mengecek jumlah barang dalam toko
    for (i = 0; i < CurrentWord.Length; i++) {
        items = items * 10 + ((CurrentWord.TabWord[i]) - '0');
    }

    // Mencetak barang dalam toko
    if (items > 0) {

        // Menyalin harga dan nama barang ke array dinamis
        while (baris < items && baris <= GetCapacity(*array)) {
            int harga = 0, panjang = 0;

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
