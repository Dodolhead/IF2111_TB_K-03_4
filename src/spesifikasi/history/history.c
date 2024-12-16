#include <stdio.h>
#include "history.h"

void History(Stack history, int N) {
    /* Input berupa Stack history dengan tipe elemen barang (nama dan harga) dan
        N jumlah barang yang ingin muncul */
    // KAMUS
    // ALGORITMA
    if (!IsStackEmpty(history)) {
        Stack temp;
        char[100] name;
        int cost, i;
        CreateStackEmpty(&temp);

        printf("Riwayat pembelian barang:\n");

        for (i = 1; i <= N && !IsStackEmpty(history); i++) {
            printf("%d. ", i);

            while ((history).T[(history).TOP].name[i] != '\0') {
                printf("%c", (history).T[(history).TOP].name[i]);
            }

            printf(" %d\n", HargaBarang(history.price));
            Pop(&history, &name, &cost);
            Push(&temp, name, cost);
        }

        for (i = 1; i <= N && !IsStackEmpty(temp); i++) {
            Pop(&temp, &name, &cost);
            Push(&history, name, cost);
        }
    } else {
        printf("Kamu belum membeli barang apapun!\n");
    }
}