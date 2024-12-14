#include <stdio.h>
#include "work.h"
#include "..\..\adt\mesinangka.c"
#include "..\..\..\utilities.c" 
#include "..\..\adt\mesinkata.c" 
#include "..\..\adt\mesinkarakter.c"  

void workDisplay() {
    printf("Daftar Pekerjaan:\n");
    printf("    1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("    2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("    3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("    4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("    5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
}

void delay(int n){
    unsigned tes = 10*10*10*10*10*10*10*10*10;
    int dot_counter = 0;
    int counter = 0;
    int time = 1;
    for (int i = 0; i < n; i++){
        for (int i = 0; i < tes; i++){
            counter ++;
            time ++;
            if (counter == n*10*10*10){
                printf("...");
                dot_counter ++;
                if (dot_counter == 3){
                    printf("\n");
                    dot_counter = 0;
                }
            }
        }
        counter =0;
        time =1;
    }
}


void doWork(int* money) {
    workDisplay(); 
    printf(">> ");
    STARTWORD();
    if (stringEquals(CurrentWord.TabWord, "Evil Lab Assistant")) {
        delay(14);
        printf("\n");
        *money += 100;
        printf("Anda mendapatkan 100 uang\n");
    } 
    else if(stringEquals(CurrentWord.TabWord, "OWCA Hiring Manager")) {
        delay(21);
        printf("\n");
        *money += 4200;
        printf("Anda mendapatkan 4200 uang\n");
    } 
    else if(stringEquals(CurrentWord.TabWord, "Cikapundunginator Caretaker")) {
        delay(30);
        printf("\n");
        *money += 7000;
        printf("Anda mendapatkan 7000 uang\n");
    } 
    else if(stringEquals(CurrentWord.TabWord, "Mewing Specialist")) {
        delay(22);
        printf("\n");
        *money += 10000;
        printf("Anda mendapatkan 10000 uang\n");
    }
    else if(stringEquals(CurrentWord.TabWord, "Inator Connoisseur")) {
        delay(15);
        printf("\n");
        *money += 997;
        printf("Anda mendapatkan 997 uang\n");
    }
    else {
        printf("%s Pekerjaan tidak ditemukan\n", CurrentWord.TabWord);
    }
//     printf(">> ");
//     STARTWORD();
//     if (stringEquals(CurrentWord.TabWord, "Evil")) {
//         ADVWORD();
//         if (stringEquals(CurrentWord.TabWord, "Lab")) {
//             ADVWORD();
//             if (stringEquals(CurrentWord.TabWord, "Assistant ")) {
//                 ADVWORD();
//                 delay(14);
//                 printf("\n");
//                 *money += 100;
//                 printf("Anda mendapatkan 100 uang\n");
//                 CurrentWord.Length = 0;
//             }
//         }
//     } 
//     else if(stringEquals(CurrentWord.TabWord, "OWCA")) {
//         ADVWORD();
//         if (stringEquals(CurrentWord.TabWord, "Hiring")) {
//             ADVWORD();
//             if (stringEquals(CurrentWord.TabWord, "Manager ")) {
//                 ADVWORD();
//                 delay(21);
//                 printf("\n");
//                 *money += 4200;
//                 printf("Anda mendapatkan 4200 uang\n");
//                 CurrentWord.Length = 0;
//             }
//         }
//     } 
//     else if(stringEquals(CurrentWord.TabWord, "Cikapundunginator")) {
//         ADVWORD();
//         if (stringEquals(CurrentWord.TabWord, "Caretaker")) {
//             ADVWORD();
//             if (stringEquals(CurrentWord.TabWord, "Inator ")) {
//                 ADVWORD();
//                 delay(30);
//                 printf("\n");
//                 *money += 7000;
//                 printf("Anda mendapatkan 7000 uang\n");
//                 CurrentWord.Length = 0;
//             }
//         }
//     } 
//     else if(stringEquals(CurrentWord.TabWord, "Mewing")) {
//         ADVWORD();
//         if (stringEquals(CurrentWord.TabWord, "Specialist ")) {
//             ADVWORD();
//             delay(22);
//             printf("\n");
//             *money += 10000;
//             printf("Anda mendapatkan 10000 uang\n");
//             CurrentWord.Length = 0;
//         }
//     } 
//     else if(stringEquals(CurrentWord.TabWord, "Inator")) {
//         ADVWORD();
//         if (stringEquals(CurrentWord.TabWord, "Connoisseur ")) {
//             ADVWORD();
//             delay(15);
//             printf("\n");
//             *money += 997;
//             printf("Anda mendapatkan 997 uang\n");
//             CurrentWord.Length = 0;
//         }
//     }
//     else {
//         ADVWORD();
//         printf("Pekerjaan tidak ditemukan\n");
//         CurrentWord.Length = 0;
//     }
//     printf("%s\n", CurrentWord.TabWord);
}


int main() {
    int money = 0;
    doWork(&money);
    printf("%d",money);
}

