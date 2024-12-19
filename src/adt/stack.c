#include <stdio.h>
#include "boolean.h"
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateStackEmpty (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S)==NilStack);
}

boolean IsStackFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S)==MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, char* name, int X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    int i;
    Top(*S) += 1;
    (*S).price = X;
    for (i = 0; name[i] != '\0'; i++) {
        (*S).name[i] = name[i];
    }
    (*S).name[i] = '\0';
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, char* name, int* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    int i;
    *X = (*S).price;
    for (i = 0; (*S).name[i] != '\0'; i++) {
        name[i] = (*S).name[i];
    }
    name[i] = '\0';
    Top(*S) -= 1;
}