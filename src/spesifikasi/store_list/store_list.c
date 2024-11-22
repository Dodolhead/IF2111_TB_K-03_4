#include <stdio.h>
#include "store_list.h"

void StoreList(ArrayDin Info) {
    // KAMUS
    int i, j;
    char* name;
    // ALGORITMA
    if (Length(Info) == 0) {
        printf("TOKO KOSONG\n");
    } else {
        printf("List barang yang ada di toko :\n");
        for (i = 0; i < Length(Info); i++) {
            printf("- ");

            name = NamaBarang(Get(Info, i)); 
            for (j = 0; name[j] != '\0'; j++) {
                printf("%c", name[j]);
            }

            printf("\n");
        }
    }
}
