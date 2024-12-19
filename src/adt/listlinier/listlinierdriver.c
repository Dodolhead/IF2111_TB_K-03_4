#include <stdio.h>
#include "listlinier.h"

int main() {
    LinkedList L;
    addressLinkedList P;
    infoLinkedListtype X;

    // Inisialisasi list kosong
    CreateLinkedListEmpty(&L);
    printf("List berhasil diinisialisasi.\n");

    // Tambah elemen pertama
    printf("Menambahkan elemen pertama: 10\n");
    InsVFirst(&L, "10");
    PrintInfo(L);

    // Tambah elemen terakhir
    printf("Menambahkan elemen terakhir: 20\n");
    InsVLast(&L, "20");
    PrintInfo(L);

    // Tambah elemen lain di awal
    printf("Menambahkan elemen pertama: 5\n");
    InsVFirst(&L, "5");
    PrintInfo(L);

    // Menghapus elemen pertama
    printf("Menghapus elemen pertama.\n");
    DelVFirst(&L, &X);
    printf("Elemen yang dihapus: %s\n", X);
    PrintInfo(L);

    // Menghapus elemen terakhir
    printf("Menghapus elemen terakhir.\n");
    DelVLast(&L, &X);
    printf("Elemen yang dihapus: %s\n", X);
    PrintInfo(L);

    // Cari elemen dalam list
    printf("Mencari elemen 10 dalam list.\n");
    P = LinkedListSearch(L, "10");
    if (P != Nil) {
        printf("Elemen ditemukan: %s\n", Info(P));
    } else {
        printf("Elemen tidak ditemukan.\n");
    }

    // Hapus elemen tertentu
    printf("Menghapus elemen 10 dari list.\n");
    DelLinkedListP(&L, "10");
    PrintInfo(L);

    // Tambahkan elemen baru lagi
    printf("Menambahkan elemen pertama: 30\n");
    InsVFirst(&L, "30");
    PrintInfo(L);

    // Test jumlah elemen
    printf("Jumlah elemen dalam list: %d\n", NbElmt(L));

    // Dealokasi elemen
    while (!IsLinkedListEmpty(L)) {
        DelVFirst(&L, &X);
    }
    printf("List telah dikosongkan.\n");

    return 0;
}
