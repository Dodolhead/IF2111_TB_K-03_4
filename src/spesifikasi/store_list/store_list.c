#include <stdio.h>
#include "store_list.h"

void StoreList(ArrayDin Info) {
    // KAMUS
    int i, j;
    char* name;
    // ALGORITMA
    if (ArrLength(Info) == 0) {
        printf("TOKO KOSONG\n");
    } else {
        printf("List barang yang ada di toko :\n");
        for (i = 0; i < ArrLength(Info); i++) {
            printf("- ");

            name = NamaBarang(&(Info.A[i])); 
            for (j = 0; name[j] != '\0'; j++) {
                printf("%c", name[j]);
            }

            printf("\n");
        }
    }
}

/*
int main() {
    ArrayDin Info = MakeArrayDin();
    ListBarang(&Info);

    StoreList(Info);
    return 0;
}
*/
