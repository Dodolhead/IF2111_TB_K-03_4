#ifndef __MESIN_ANGKA_H_
#define __MESIN_ANGKA_H_

#include "../../adt/boolean/boolean.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/mesinkarakter/mesinkarakter.h"

/* State Mesin */
extern int currentAngka;
extern boolean EOPAngka;

void STARTANGKA(char* filename);
/* Mesin siap dioperasikan untuk membaca angka.
   I.S. : sembarang
   F.S. : currentAngka adalah angka pertama yang terbaca.
          Jika currentAngka != MARK maka EOPAngka akan padam (false)
          Jika currentAngka = MARK maka EOPAngka akan menyala (true) */

void ADVANGKA();
/* Pita dimajukan hingga menemukan angka berikutnya.
   I.S. : currentAngka adalah angka terakhir yang terbaca.
   F.S. : currentAngka adalah angka berikutnya,
          Jika tidak ada lagi angka di pita, maka EOPAngka akan menyala (true). */

int bacaAngka();

int arrayToInteger(char arr[], int length);

boolean IsEOPAngka();
/* Mengirimkan true jika currentChar = MARK */

int GetAngka();
/* Mengirimkan angka yang terbaca pada currentAngka. */

#endif

