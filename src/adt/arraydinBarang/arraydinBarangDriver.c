#include <stdio.h>
#include "arraydinBarang.h"

int main() {
    // Deklarasi variabel
    ArrayDin array;
    int i;

    // Membuat ArrayDin
    array = MakeArrayDin();
    printf("ArrayDin berhasil dibuat dengan kapasitas awal: %d\n", GetCapacity(array));

    // Menambahkan elemen secara langsung
    printf("\nMenambahkan elemen ke dalam array:\n");
    ArrInsertLast(&array, "Barang1", 1000);
    ArrInsertLast(&array, "Barang2", 2000);
    ArrInsertLast(&array, "Barang3", 3000);

    // Menampilkan elemen setelah ditambahkan
    printf("Isi array setelah penambahan:\n");
    for (i = 0; i < ArrLength(array); i++) {
        printf("Barang ke-%d: %s, Harga: %d\n", i + 1, array.A[i].name, array.A[i].price);
    }

    // Menambahkan elemen di posisi tertentu
    printf("\nMenambahkan elemen 'BarangBaru' di indeks ke-1:\n");
    ArrInsertAt(&array, "BarangBaru", 1500, 1);

    // Menampilkan elemen setelah penambahan
    printf("Isi array setelah menambahkan di indeks ke-1:\n");
    for (i = 0; i < ArrLength(array); i++) {
        printf("Barang ke-%d: %s, Harga: %d\n", i + 1, array.A[i].name, array.A[i].price);
    }

    // Menghapus elemen tertentu
    printf("\nMenghapus elemen dengan nama 'Barang2':\n");
    ArrDeleteAt(&array, "Barang2");

    // Menampilkan elemen setelah penghapusan
    printf("Isi array setelah menghapus 'Barang2':\n");
    for (i = 0; i < ArrLength(array); i++) {
        printf("Barang ke-%d: %s, Harga: %d\n", i + 1, array.A[i].name, array.A[i].price);
    }

    // Dealokasi array
    DeallocateArrayDin(&array);
    printf("\nArrayDin berhasil didealokasi.\n");

    return 0;
}
