#include <stdio.h>
#include "store_supply.h"

void StoreSupply(Queue q, ArrayDin Info) {
    // KAMUS
    char save[50];
    int harga, i = 0, select = 0;
    char name[50];

    // ALGORITMA
    printf("Apakah kamu ingin menambahkan barang ");
    i = 0;

    for (i = 0; HEAD(q).name[i] != '\0'; i++) {
        printf("%c", HEAD(q).name[i]);
    }
    printf(": ");

    ADVWORD();
    for (i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");

    if (stringEquals(currentWord.TabWord, "Terima")) {
        printf("Harga barang: ");
        ADVWORD();

        for (i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
            if (currentWord.TabWord[i] >= '0' && currentWord.TabWord[i] <= '9') {
                harga = harga * 10 + ((currentWord.TabWord[i]) - '0');
            }
        }
        printf("\n");
        ArrInsertLast(&Info, HEAD(q).name, harga);
        dequeue(&q, save);
    } else if (stringEquals(currentWord.TabWord, "Tunda")) {
        dequeue(&q, save);
        enqueue(&q, save);
    } else if (stringEquals(currentWord.TabWord, "Tolak")) {
        dequeue(&q, save);
    } else {
        printf("ERROR: Input tidak valid\n");
    }
}

/*
int main() {
    Queue request;
    ArrayDin Info = MakeArrayDin();
    CreateQueue(&request);
    ListBarang(&Info);
    char item[] = "Kata";

    enqueue(&request, item);
    StoreSupply(request, Info);
    return 0;
}
*/
