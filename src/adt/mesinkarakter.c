#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(char *filename) {
    pita = fopen(filename, "r");
    if (pita == NULL) {
        printf("File tidak ditemukan: %s\n", filename);
        EOP = true;
    } else {
        ADV();
    }
}

void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (retval == EOF);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    return currentChar;
}

boolean IsEOP() {
    return EOP;
}
