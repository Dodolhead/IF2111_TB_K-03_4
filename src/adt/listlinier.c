#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"


boolean IsListEmpty (List L){
    return First(L) == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressList Alokasi(infoListtype X) {
    addressList P = (addressList)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;  // Salin pointer ke info
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (addressList *P){
    free(*P);
    *P = Nil;
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList Search (List L, infoListtype X){
    addressList P = First(L);
    while (P != Nil) {
        if (Info(P) == X) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infoListtype X) {
    addressList P = Alokasi(X);
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast(List *L, infoListtype X) {
    addressList P = Alokasi(X);
    if (P != Nil) {
        if (IsListEmpty(*L)) {
            First(*L) = P;
        } else {
            addressList Last = First(*L);
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infoListtype *X) {
    if (!IsListEmpty(*L)) {
        addressList P = First(*L);
        *X = Info(P);
        First(*L) = Next(P);
        Dealokasi(&P);
    }
}

void DelVLast(List *L, infoListtype *X) {
    if (!IsListEmpty(*L)) {
        addressList P = First(*L);
        addressList Prec = Nil;
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
void InsertFirst(List *L, addressList P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, addressList P, addressList Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(List *L, addressList P) {
    if (IsListEmpty(*L)) {
        First(*L) = P;
    } else {
        addressList Last = First(*L);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, addressList *P) {
    if (!IsListEmpty(*L)) {
        *P = First(*L);
        First(*L) = Next(*P);
        Next(*P) = Nil;
    }
}

void DelP(List *L, infoListtype X) {
    addressList P = First(*L);
    addressList Prec = Nil;

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

void DelLast(List *L, addressList *P) {
    addressList Last = First(*L);
    addressList Prec = Nil;

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

void DelAfter(List *L, addressList *Pdel, addressList Prec) {
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L) {
    addressList P = First(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil) printf(",");
    }
    printf("]\n");
}

int NbElmt(List L) {
    int count = 0;
    addressList P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

infoListtype Max(List L) {
    infoListtype max = Info(First(L));
    addressList P = Next(First(L));
    while (P != Nil) {
        if (Info(P) > max) {
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

addressList AdrMax(List L) {
    infoListtype max = Max(L);
    addressList P = First(L);
    while (P != Nil) {
        if (Info(P) == max) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

infoListtype Min(List L) {
    infoListtype min = Info(First(L));
    addressList P = Next(First(L));
    while (P != Nil) {
        if (Info(P) < min) {
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

addressList AdrMin(List L) {
    infoListtype min = Min(L);
    addressList P = First(L);
    while (P != Nil) {
        if (Info(P) == min) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

void InversList(List *L) {
    addressList P = First(*L);
    addressList Prev = Nil, NextNode;

    while (P != Nil) {
        NextNode = Next(P);
        Next(P) = Prev;
        Prev = P;
        P = NextNode;
    }
    First(*L) = Prev;
}

void Konkat1(List *L1, List *L2, List *L3) {
    CreateListEmpty(L3);
    First(*L3) = First(*L1);

    if (!IsListEmpty(*L1)) {
        addressList Last = First(*L1);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        Next(Last) = First(*L2);
    } else {
        First(*L3) = First(*L2);
    }

    CreateListEmpty(L1);
    CreateListEmpty(L2);
}


// int main(){
//     List fibonacci;
//     addressList P1, P2;
//     infoListtype i = 2, el, x1, x2;
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
//     addressList P;
//     int n;
//     int temp;
//     int el1;
//     int el2;
//     int next;
//     List l;
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