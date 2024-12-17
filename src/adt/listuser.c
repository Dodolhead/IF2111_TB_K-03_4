#include <stdio.h>
#include "listuser.h"
#include "../../utilities.c"

List MakeList() {
    List U;
    for (int i = 0; i < MaxEl; i++) {
        U.A[i].money = MarkNumber;
        U.A[i].name[0] = '\0';
        U.A[i].password[0] = '\0';
    }
    return U;
}
/* Membentuk list kosong dengan elemen yang diisi MarkNumber/MarkName */

boolean IsListEmpty(List U) {
    return (U.A[0].money == MarkNumber && U.A[0].name[0] == '\0' && U.A[0].password[0] == '\0');
}
/* Mengembalikan true jika list kosong */

int GetMoney(List U, IdxType i) {
    return U.A[i].money;
}

void GetName(List U, IdxType i, char* buffer) {
    copyString(buffer, U.A[i].name);
}

void GetPassword(List U, IdxType i, char* buffer) {
    copyString(buffer, U.A[i].password);
}

/* Mengambil elemen pada indeks ke-i */

void Set(List *U, IdxType i, int money, char* name, char* password) {
    U->A[i].money = money;
    copyString(U->A[i].name, name);
    copyString(U->A[i].password, password);
}
/* Mengubah elemen pada indeks ke-i dengan nilai baru */

int ListUserLength(List U) {
    int count = 0;
    while (count < MaxEl && U.A[count].money != MarkNumber) {
        count++;
    }
    return count;
}
/* Mengembalikan jumlah elemen efektif dalam list */

IdxType FirstIdx(List U) {
    return 0;
}
/* Mengembalikan indeks elemen pertama */

IdxType LastIdx(List U) {
    return Length(U) - 1;
}
/* Mengembalikan indeks elemen terakhir */

boolean IsIdxValid(List U, IdxType i) {
    return i < MaxEl && i >= 0;
}
/* Mengecek apakah indeks valid untuk list */

boolean IsIdxEff(List U, IdxType i) {
    return i <= LastIdx(U) && i >= FirstIdx(U);
}
/* Mengecek apakah indeks efektif (elemen diisi) dalam list */

boolean Search(List U, char* X) {
    for (int i = 0; i < Length(U); i++) {
        if (stringEquals(U.A[i].name, X)) {
            return true;
        }
    }
    return false;
}
/* Mengecek apakah elemen X terdapat dalam list */

void InsertFirst(List *U, int money, char* name, char* password) {
    InsertAt(U, money, name, password, 0);
}
/* Menyisipkan elemen di posisi pertama */

void InsertAt(List *U, int money, char* name, char* password, IdxType i) {
    if (Length(*U) < MaxEl && i >= 0 && i <= Length(*U)) {
        for (int j = Length(*U); j > i; j--) {
            U->A[j] = U->A[j - 1];
        }
        Set(U, i, money, name, password);
    }
}
/* Menyisipkan elemen di posisi indeks ke-i */

void InsertLast(List *U, int money, char* name, char* password) {
    if (Length(*U) < MaxEl) {
        Set(U, Length(*U), money, name, password);
    }
}
/* Menyisipkan elemen di posisi terakhir */

void DeleteFirst(List *U) {
    DeleteAt(U, 0);
}
/* Menghapus elemen di posisi pertama */

void DeleteAt(List *U, IdxType i) {
    int panjang = Length(*U);
    if (panjang > 0 && i >= 0 && i < panjang) {
        // Geser elemen dari indeks i ke depan
        for (IdxType j = i; j < panjang - 1; j++) {
            U->A[j] = U->A[j + 1];
        }
        // Hapus elemen terakhir (nilai tidak terpakai)
        U->A[panjang - 1].money = MarkNumber;
        U->A[panjang - 1].name[0] = '\0';
        U->A[panjang - 1].password[0] = '\0';

        // Update panjang list
        panjang--;  // Pastikan untuk mengurangi jumlah elemen
    }
}

/* Menghapus elemen di posisi indeks ke-i */

void DeleteLast(List *U) {
    DeleteAt(U, LastIdx(*U));
}
/* Menghapus elemen di posisi terakhir */

int main() {
    List U = MakeList();
    InsertFirst(&U, 100000, "admin", "admin");
    InsertAt(&U, 100000, "dapid", "idiot",1);
    InsertLast(&U, 50000, "user", "user");
    InsertLast(&U, 50000, "asu", "user");

    printf("Length before DeleteAt: %d\n", Length(U));
    DeleteAt(&U, 2);
    printf("Length after DeleteAt: %d\n", Length(U));


    char buffer[50];
    for (int i = 0; i < Length(U); i++) {
        printf("%d\n", GetMoney(U, i));
        GetName(U, i, buffer);
        printf("%s\n", buffer);
        GetPassword(U, i, buffer);
        printf("%s\n", buffer);
    }
}
