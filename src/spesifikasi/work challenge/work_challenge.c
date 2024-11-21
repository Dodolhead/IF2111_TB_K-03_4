#include <stdio.h>
#include "..\..\..\dictionary.h"
#include "..\..\..\dictionary.c" 
#include "..\..\adt\mesinkata.c" 
#include "..\..\adt\mesinkarakter.c" 
#include "..\..\adt\mesinangka.c"
#include "work_challenge.h"
#include <stdlib.h>
#include <time.h>

int random(){
    srand(time(0));
    int lower = 1, upper = 100;
    int randomNumber = (rand() % (upper - lower + 1)) + lower;
    return randomNumber;
}

void tebakAngka(int* money) {
    int total = 0;
    int multiplier = 1;
    int getMoney = 500;
    int angka_random = random();
    for (int i =0;i<10;i++){
        printf("Tebak Angka:\n");
        printf(">> ");
        STARTANGKA();
        while (!IsEOPAngka()) {
            total = total * 10 + currentAngka;
            ADVANGKA();
        }
        if (total == angka_random) {
            printf("Tebakanmu benar! %d rupiah telah ditambahkan ke akun anda.\n", getMoney);
        }
        else if(total < angka_random){
            printf("Tebakanmu lebih kecil dari angka yang ditentukan!\n");
            getMoney -= 20;
        }
        else if(total > angka_random){
            printf("Tebakanmu lebih besar dari angka yang ditentukan!\n");
            getMoney -= 20;
        }
    }
    printf("Angka yang ditentukan adalah %d\n", angka_random);
}

void workChallenge(int* money) {
    printf("Daftar challenge yang tersedia:");
    printf("1. Tebak Angka (biaya main=200");
    printf("2. W0RDL399 (biaya main=500)");

}

int main(){
    int money = 0;
    tebakAngka(&money);
    printf("%d",money);
}