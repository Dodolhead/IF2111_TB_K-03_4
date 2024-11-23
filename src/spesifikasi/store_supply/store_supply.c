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
        while (HEAD(q).name[i] != '\0') {
            printf("%c", HEAD(q).name[i]);
            i++;
        }
        printf(": ");

        select = 0;
        while (CurrentWord.TabWord[select] != '\0') {
            printf("%c", CurrentWord.TabWord[select]);
            select++;
        }
        printf("\n");

        if (stringEquals(CurrentWord.TabWord, Terima)) {
            printf("Harga barang: ");
            ADVWORD();
            select = 0;
            while (CurrentWord.TabWord[select] != '\0') {
                printf("%c", CurrentWord.TabWord[select]);
                select++;
            }
            for (i = 0; i < CurrentWord.Length; i++) {
                if (CurrentWord.TabWord[i] >= '0' && CurrentWord.TabWord[i] <= '9') {
                    harga = harga * 10 + ((CurrentWord.TabWord[i]) - '0');
                }
            }
            printf("\n");
            InsertLast(&Info, HEAD(q).name, harga);
            dequeue(&q, save);
        } else if (stringEquals(CurrentWord.TabWord, Tunda)) {
            dequeue(&q, save);
            enqueue(&q, save);
        } else if (stringEquals(CurrentWord.TabWord, Tolak)) {
            dequeue(&q, save);
        } else if (stringEquals(CurrentWord.TabWord, Purry)) {
            finish = true;
            printf("STORE SUPPLY ditutup\n");
        } else {
            printf("Input tidak valid\n");
        }
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
