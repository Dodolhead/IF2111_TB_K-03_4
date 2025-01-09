#include <stdio.h>
#include "history.h"

void History(Stack history, int N) {
    /* Input berupa Stack history dengan tipe elemen barang (nama dan harga) dan
        N jumlah barang yang ingin muncul */
    // KAMUS
    // ALGORITMA
    if (!IsStackEmpty(history)) {
        Stack temp;
        char name[50];
        int cost, i;
        CreateStackEmpty(&temp);

        printf("Riwayat pembelian barang:\n");

        for (i = 1; i <= N && !IsStackEmpty(history); i++) {
            printf("%d. ", i);

            for (int j = 0; (history).T[(history).TOP].name[j] != '\0'; j++) {
                printf("%c", (history).T[(history).TOP].name[j]);
            }

            printf(" %d\n", HargaBarang(history.T[i]));
            Pop(&history, name, &cost);
            Push(&temp, name, cost);
        }

        for (i = 1; i <= N && !IsStackEmpty(temp); i++) {
            Pop(&temp, name, &cost);
            Push(&history, name, cost);
        }
    } else {
        printf("Kamu belum membeli barang apapun!\n");
    }
}

int main() {
    Stack riwayat;
    CreateStackEmpty(&riwayat);

    Push(&riwayat, "AK47", 10);
    Push(&riwayat, "Aqua", 20);
    Push(&riwayat, "ItemA", 30);
    Push(&riwayat, "ItemB", 40);
    Push(&riwayat, "ItemC", 50);
    Push(&riwayat, "ItemD", 60);

    History(riwayat, 2);
}