#include <stdio.h>
#include "..\..\..\dictionary.c" 
#include "..\..\adt\mesinkata.c" 
#include "..\..\adt\mesinkarakter.c" 
#include "..\..\adt\mesinangka.c"
#include "work_challenge.h"
#include <stdlib.h>
#include <time.h>

int bacaAngka(){
    int total=0;
    while (!IsEOPAngka()) {
        total = total * 10 + currentAngka;
    ADVANGKA();
    }
    return total;
}
int random(int lower, int upper){
    srand(time(0));
    int randomNumber = (rand() % (upper - lower + 1)) + lower;
    return randomNumber;
}

void tebakAngka(int* money) {   
    int tebakan;
    int multiplier = 1;
    int getMoney = 500;
    int loss = 0;
    int angka_random = random(0,100);
    for (int i =0;i<10;i++){
        printf("Tebak Angka:\n");
        printf(">> ");
        STARTANGKA();
        tebakan = bacaAngka();
        if (tebakan == angka_random) {
            printf("Tebakanmu benar! %d rupiah telah ditambahkan ke akun anda.\n", getMoney);
            *money += getMoney;
            break;
        }
        else if(tebakan < angka_random){
            printf("Tebakanmu lebih kecil dari angka yang ditentukan!\n");
            getMoney -= 20;
            loss++;
            tebakan = 0;
        }
        else if(tebakan > angka_random){
            printf("Tebakanmu lebih besar dari angka yang ditentukan!\n");
            getMoney -= 20;
            loss ++;
            tebakan = 0;
        }
    }
    if (loss == 10) {
        printf("Sayang sekali, angka yang ditentukan adalah %d\n", angka_random);
    }
}
void wordl3(int* money) {
    int getMoney = 1500;
    char matrix[5][5] = {
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'}
    };

    char feedbackMatrix[5][5] = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };

    int random_number = random(0, 9);
    char koleksi[10][5] = {
        "HELLO", "WORLD", "LUCKY", "GRAIN", "LUNCH", "BERRY", "VOLVO", "TRULY", "STORY", "APPLE"
    };
    char kata[5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            kata[i] = koleksi[random_number][i];
        }
    }
    int isCorrect = 0;

    for (int i = 0; i < 5; i++) {
        printf("Masukkan kata tebakan Anda:\n");
        printf(">> ");
        STARTWORD();

        if (CurrentWord.Length != 5) {
            printf("Kata harus terdiri dari 5 huruf, jangan rusak permainan ya kids :)\n");
            break;
        } 

        int correctCount = 0;
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = CurrentWord.TabWord[j];
            if (CurrentWord.TabWord[j] == kata[j]) {
                feedbackMatrix[i][j] = '*';
                correctCount++;
            } else {
                feedbackMatrix[i][j] = '%';
            }
        }

        if (correctCount == 5) {
            for (int j = 0; j < 5; j++) {
                feedbackMatrix[i][j] = ' ';
            }
            isCorrect = 1;
        }

        for (int k = 0; k < 5; k++) {
            for (int j = 0; j < 5; j++) {
                printf("%c", matrix[k][j]);
                if (feedbackMatrix[k][j] != ' ') {
                    printf("%c ", feedbackMatrix[k][j]);
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }

        if (isCorrect) {
            *money += getMoney;
            printf("Selamat, Anda menang!\n+%d rupiah telah ditambahkan ke akun Anda.\n", getMoney);
            break;
        } else {
            printf("Tebakan Anda salah, silakan coba lagi!\n");
        }
    }

    if (!isCorrect) {
        printf("Permainan selesai. Coba lagi lain waktu!\n");
    }
}


void workChallenge(int* money) {
    int input;
    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200\n");
    printf("2. W0RDL399 (biaya main=500)\n>> ");
    STARTANGKA();
    input = bacaAngka();
    if (input == 1) {
        tebakAngka(money);
    } 
    else if (input == 2) {
        wordl3(money);
    }

}


int main(){
    int money = 0;
    workChallenge(&money);
    printf("%d",money);
}