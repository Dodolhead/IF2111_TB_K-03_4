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

void ADVUSER() {
    IgnoreBlanks(); 

    CurrentWord.Length = 0; 

    while (currentChar != ' ' && currentChar != MARK && CurrentWord.Length < NMax) {
        CurrentWord.TabWord[CurrentWord.Length] = currentChar;
        CurrentWord.Length++;
        ADV();
    }
    
    IgnoreBlanks(); 
}

void ADVONEWORD() {
    // Lewati karakter-karakter dalam kata pertama
    while (currentChar != BLANK && currentChar != MARK) {
        ADV(); // Pindahkan ke karakter berikutnya
    }

    // Lewati spasi setelah kata pertama
    while (currentChar == BLANK && currentChar != MARK) {
        ADV(); // Pindahkan ke karakter berikutnya
    }

    // Salin kata berikutnya ke CurrentWord
    CurrentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK) {
        if (CurrentWord.Length < NMax) {  // Pastikan tidak melebihi kapasitas
            CurrentWord.TabWord[CurrentWord.Length] = currentChar;
            CurrentWord.Length++;
            ADV();  // Pindahkan ke karakter berikutnya
        }
    }
}

void CopyWord(){
    CurrentWord.Length = 0;

    while (currentChar != MARK && CurrentWord.Length < NMax) {
        CurrentWord.TabWord[CurrentWord.Length] = currentChar;
        CurrentWord.Length++;
        ADV(); 
    }

    IgnoreBlanks(); 
}

boolean isEndWord(){
    return EndWord;
}

void stringCopy(char *destination, const char *source) {
    int i = 0;

    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
}
