#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    // KAMUS
    // ALGORITMA
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    // KAMUS
    // ALGORITMA
    return (q.idxHead == IDX_UNDEF) && (q.idxTail == IDX_UNDEF);
}

boolean isFull(Queue q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    // KAMUS
    // ALGORITMA
    return ((q.idxHead == 0) && (q.idxTail == CAPACITY-1));
}

int length(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    // KAMUS
    // ALGORITMA
    if (isEmpty(q)) {
        return 0;
    } else {
        return q.idxTail - q.idxHead + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, char* name) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    // KAMUS
    int i = 0;
    // ALGORITMA
    if (isEmpty(*q)) {
        (*q).idxHead = 0;
        (*q).idxTail = 0;
    } else {
        (*q).idxTail = ((*q).idxTail + 1) % CAPACITY;
    }

    copyString(TAIL(*q).name, name);
    TAIL(*q).price = NULL;
}


void dequeue(Queue *q, char *name) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. name = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    // KAMUS
    int i = 0;
    // ALGORITMA
    copyString(name, HEAD(*q).name);
    
    if ((*q).idxHead == (*q).idxTail) {
        (*q).idxHead = IDX_UNDEF;
        (*q).idxTail = IDX_UNDEF;
    } else {
        (*q).idxHead = (*q).idxHead + 1;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q) {
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    // KAMUS
    int i, j;
    // ALGORITMA
    if (isEmpty(q)) {
        printf("[]\n");
    } else {
        printf("[\n");
        for (i = q.idxHead; i <= q.idxTail; i++) {
            j = 0;
            if (i == q.idxTail) {
                printf("Harga: %d ", q.buffer[i].price);
                printf("Barang: ");
                while (q.buffer[i].name[j] != '\0') {
                    printf("%c", q.buffer[i].name[j]);
                    j++;
                }
                printf("\n");
            } else {
                printf("Harga: %d ", q.buffer[i].price);
                printf("Barang: ");
                while (q.buffer[i].name[j] != '\0') {
                    printf("%c", q.buffer[i].name[j]);
                    j++;
                }
                printf(",\n");
            }
        }
        printf("]\n");
    }
}
