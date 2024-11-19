#include <stdio.h>
#include "store_list.h"

void StoreList(ArrayDin Info) {
    int i, j;

    if (Length(Info) == 0) {
        printf("TOKO KOSONG");
    } else {
        printf("List barang yang ada di toko :\n");
        for (i = 0; i < Length(Info); i++) {
            printf("- ");

            for (j = 0; Info.A[i].name[j] != '\0'; j++) {
                printf("%c", Info.A[i].name[j]);
            }

            printf("\n");
        }
    }
}
