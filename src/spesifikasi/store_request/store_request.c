#include <stdio.h>
#include "store_request.h"

boolean CompareItem(char* item1, char* item2) {
    boolean different = false;
    int i = 0;

    while (item2[i] != '\0' && !different) {
        if (item1[i] != item2[i]) {
            different = true;
        } else {
            i++;
        }
    }
    return different;
}

void StoreRequest() {
    char item[50] = {'A', 'K', '4', '7'};
    int i = 0;
    boolean foundQueue = false, foundList = false;
    Queue request;

    ArrayDin Info = MakeArrayDin();
    ListBarang(&Info);

    CreateQueue(&request);

    // Mengecek nama barang di toko
    if (!IsEmpty(Info)) {
        while (i < Length(Info) && !foundList) {
            if (!CompareItem(Info.A[i].name, item)) {
                foundList = true;
            } else {
                i++;
            }
        }
    }

    // Mengecek nama barang di antrian
    if (!isEmpty(request)) {
        i = IDX_HEAD(request);
        while (i <= IDX_TAIL(request) && !foundQueue) {
            if (!CompareItem(Info.A[i].name, request.buffer[i].name)) {
                foundQueue = true;
            } else {
                i++;
            }
        }
    }

    if (foundList) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    } else {
        if (foundQueue) {
            printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        } else {
            enqueue(&request, item);
            printf("Barang berhasil ditambahkan ke antrian!\n");
            displayQueue(request);
        }
    }
}
