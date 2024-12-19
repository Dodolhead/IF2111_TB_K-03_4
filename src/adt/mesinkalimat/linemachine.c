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

void IgnoreTitikKoma()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (currentChar == ';')
    {
        ADV();
    }
}

void SalinInput() {
    ResetInput();  // Reset array
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != EOF))
    {
        currentInput.TabLine[i] = currentChar;
        // printf("%c", CC);
        i+= 1;
        ADV();
    }
    currentInput.Length = i;
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

void SalinRecord() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE))
    {
        currentLine.TabLine[i] = currentChar;
        i += 1;
        ADV();
    }
    currentLine.Length = i;
}

void STARTKALIMATINPUT() {
    START();
    IgnoreNewline();
    if (currentChar == ';'){
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinInput();
    }
}

void STARTCOMMAND() {
    START();
    IgnoreNewline();
    if (currentChar == ';'){
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinCommand();
    }
}

void SalinCommand() {
    ResetCommand();  // Reset array
    int i = 0;
    while ((currentChar != ' ') && (currentChar != ';') && (currentChar != EOF))
    {
        currentCommand.TabLine[i] = currentChar;
        // printf("%c", CC);
        i+= 1;
        ADV();
    }
    currentCommand.Length = i;
}

Kalimat DirectoryCommand(Kalimat file)
{
    Kalimat Direct;
    Direct.TabLine[0] = 'D';
    Direct.TabLine[1] = 'a';
    Direct.TabLine[2] = 't';
    Direct.TabLine[3] = 'a';
    Direct.TabLine[4] = '/';
    Direct.Length = 5;

    int i = Direct.Length;
    int j = 0;

    while (file.TabLine[j] != '\0')
    {
        Direct.TabLine[i] = file.TabLine[j];
        // printf("%c", CC);
        Direct.Length += 1;
        i++;
        j++;
    }

    Direct.TabLine[Direct.Length] = '\0';
    
    return Direct;
}

void ADVCOMMAND(){
    Ignoreblanks();
    if (currentChar == ';'){
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinCommand();
    }
}



void STARTKALIMATFILE(char filename[]) {
    STARTFILE(filename);
    IgnoreNewline();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
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

void ADVRECORD() {
    Ignoreblanks();
    IgnoreNewline();
    IgnoreTitikKoma();
    if (currentChar == ';' || currentChar == NEWLINE) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinRecord();
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

void ResetInput() {
    for (int i = 0; i < sizeof(currentInput.TabLine); i++) {
        currentInput.TabLine[i] = '\0';
        currentInput.Length = 0;
    }
}

void ResetCommand() {
    for (int i = 0; i < sizeof(currentCommand.TabLine); i++) {
        currentCommand.TabLine[i] = '\0';
        currentCommand.Length = 0;
    }
}

boolean isKalimatEqual(Kalimat K1, Kalimat K2) // belum dites
{   
    boolean equal = true;
    if (K1.Length == K2.Length)
    {
        int i = 0;
        while (i < K1.Length && equal)
        {
            if (K1.TabLine[i] != K2.TabLine[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

boolean isInputEqual(Kalimat Input, char * kata) // belum dites
{   
    boolean equal = true;
    if (Input.Length == Length(kata))
    {
        int i = 0;
        while (i < Input.Length && equal)
        {
            if (Input.TabLine[i] != kata[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

int Length(char * S2){
    int i = 0;

    while (S2[i] != '\0'){
        i++;
    }

    return i;
}


