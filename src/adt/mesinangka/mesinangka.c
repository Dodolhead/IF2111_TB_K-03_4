#include <stdio.h>
#include "mesinangka.h"

int currentAngka;
boolean EOPAngka;

void STARTANGKA() {
    START(); // Perbaikan dengan argumen filename
    EOPAngka = false;
    ADVANGKA();
}

void ADVANGKA() {
    while (!IsEOP() && (GetCC() < '0' || GetCC() > '9')) {
        ADV();
    }
    if (IsEOP()) {
        EOPAngka = true;
    } else {
        currentAngka = GetCC() - '0';
        ADV();
    }
}

int bacaAngka() {
    int total = 0;
    while (!IsEOPAngka()) {
        total = total * 10 + currentAngka;
        ADVANGKA();
    }
    return total;
}

boolean IsEOPAngka() {
    return EOPAngka;
}

int GetAngka() {
    return currentAngka;
}
