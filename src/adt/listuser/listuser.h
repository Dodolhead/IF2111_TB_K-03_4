#ifndef LISTUSER_H
#define LISTUSER_H

#include "../../adt/boolean/boolean.h"
#include "../../adt/listlinier/listlinier.h"
#include "../../adt/map/map.h"
#include "../../adt/stack/stack.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/mesinkarakter/mesinkarakter.h"
#include "../../adt/mesinangka/mesinangka.h"
#include "../../../utilities.h"

#define MaxEl 100
#define MarkNumber -9999   
#define MarkName ""       
#define InvalidIdx -1      

typedef int IdxType;      
typedef struct {
    char name[50];
    char password[50];
    int money;
    Map keranjang;
    Stack riwayat_pembelian;
    LinkedList wishlist;
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
void SetKeranjang(List *U, IdxType i, Map keranjang);
void SetRiwayat(List *U, IdxType i, Stack riwayat_pembelian);
void SetWishlist(List *U, IdxType i, LinkedList wishlist);
/* Mengambil elemen pada indeks ke-i */

void Set(List *U, IdxType i, int money, char* name, char* password, Map keranjang, Stack riwayat_pembelian, LinkedList wishlist);
/* Mengubah elemen pada indeks ke-i dengan nilai baru */

int ListUserLength(List U);
/* Mengembalikan jumlah elemen efektif dalam list */

IdxType FirstIdx(List U);
/* Mengembalikan indeks elemen pertama */

IdxType LastIdx(List U);
/* Mengembalikan indeks elemen terakhir */

boolean IsIdxValid(List U, IdxType i);
/* Mengecek apakah indeks valid untuk list */

boolean IsIdxEff(List U, IdxType i);
/* Mengecek apakah indeks efektif (elemen diisi) dalam list */

boolean ListSearch(List U, char* X);
/* Mengecek apakah elemen X terdapat dalam list */

void InsertListFirst(List *U, int money, char* name, char* password, Map keranjang, Stack riwayat_pembelian, LinkedList wishlist);
/* Menyisipkan elemen di posisi pertama */

void InsertListAt(List *U, int money, char* name, char* password, Map keranjang, Stack riwayat_pembelian, LinkedList wishlist, IdxType i);
/* Menyisipkan elemen di posisi indeks ke-i */

void InsertListLast(List *U, int money, char* name, char* password, Map keranjang, Stack riwayat_pembelian, LinkedList wishlist);
/* Menyisipkan elemen di posisi terakhir */

void DeleteRiwayat(List *U, IdxType i);
void DeleteKeranjang(List *U, IdxType i);
void DeleteWishlist(List *U, IdxType i);


void DeleteListFirst(List *U);
/* Menghapus elemen di posisi pertama */

void DeleteListAt(List *U, IdxType i);
/* Menghapus elemen di posisi indeks ke-i */

void DeleteListLast(List *U);
/* Menghapus elemen di posisi terakhir */

void AddToWishlist(User *U, infoLinkedListtype item);
addressLinkedList SearchWishList(User *U, infoLinkedListtype item);
int WishlistCount(User *U);
void DelPWishList(LinkedList *L, infoLinkedListtype X);
void AddToKeranjang(User *U, keytype k, valuetype v);
void RemoveFromKeranjang(User *U, keytype k);
void PrintUserInfo(List U, IdxType i);

#endif /* LISTUSER_H */
