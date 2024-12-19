#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
     I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (CurrentChar == BLANK || CurrentChar == NEWLINE)
    {
        ADV();
    }
}

void STARTWORD(char* filename)
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(filename);
    IgnoreBlanks();
    if (CurrentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void STARTSENTENCE()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopySentence();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (CurrentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
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
        {
            CurrentWord.TabWord[CurrentWord.Length] = currentChar;
            CurrentWord.Length++;
        }
        ADV();
    }
}

// copyword 3 (buat cek 1 kata 1 kata)
void CopyWord() {
    int i = 0;
    while (currentChar != BLANK && currentChar != MARK && i < NMax) {
        CurrentWord.TabWord[i] = currentChar; // Salin karakter
        ADV();
        i++;
    }
    CurrentWord.TabWord[CurrentWord.Length] = '\0';
}

boolean isEndWord() {
    return endWord;
}