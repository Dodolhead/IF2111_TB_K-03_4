#include <stdio.h>
#include "listuser.h"

List MakeList(){
    List U;
    for (int i = 0; i < MaxEl; i++){
        U.A[i].money = MarkNumber;
        U.A[i].name[0] = MarkName[0];
        U.A[i].password[0] = MarkName[0];
    }
    return U;
}
/* Membentuk list kosong dengan elemen yang diisi MarkNumber/MarkName */

boolean IsListEmpty(List U){
    return (U.A[0].money == MarkNumber && U.A[0].name[0] == MarkName[0] && U.A[0].password[0] == MarkName[0]);
}
/* Mengembalikan true jika list kosong */

User Get(List U, IdxType i){
    return U.A[i];
}
/* Mengambil elemen pada indeks ke-i */

void Set(List *U, IdxType i, int money, char* name, char* password){
    U->A[i].money = money;
    U->A[i].name = 
}
/* Mengubah elemen pada indeks ke-i dengan nilai baru */

int Length(List U) {
    int count = 0;
    while (count < MaxEl && U.A[count].name != MarkName) {
        count++;
    }
    return count;
}
/* Mengembalikan jumlah elemen efektif dalam list */

IdxType FirstIdx(List U){
    return 0;
}
/* Mengembalikan indeks elemen pertama */

IdxType LastIdx(List U){
    return Length(U) - 1;
}
/* Mengembalikan indeks elemen terakhir */

boolean IsIdxValid(List U, IdxType i){
    return i < MaxEl && i >= 0;
}
/* Mengecek apakah indeks valid untuk list */

boolean IsIdxEff(List U, IdxType i){
    return i <= LastIdx(U) && i >= FirstIdx(U);
}
/* Mengecek apakah indeks efektif (elemen diisi) dalam list */

boolean Search(List U, User X){
    
}
/* Mengecek apakah elemen X terdapat dalam list */

void InsertFirst(List *U, User X);
/* Menyisipkan elemen di posisi pertama */

void InsertAt(List *U, User X, IdxType i);
/* Menyisipkan elemen di posisi indeks ke-i */

void InsertLast(List *U, User X);
/* Menyisipkan elemen di posisi terakhir */

void DeleteFirst(List *U);
/* Menghapus elemen di posisi pertama */

void DeleteAt(List *U, IdxType i);
/* Menghapus elemen di posisi indeks ke-i */

void DeleteLast(List *U);
/* Menghapus elemen di posisi terakhir */

List Concat(List U1, List U2);
/* Menggabungkan dua list menjadi satu */