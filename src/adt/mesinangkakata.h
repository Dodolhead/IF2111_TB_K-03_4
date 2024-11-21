#ifndef __MESINANGKAKATA_H__
#define __MESINANGKAKATA_H__

#include "boolean.h"
#include "mesinkarakter.h"

#define NMax 100
#define BLANK ' '
#define MARK '\n'

typedef struct
{
    char TabAngka[NMax]; /* container penyimpan angka sebagai kata */
    int Length;          /* panjang deretan angka yang dibaca */
} Angka;

/* State Mesin Angka */
extern boolean EndAngka;
extern Angka CurrentAngka;

void IgnoreNonDigits();
/* Mengabaikan satu atau beberapa karakter non-digit
   I.S. : currentChar sembarang
   F.S. : currentChar = digit (angka 0-9) atau currentChar = MARK */

void STARTANGKAKATA();
/* I.S. : currentChar sembarang
   F.S. : EndAngka = true, dan currentChar = MARK;
          atau EndAngka = false, CurrentAngka adalah deretan angka yang sudah diakuisisi */

void ADVANGKAKATA();
/* I.S. : currentChar adalah karakter pertama angka berikutnya
   F.S. : CurrentAngka adalah angka terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari angka berikutnya, mungkin MARK
          Jika currentChar = MARK, EndAngka = true */

void CopyAngka();
/* Mengakuisisi angka, menyimpan dalam CurrentAngka
   I.S. : currentChar adalah karakter pertama dari deretan angka
   F.S. : CurrentAngka berisi angka yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          Jika panjang angka melebihi NMax, maka sisa angka "dipotong" */

#endif
