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

void CopyWord(){
    // int i = 0;
    // CurrentWord.Length = 0;

    // while (currentChar != BLANK && currentChar != MARK && i < NMax) {
    //     CurrentWord.TabWord[i] = currentChar; 
    //     ADV();
    //     i++;
    // }
    // CurrentWord.Length = i;
    // IgnoreBlanks();

    // while ((currentChar != MARK))
    // {
    //     if (CurrentWord.Length < NMax)
    //     {
    //         CurrentWord.TabWord[CurrentWord.Length] = currentChar;
    //         CurrentWord.Length++;
    //     }
    //     ADV();
    // }
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    CurrentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK)
    {
        if (CurrentWord.Length < NMax)
        { // jika lebih akan terpotong
            CurrentWord.TabWord[CurrentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord(){
    return EndWord;
}