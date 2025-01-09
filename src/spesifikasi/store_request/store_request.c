#include <stdio.h>
#include "store_request.h"

void StoreRequest(Queue q, ArrayDin Info) {
    // KAMUS
    int i = 0, j = 0;
    boolean foundQueue = false, foundList = false;
    char name[50];

    // ALGORITMA
    // Membaca kata pertama nama barang
    ADVWORD();
    copyString(name, currentWord.TabWord);

    // Jika nama barang lebih dari satu kata
    while (GetCC() != '\n') {
        ADVWORD();
            name[stringLength(name)] = BLANK;
            stringConcat(name, currentWord.TabWord);
    }

    // Mencetak nama barang
    for (i = 0; name[i] != '\0'; i++) {
        printf("%c", name[i]);
    }
    printf("\n");

    // Mengecek ketersediaan barang dalam toko
    if (!IsArrDinEmpty(Info)) {
        for (j = 0; j < ArrLength(Info) && !foundList; j++) {
            if (stringEquals(NamaBarang(&(Info.A[j])), name)) {
                foundList = true;
            }
        }
    } else {
        printf("ERROR: Toko Kosong!");
    }

    // Mengecek nama barang di antrian
    if (!isQueueEmpty(q)) {
        for (i = IDX_HEAD(q); i <= IDX_TAIL(q) && !foundQueue; i++) {
            if (stringEquals(NamaBarang(&(q.buffer[i])), name)) {
                foundQueue = true;
            } else {
                i = (i + 1) % CAPACITY;
            }
        }
    } else {
        printf("ERROR: Antrian Kosong!");
    }

    if (foundList) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    } else {
        if (foundQueue) {
            printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        } else {
            enqueue(&q, name);
            printf("Barang berhasil ditambahkan ke antrian!\n");
        }
    }
}


int main() {
    Queue request;
    ArrayDin Info = MakeArrayDin();
    CreateQueue(&request);
    char item[] = "Kata";

    enqueue(&request, item);
    displayQueue(request);
    StoreRequest(request, Info);
    displayQueue(request);
    return 0;
}

