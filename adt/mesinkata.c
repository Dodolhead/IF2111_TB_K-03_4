#include "mesinkata.h"
#include "mesinkarakter.h"
#include <stdio.h>

boolean EndWord; // Define the EndWord variable
Word CurrentWord; // Define CurrentWord variable

void IgnoreBlanks() {
    while (currentChar == BLANK && currentChar != MARK) {
        ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } 
    else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } 
    else {
        CopyWord();
    }
}

void CopyWord() {
    int i = 0;
    while (currentChar != BLANK && currentChar != MARK && i < NMax) {
        CurrentWord.TabWord[i] = currentChar; // Use CurrentWord
        ADV();
        i++;
    }
    CurrentWord.Length = i;
    IgnoreBlanks();
}
boolean isEndWord(){
    return EndWord;
}