#include "mesinkata.h"
#include "mesinkarakter.h"
#include <stdio.h>

boolean EndWord; // Define the EndWord variable
Word CurrentWord; // Define CurrentWord variable

void IgnoreBlanks() {
    while (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD()
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
    if (GetCC() == MARK) {
        EndWord = true;
    } else { 
        if (GetCC() == '\n') {
            ADV();
        }
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

// copyword 1
// void CopyWord()
// {
//     /* Mengakuisisi kata, menyimpan dalam currentWord
//        I.S. : currentChar adalah karakter pertama dari kata
//        F.S. : currentWord berisi kata yang sudah diakuisisi;
//               currentChar = BLANK atau currentChar = MARK;
//               currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
//               Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
//     CurrentWord.Length = 0;
//     while (currentChar != BLANK && currentChar != MARK)
//     {
//         if (CurrentWord.Length < NMax)
//         { // jika lebih akan terpotong
//             CurrentWord.TabWord[CurrentWord.Length++] = currentChar;
//             ADV();
//         }
//         else
//             break;
//     }
//     CurrentWord.TabWord[CurrentWord.Length] = '\0';
// }

// copyword 2 (buat cek 1 kalimat)
void CopySentence()
{
    while ((currentChar != MARK))
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
    CurrentWord.TabWord[i] = '\0'; // Tambahkan terminator string
    CurrentWord.Length = i;       // Simpan panjang kata
    IgnoreBlanks();               // Lewati karakter kosong setelah kata
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
