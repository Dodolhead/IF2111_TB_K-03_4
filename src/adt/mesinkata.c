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
    IgnoreBlanks();  // Abaikan spasi awal

    CurrentWord.Length = 0; // Reset panjang kata

    while (currentChar != ' ' && currentChar != MARK && CurrentWord.Length < NMax) {
        CurrentWord.TabWord[CurrentWord.Length] = currentChar; // Tambahkan karakter ke kata
        CurrentWord.Length++;
        ADV(); // Pindah ke karakter berikutnya
    }
    
    IgnoreBlanks(); // Abaikan spasi setelah kata
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