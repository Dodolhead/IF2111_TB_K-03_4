#include <stdio.h>
#include "store_supply.h"

void StoreSupply(Queue q, ArrayDin Info) {
    // KAMUS
    char save[MAX_LEN];
    int harga, i = 0, select = 0;
    boolean finish = false;
    char Terima[6] = {'T', 'e', 'r', 'i', 'm', 'a'};
    char Tunda[5] = {'T', 'u', 'n', 'd', 'a'};
    char Tolak[5] = {'T', 'o', 'l', 'a', 'k'};
    char Purry[5] = {'P', 'u', 'r', 'r', 'y'};

    // ALGORITMA
    STARTWORD();
    while (!finish) {
        printf("Apakah kamu ingin menambahkan barang ");
        i = 0;
        while (HEAD(request).name[i] != '\0') {
            printf("%c",HEAD(request).name[i]);
            i++;
        }
        printf(": ");

        while (CurrentWord.TabWord[select] != '\0') {
            printf("%c", CurrentWord.TabWord[select]);
            select++;
        }
        printf("\n");

        if (stringEquals(CurrentWord.TabWord, Terima)) {
            printf("Harga barang: ");
            ADVWORD();
            select = 0;
            while (HEAD(q).name[select] != '\0') {
                printf("%c", CurrentWord.TabWord[select]);
                select++;
            }
            printf("\n");
            InsertLast(&Info, HEAD(q).name, CurrentWord.TabWord);
            dequeue(&q, save);
        } else if (stringEquals(CurrentWord.TabWord, Tunda)) {
            dequeue(&q, save);
            enqueue(&q, save);
        } else if (stringEquals(CurrentWord.TabWord, Tolak)) {
            dequeue(&q, save);
        } else if (stringEquals(CurrentWord.TabWord, Purry)) {
            finish = true;
            printf("STORE SUPPLY ditutup");
        } else {
            printf("Input tidak valid");
        }
    }
}
