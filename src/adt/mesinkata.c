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
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(filename);
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
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
        IgnoreBlanks(); 
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