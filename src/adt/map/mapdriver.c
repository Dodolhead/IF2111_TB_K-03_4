#include <stdio.h>
#include "map.h"

int main() {
    Map myMap;

    // Inisialisasi Map
    CreateMapEmpty(&myMap);
    printf("Map berhasil dibuat kosong.\n");

    // Cek apakah Map kosong
    if (IsMapEmpty(myMap)) {
        printf("Map kosong saat ini.\n");
    }

    // Menambahkan elemen ke Map
    printf("Menambahkan elemen ke Map:\n");
    Insert(&myMap, 1, 100);
    Insert(&myMap, 2, 200);
    Insert(&myMap, 3, 300);

    // Tampilkan isi Map
    printf("Isi Map saat ini:\n");
    for (int i = 0; i < myMap.Count; i++) {
        printf("Key: %d, Value: %d\n", myMap.Elements[i].Key, myMap.Elements[i].Value);
    }

    // Mencari elemen berdasarkan key
    printf("\nMencari elemen dengan key = 2:\n");
    valuetype value = Value(myMap, 2);
    if (value != Undefined) {
        printf("Key ditemukan, Value: %d\n", value);
    } else {
        printf("Key tidak ditemukan.\n");
    }

    // Menghapus elemen dari Map
    printf("\nMenghapus elemen dengan key = 2:\n");
    Delete(&myMap, 2);

    // Tampilkan isi Map setelah penghapusan
    printf("Isi Map setelah penghapusan:\n");
    for (int i = 0; i < myMap.Count; i++) {
        printf("Key: %d, Value: %d\n", myMap.Elements[i].Key, myMap.Elements[i].Value);
    }

    // Cek apakah Map penuh
    if (IsMapFull(myMap)) {
        printf("Map penuh.\n");
    } else {
        printf("Map belum penuh.\n");
    }

    return 0;
}
