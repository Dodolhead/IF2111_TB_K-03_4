#include <stdio.h>
#include "store_list.h"

void StoreList(ArrayDin Info) {
    // KAMUS
    int i, j;
    // ALGORITMA
    if (Length(Info) == 0) {
        printf("TOKO KOSONG");
    } else {
        printf("List barang yang ada di toko :\n");
        for (i = 0; i < Length(Info); i++) {
            printf("- ");

            for (j = 0; NamaBarang(Get(Info, i))[j] != '\0'; j++) {
                printf("%c", NamaBarang(Get(Info, i))[j]);
            }

            printf("\n");
        }
    }
}
