#include <stdio.h>
#include "queue.h"

int main() {
    Queue myQueue;
    char dequeuedName[MAX_LEN];

    // Inisialisasi Queue
    CreateQueue(&myQueue);
    printf("Queue berhasil dibuat.\n");

    // Cek apakah Queue kosong
    if (isQueueEmpty(myQueue)) {
        printf("Queue kosong saat ini.\n");
    }

    // Menambahkan elemen ke Queue
    printf("\nMenambahkan elemen ke Queue:\n");
    enqueue(&myQueue, "BarangA");
    enqueue(&myQueue, "BarangB");
    enqueue(&myQueue, "BarangC");

    // Menampilkan isi Queue
    printf("\nIsi Queue saat ini:\n");
    displayQueue(myQueue);

    // Menghapus elemen dari Queue
    printf("\nMenghapus elemen dari Queue:\n");
    dequeue(&myQueue, dequeuedName);
    printf("Elemen yang dihapus: %s\n", dequeuedName);

    // Menampilkan isi Queue setelah penghapusan
    printf("\nIsi Queue setelah penghapusan:\n");
    displayQueue(myQueue);

    // Cek apakah Queue penuh
    if (isQueueFull(myQueue)) {
        printf("\nQueue penuh.\n");
    } else {
        printf("\nQueue belum penuh.\n");
    }

    // Menambahkan elemen kembali
    printf("\nMenambahkan elemen ke Queue kembali:\n");
    enqueue(&myQueue, "BarangD");
    enqueue(&myQueue, "BarangE");

    // Menampilkan isi Queue setelah penambahan
    printf("\nIsi Queue setelah penambahan:\n");
    displayQueue(myQueue);

    return 0;
}
