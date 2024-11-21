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
    *money -= 200;
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
    *money -= 500;
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

void quantumWordl3(int* money) {
    *money -= 5000;
    int getMoney = 10000;
    int winCount = 0;
    char matrix[5][5] = {
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'}
    };
    int random_number = random(0, 9);

    char koleksi1[10][5] = {
        "HELLO", "WORLD", "LUCKY", "GRAIN", "LUNCH", "BERRY", "VOLVO", "TRULY", "STORY", "APPLE"
    };
    char kata1[5];

    char koleksi2[10][5] = {
        "PEACE", "SMILE", "TRAIN", "BRAVE", "PIZZA", "FIGHT", "STORM", "WATCH", "HORSE", "CLOUD"
    };
    char kata2[5];

    char koleksi3[10][5] = {
        "GLORY", "NICEY", "LOVEL", "FLOOD", "JUMPY", "TIGER", "CLEAN", "SHARE", "PLANT", "FAVOR"
    };
    char kata3[5];

    char koleksi4[10][5] = {
        "STRAW", "BRAIN", "FLAME", "MONEY", "STAND", "PAPER", "STYLE", "FLYER", "LAUGH", "PULSE"
    };
    char kata4[5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            kata1[i] = koleksi1[random_number][i];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            kata2[i] = koleksi2[random_number][i];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            kata3[i] = koleksi3[random_number][i];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            kata4[i] = koleksi4[random_number][i];
        }
    }

    char* kataPilihan[4] = {
        kata1,kata2,kata3,kata4
    };

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 4; j++){
            int correctCount = 0;
            int isCorrect = 0;
            char kata[5];

            for (int k = 0; k < 5; k++) {
                kata[k] = kataPilihan[j][k];
            }
            printf("Masukkan kata tebakan Anda:\n");
            printf(">> ");
            STARTWORD();

            if (CurrentWord.Length != 5) {
                printf("Kata harus terdiri dari 5 huruf, jangan rusak permainan ya kids :)\n");
                break;
            } 

            for (int k = 0; k < 5; k++) {
                matrix[j][k] = CurrentWord.TabWord[k];
                if (CurrentWord.TabWord[k] == kata[k]) {
                    correctCount++;
                }
            }

            if (correctCount == 5) {
                isCorrect = 1;
            }

            for (int k = 0; k < 5; k++) {
                for (int j = 0; j < 5; j++) {
                    printf("%c ", matrix[k][j]);

                }
                printf("\n");
            }

            if (isCorrect) {
                printf("Tebakan Anda benar!\n");
                winCount++;
            } 
            else {
                for (int k = 0; k < 4; k++) 
                    for (int l = 0; l < 5; l++) {
                        matrix[k][l] = '_';
                    }
                printf("Tebakan Anda salah, silakan coba lagi!\n");
                winCount = 0;
                break;
            }
        }
        if (winCount == 4){
            printf("Selamat, Anda menang!\n+%d rupiah telah ditambahkan ke akun Anda.\n", getMoney);
            *money += getMoney;
            break;
        }
    }
}
void workChallenge(int* money) {
    int input;
    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200\n");
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("3. Quantum W0RDL399 (biaya main=5000)\n>> ");
    STARTANGKA();
    input = bacaAngka();
    if (input == 1 && *money >= 200) {
        tebakAngka(money);
    } 
    else if (input == 2 && *money >= 500) {
        wordl3(money);
    }
    else if (input == 3 && *money >= 5000) {
        quantumWordl3(money);
    }
    else{
        printf("Uang tidak cukup!\n");
    }
}


int main(){
    int money = 5001;
    workChallenge(&money);
    printf("%d",money);
}