#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"


boolean IsLinkedListEmpty (LinkedList L){
    return First(L) == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateLinkedListEmpty (LinkedList *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressLinkedList Alokasi(infoLinkedListtype X) {
    addressLinkedList P = (addressLinkedList)malloc(sizeof(ElmtLinkedList));
    if (P != Nil) {
        Info(P) = X;  // Salin pointer ke info
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan addressLinkedList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLinkedList tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (addressLinkedList *P){
    free(*P);
    *P = Nil;
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLinkedList LinkedListSearch (LinkedList L, infoLinkedListtype X){
    addressLinkedList P = First(L);
    while (P != Nil) {
        if (Info(P) == X) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}
/* Mencari apakah ada elemen LinkedList dengan info(P)= X */
/* Jika ada, mengirimkan addressLinkedList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(LinkedList *L, infoLinkedListtype X) {
    addressLinkedList P = Alokasi(X);
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast(LinkedList *L, infoLinkedListtype X) {
    addressLinkedList P = Alokasi(X);
    if (P != Nil) {
        if (IsLinkedListEmpty(*L)) {
            First(*L) = P;
        } else {
            addressLinkedList Last = First(*L);
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(LinkedList *L, infoLinkedListtype *X) {
    if (!IsLinkedListEmpty(*L)) {
        addressLinkedList P = First(*L);
        *X = Info(P);
        First(*L) = Next(P);
        Dealokasi(&P);
    }
}

void DelVLast(LinkedList *L, infoLinkedListtype *X) {
    if (!IsLinkedListEmpty(*L)) {
        addressLinkedList P = First(*L);
        addressLinkedList Prec = Nil;
        while (Next(P) != Nil) {
            Prec = P;
            P = Next(P);
        }
        *X = Info(P);
        if (Prec == Nil) {
            First(*L) = Nil;
        } else {
            Next(Prec) = Nil;
        }
        Dealokasi(&P);
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertLinkedListFirst(LinkedList *L, addressLinkedList P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertLinkedListAfter(LinkedList *L, addressLinkedList P, addressLinkedList Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLinkedListLast(LinkedList *L, addressLinkedList P) {
    if (IsLinkedListEmpty(*L)) {
        First(*L) = P;
    } else {
        addressLinkedList Last = First(*L);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelLinkedListFirst(LinkedList *L, addressLinkedList *P) {
    if (!IsLinkedListEmpty(*L)) {
        *P = First(*L);
        First(*L) = Next(*P);
        Next(*P) = Nil;
    }
}

void DelLinkedListP(LinkedList *L, infoLinkedListtype X) {
    addressLinkedList P = First(*L);
    addressLinkedList Prec = Nil;

    while (P != Nil && Info(P) != X) {
        Prec = P;
        P = Next(P);
    }

    if (P != Nil) {
        if (Prec == Nil) {
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        Dealokasi(&P);
    }
}

void DelLinkedListLast(LinkedList *L, addressLinkedList *P) {
    addressLinkedList Last = First(*L);
    addressLinkedList Prec = Nil;

    while (Next(Last) != Nil) {
        Prec = Last;
        Last = Next(Last);
    }

    *P = Last;
    if (Prec == Nil) {
        First(*L) = Nil;
    } else {
        Next(Prec) = Nil;
    }
}

void DelLinkedListAfter(LinkedList *L, addressLinkedList *Pdel, addressLinkedList Prec) {
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LinkedList ******************/
void PrintInfo(LinkedList L) {
    addressLinkedList P = First(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil) printf(",");
    }
    printf("]\n");
}

int NbElmt(LinkedList L) {
    int count = 0;
    addressLinkedList P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

infoLinkedListtype Max(LinkedList L) {
    infoLinkedListtype max = Info(First(L));
    addressLinkedList P = Next(First(L));
    while (P != Nil) {
        if (Info(P) > max) {
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

addressLinkedList AdrMax(LinkedList L) {
    infoLinkedListtype max = Max(L);
    addressLinkedList P = First(L);
    while (P != Nil) {
        if (Info(P) == max) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

infoLinkedListtype Min(LinkedList L) {
    infoLinkedListtype min = Info(First(L));
    addressLinkedList P = Next(First(L));
    while (P != Nil) {
        if (Info(P) < min) {
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

addressLinkedList AdrMin(LinkedList L) {
    infoLinkedListtype min = Min(L);
    addressLinkedList P = First(L);
    while (P != Nil) {
        if (Info(P) == min) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

void InversLinkedList(LinkedList *L) {
    addressLinkedList P = First(*L);
    addressLinkedList Prev = Nil, NextNode;

    while (P != Nil) {
        NextNode = Next(P);
        Next(P) = Prev;
        Prev = P;
        P = NextNode;
    }
    First(*L) = Prev;
}

void Konkat1(LinkedList *L1, LinkedList *L2, LinkedList *L3) {
    CreateLinkedListEmpty(L3);
    First(*L3) = First(*L1);

    if (!IsLinkedListEmpty(*L1)) {
        addressLinkedList Last = First(*L1);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        Next(Last) = First(*L2);
    } else {
        First(*L3) = First(*L2);
    }

    CreateLinkedListEmpty(L1);
    CreateLinkedListEmpty(L2);
}


// int main(){
//     LinkedList fibonacci;
//     addressLinkedList P1, P2;
//     infoLinkedListtype i = 2, el, x1, x2;
//     CreateEmpty(&fibonacci);
//     scanf("%d", &el);
//     if (el == 1)
//     {
//         scanf("%d", &x1);
//         InsVFirst(&fibonacci, x1);
//     }
//     else if (el > 1)
//     {
//         scanf("%d %d", &x1, &x2);
//         InsVFirst(&fibonacci, x1);
//         InsVLast(&fibonacci, x2);
//         P1 = First(fibonacci);
//         P2 = Next(P1);
//         while (i < el)
//         {
//             InsVLast(&fibonacci, Info(P1) + Info(P2));
//             P1 = Next(P1);
//             P2 = Next(P2);
//             i++;
//         }
//     }
//     PrintInfo(fibonacci);
// }

// int main(){
//     addressLinkedList P;
//     int n;
//     int temp;
//     int el1;
//     int el2;
//     int next;
//     LinkedList l;
//     CreateEmpty(&l);
//     scanf("%d", &n);
//     if (n == 1){
//         scanf("%d", &el1);
//         InsVFirst(&l, el1);
//         PrintInfo(l);
//     }
//     else if (n > 1){
//         scanf("%d", &el1);
//         scanf("%d", &el2);
//         InsVLast(&l, el1);
//         InsVLast(&l, el2);
//         next = el1;
//         for (int i=0;i<n;i++){
//             next+= el2;
//             temp = el2;
//             InsVLast(&l, next);
//             el2 = next;
//             next = temp;
//         }
//         PrintInfo(l);
//     }
// }