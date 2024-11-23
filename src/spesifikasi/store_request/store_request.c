#include <stdio.h>
#include "store_request.h"

void StoreRequest(Queue q, ArrayDin Info) {
    // KAMUS
    int i = 0;
    boolean foundQueue = false, foundList = false;

    // ALGORITMA
    STARTWORD();

    // Mengecek nama barang di toko
    if (!IsEmpty(Info)) {
        while (i < Length(Info) && !foundList) {
            if (stringEquals(NamaBarang(&(Info.A[i])), CurrentWord.TabWord)) {
                foundList = true;
            } else {
                i++;
            }
        }
    }

    // Mengecek nama barang di antrian
    if (!isEmpty(q)) {
        i = IDX_HEAD(q);
        while (i <= IDX_TAIL(q) && !foundQueue) {
            if (stringEquals(NamaBarang(&(q.buffer[i])), CurrentWord.TabWord)) {
                foundQueue = true;
            } else {
                i = (i + 1) % CAPACITY;
            }
        }
    }

    if (foundList) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    } else {
        if (foundQueue) {
            printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        } else {
            enqueue(&q, nama);
            printf("Barang berhasil ditambahkan ke antrian!\n");
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
    StoreRequest(request, Info);
    return 0;
}
*/
