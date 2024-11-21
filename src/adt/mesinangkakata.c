#include "mesinangkakata.h"
#include <stdio.h>

boolean EndAngka;
Angka CurrentAngka;

void IgnoreNonDigits() {
    while ((currentChar < '0' || currentChar > '9') && currentChar != MARK) {
        ADV(); // Lewati semua karakter non-digit
    }
}

void STARTANGKAKATA() {
    START();
    IgnoreNonDigits();
    if (currentChar == MARK) {
        EndAngka = true;
    } else {
        EndAngka = false;
        CopyAngka();
    }
}

void ADVANGKAKATA() {
    IgnoreNonDigits();
    if (currentChar == MARK) {
        EndAngka = true;
    } else {
        CopyAngka();
    }
}

void CopyAngka() {
    CurrentAngka.Length = 0;

    while (currentChar >= '0' && currentChar <= '9' && CurrentAngka.Length < NMax) {
        CurrentAngka.TabAngka[CurrentAngka.Length] = currentChar;
        CurrentAngka.Length++;
        ADV(); // Lanjutkan ke karakter berikutnya
    }

    CurrentAngka.TabAngka[CurrentAngka.Length] = '\0'; // Null-terminate
    IgnoreNonDigits(); // Abaikan karakter non-digit setelah angka
}
