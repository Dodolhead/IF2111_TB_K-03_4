#include <stdio.h>
#include <stdlib.h>
#include "save.h"

void Save(ArrayDin Info, List ListUser, char* filename) {
    // KAMUS
    int i, j;
    FILE* file;
    char fullpath[] = "src/data/";
    Stack temp;

    char tempname[50]; 
    int tempprice;

    addressLinkedList p;

    // ALGORITMA
    CreateStackEmpty(&temp);
    stringConcat(fullpath, filename);

    // Membuka file untuk penulisan
    file = fopen(fullpath, "w");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file %s untuk penulisan.\n", fullpath);
        return;
    }

    // Menulis data barang
    fprintf(file, "%d\n", ArrLength(Info)); 
    for (i = 0; i < ArrLength(Info); i++) {
        fprintf(file, "%d ", HargaBarang(Info.A[i]));
        for (j = 0; NamaBarang(&(Info.A[i]))[j] != '\0'; j++) {
            fprintf(file, "%c", NamaBarang(&(Info.A[i]))[j]); 
        }
        fprintf(file, "\n"); 
    }

    // Menulis data user
    fprintf(file, "%d\n", ListUserLength(&ListUser));
    for (i = 0; i < ListUserLength(&ListUser); i++) {
        fprintf(file, "%d %s %s\n", ListUser.A[i].money, ListUser.A[i].name, ListUser.A[i].password);

        // Menulis riwayat pembelian user
        j = 0; // Push ke temp
        while (!IsStackEmpty(ListUser.A[i].riwayat_pembelian)) {
            Pop(&ListUser.A[i].riwayat_pembelian, tempname, &tempprice);
            Push(&temp, tempname, tempprice);
            j++;
        }
        fprintf(file, "%d\n", j);
        // Push ke stack user
        while (!IsStackEmpty(ListUser.A[i].riwayat_pembelian)) {
            Pop(&temp, tempname, &tempprice);
            Push(&ListUser.A[i].riwayat_pembelian, tempname, tempprice);
            fprintf(file, "%d %s\n", InfoTop(ListUser.A[i].riwayat_pembelian).price, InfoTop(ListUser.A[i].riwayat_pembelian).name);
        }

        // Menulis wishlist user
        fprintf(file, "%d\n", WishlistCount(&(ListUser.A[i])));
        p = First(ListUser.A[i].wishlist);
        for (j = 0; j < WishlistCount(&(ListUser.A[i])); j++) {
            fprintf(file, "%s\n", Info(p));
            p = Next(p);
        }
    }

    // Menutup file
    if (fclose(file) != 0) {
        printf("Error: Gagal menutup file %s dengan benar.\n", fullpath);
        return;
    }

    // Notifikasi keberhasilan
    printf("Save file berhasil disimpan di %s.\n", fullpath);
}