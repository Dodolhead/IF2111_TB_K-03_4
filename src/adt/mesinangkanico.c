#include <stdio.h>
#include "mesinangka.h"
#include "mesinkarakter.h"
#include "mesinkata.h" // Menggunakan Mesin Karakter sebagai dasar

int currentAngka;
boolean EndAngka;


int arrayToInteger(char arr[], int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result = result * 10 + (arr[i] - '0');
    }
    return result;
}

void STARTANGKA() {
    IgnoreBlanks();
    if (IsEOP()) {
        EndAngka = true;
        currentAngka = 0;
        return;
    }

    char temp[20]; // Buffer untuk angka
    int index = 0;

    while ((currentChar >= '0' && currentChar <= '9') && !IsEOP() && index < 20) {
        temp[index++] = currentChar;
        ADV();
    }

    currentAngka = arrayToInteger(temp, index); // Konversi angka
    EndAngka = IsEOP();
}

void ADVANGKA() {
    IgnoreBlanks();
    char temp[20];
    int index = 0;

    while (currentChar >= '0' && currentChar <= '9' && !IsEOP() && index < 20) {
        temp[index++] = currentChar;
        ADV();
    }

    currentAngka = arrayToInteger(temp, index);
    EndAngka = IsEOP();
}

boolean IsEOPAngka(){
    return EndAngka;
}

