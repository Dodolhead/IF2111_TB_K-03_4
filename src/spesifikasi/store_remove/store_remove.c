#include <stdio.h>
#include "store_remove.h"

void StoreRemove() {
    // KAMUS
    boolean foundList = false;
    int select = 0;

    // ALGORITMA
    printf("Nama barang yang akan dihapus: ");
    STARTWORD();

    while (CurrentWord.TabWord[select] != '\0') {
        printf("%c", CurrentWord.TabWord[select]);
        select++;
    }
    printf("\n");

    if (!IsEmpty(Info)) {
        select = 0;
        while (select < Length(Info) && !foundList) {
            if (!stringEquals(NamaBarang(Get(Info,select)), CurrentWord.TabWord)) {
                foundList = true;
            } else {
                select++;
            }
        }
    }

    select = 0;
    if (foundList) {
        while (CurrentWord.TabWord[select] != '\0') {
            printf("%c", CurrentWord.TabWord[select]);
            select++;
        }
        printf(" telah berhasil dihapus.\n");
        DeleteAt(&Info, CurrentWord.TabWord);
    } else {
        printf("Toko tidak menjual ");
        while (CurrentWord.TabWord[select] != '\0') {
            printf("%c", CurrentWord.TabWord[select]);
            select++;
        }
        printf("\n");
    }
}
