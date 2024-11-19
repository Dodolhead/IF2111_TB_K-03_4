#ifndef LISTUSER_H
#define LISTUSER_H

#include "boolean.h"

/* Konstanta */
#define MaxEl 100
#define MarkNumber -9999   /* Nilai penanda elemen tidak valid */
#define MarkName ""        /* Nilai penanda string kosong */
#define InvalidIdx -1      /* Indeks tidak valid */

/* Tipe Data */
typedef int IdxType;       /* Tipe indeks */
typedef struct {
    char name[50];         /* Nama pengguna */
    char password[50];     /* Kata sandi pengguna */
    int money;             /* Uang yang dimiliki pengguna */
} User;                    /* Tipe elemen */

typedef struct {
    User A[MaxEl];         /* Array elemen */
} List;                    /* Tipe list */

/* Primitif List */
List MakeList();
/* Membentuk list kosong dengan elemen yang diisi MarkNumber/MarkName */

boolean IsListEmpty(List U);
/* Mengembalikan true jika list kosong */

User Get(List U, IdxType i);
/* Mengambil elemen pada indeks ke-i */

void Set(List *U, IdxType i, User v);
/* Mengubah elemen pada indeks ke-i dengan nilai baru */

int Length(List U);
/* Mengembalikan jumlah elemen efektif dalam list */

IdxType FirstIdx(List U);
/* Mengembalikan indeks elemen pertama */

IdxType LastIdx(List U);
/* Mengembalikan indeks elemen terakhir */

boolean IsIdxValid(List U, IdxType i);
/* Mengecek apakah indeks valid untuk list */

boolean IsIdxEff(List U, IdxType i);
/* Mengecek apakah indeks efektif (elemen diisi) dalam list */

boolean Search(List U, User X);
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
#endif /* LISTUSER_H */
