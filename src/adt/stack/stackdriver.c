#include <stdio.h>
#include "stack.h"

int main() {
    Stack myStack;
    char name[MAX_LEN];
    int price;

    // Inisialisasi Stack
    CreateStackEmpty(&myStack);
    printf("Stack berhasil dibuat.\n");

    // Cek apakah Stack kosong
    if (IsStackEmpty(myStack)) {
        printf("Stack kosong saat ini.\n");
    }

    // Menambahkan elemen ke Stack
    printf("\nMenambahkan elemen ke Stack:\n");
    Push(&myStack, "BarangA", 1000);
    printf("Push: BarangA, Harga: 1000\n");
    Push(&myStack, "BarangB", 2000);
    printf("Push: BarangB, Harga: 2000\n");
    Push(&myStack, "BarangC", 3000);
    printf("Push: BarangC, Harga: 3000\n");

    // Cek apakah Stack penuh
    if (IsStackFull(myStack)) {
        printf("Stack penuh.\n");
    } else {
        printf("Stack belum penuh.\n");
    }

    // Menghapus elemen dari Stack
    printf("\nMenghapus elemen dari Stack:\n");
    Pop(&myStack, name, &price);
    printf("Pop: Barang: %s, Harga: %d\n", name, price);

    Pop(&myStack, name, &price);
    printf("Pop: Barang: %s, Harga: %d\n", name, price);

    // Menambahkan elemen kembali ke Stack
    printf("\nMenambahkan elemen kembali ke Stack:\n");
    Push(&myStack, "BarangD", 4000);
    printf("Push: Barang: BarangD, Harga: 4000\n");

    // Menghapus elemen terakhir dari Stack
    Pop(&myStack, name, &price);
    printf("Pop: Barang: %s, Harga: %d\n", name, price);

    // Cek apakah Stack kosong
    if (IsStackEmpty(myStack)) {
        printf("\nStack kosong.\n");
    } else {
        printf("\nStack masih memiliki elemen.\n");
    }

    return 0;
}
