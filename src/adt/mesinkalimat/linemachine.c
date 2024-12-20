#include <stdio.h>
#include <stdlib.h>
#include "linemachine.h"
#include "../../adt/boolean/boolean.h"

boolean EndKalimat;
Kalimat currentLine;
Kalimat currentInput;
Kalimat currentCommand;

void Ignoreblanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (currentChar == ' ')
    {
        ADV();
    }
}

void IgnoreNewline()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (currentChar == NEWLINE)
    {
        ADV();
    }
}





void SalinKalimat() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != EOF))
    {
        currentLine.TabLine[i] = currentChar;

        i+= 1;
        ADV();
    }
    currentLine.Length = i;
}

void SalinSatuKata() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((currentChar != ' ') && (currentChar != MARK))
    {
        currentLine.TabLine[i] = currentChar;
        i += 1;
        ADV();
    }
    currentLine.Length = i;
}

void ADVKALIMAT(){
    IgnoreNewline();
    Ignoreblanks();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void ADVSATUKATA() {
    Ignoreblanks();
    IgnoreNewline();
    if (currentChar == ' ') {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinSatuKata();
    }
}

void copyKalimat (Kalimat k1, Kalimat *k2){
    k2->Length=k1.Length;
    for (int i=0;i<=k1.Length;i++){
        k2->TabLine[i] = k1.TabLine[i];
    }
}

void ResetKalimat() {
    for (int i = 0; i < sizeof(currentLine.TabLine); i++) {
        currentLine.TabLine[i] = '\0';
        currentLine.Length = 0;
    }
}

int Length(char * S2){
    int i = 0;

    while (S2[i] != '\0'){
        i++;
    }

    return i;
}


