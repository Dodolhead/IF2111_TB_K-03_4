#ifndef LISTUSER_H
#define LISTUSER_H

#include "boolean.h"
#include "../../utilities.h"

#define MaxEl 100
#define MarkNumber -9999   
#define MarkName ""       
#define InvalidIdx -1      

typedef int IdxType;      
typedef struct {
    char name[50];        
    char password[50];    
    int money;            
} User;                   

typedef struct {
    User A[MaxEl];       
} List;                   

/* Primitif List */
List MakeList();
/* Membentuk list kosong dengan elemen yang diisi MarkNumber/MarkName */

boolean IsListEmpty(List U);
/* Mengembalikan true jika list kosong */

int GetMoney(List U, IdxType i);
void GetName(List U, IdxType i, char* buffer);
void GetPassword(List U, IdxType i, char* buffer);
/* Mengambil elemen pada indeks ke-i */

void Set(List *U, IdxType i, int money, char* name, char* password);
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

boolean Search(List U, char* X);
/* Mengecek apakah elemen X terdapat dalam list */

void InsertFirst(List *U, int money, char* name, char* password);
/* Menyisipkan elemen di posisi pertama */

void InsertAt(List *U, int money, char* name, char* password, IdxType i);
/* Menyisipkan elemen di posisi indeks ke-i */

void InsertLast(List *U, int money, char* name, char* password);
/* Menyisipkan elemen di posisi terakhir */

void DeleteFirst(List *U);
/* Menghapus elemen di posisi pertama */

void DeleteAt(List *U, IdxType i);
/* Menghapus elemen di posisi indeks ke-i */

void DeleteFirst(List *U);
/* Menghapus elemen di posisi terakhir */

#endif /* LISTUSER_H */
