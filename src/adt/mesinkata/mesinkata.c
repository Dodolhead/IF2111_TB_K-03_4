#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
     I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK || currentChar == NEWLINE)
    {
        ADV();
    }
}

void STARTWORD()
{
    START();
    IgnoreBlanks();
    copyString(currentWord.TabWord, "");
    currentWord.Length = 0;
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void STARTSENTENCE() {
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        endWord = true;
    } 
    else {
        endWord = false;
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
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void CopyWord() {
    int i = 0;
    while ( currentChar != MARK ) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.TabWord[i] = '\0'; 
    currentWord.Length = i;     
    IgnoreBlanks();             
}

void CopySentence()
{
    while ((currentChar != MARK))
    {
        if (currentWord.Length < NMax)
        {
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
        }
        ADV();
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
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentChar != NEWLINE)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord() {
    return endWord;
}