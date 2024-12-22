#include <stdio.h>
#include "work.h"
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
    STARTSENTENCE();
    if (stringEquals(currentWord.TabWord, "Evil Lab Assistant")) {
        delay(14);
        printf("\n");
        *money += 100;
        printf("Anda mendapatkan 100 uang\n");
    } 
    else if(stringEquals(currentWord.TabWord, "OWCA Hiring Manager")) {
        delay(21);
        printf("\n");
        *money += 4200;
        printf("Anda mendapatkan 4200 uang\n");
    } 
    else if(stringEquals(currentWord.TabWord, "Cikapundunginator Caretaker")) {
        delay(30);
        printf("\n");
        *money += 7000;
        printf("Anda mendapatkan 7000 uang\n");
    } 
    else if(stringEquals(currentWord.TabWord, "Mewing Specialist")) {
        delay(22);
        printf("\n");
        *money += 10000;
        printf("Anda mendapatkan 10000 uang\n");
    }
    else if(stringEquals(currentWord.TabWord, "Inator Connoisseur")) {
        delay(15);
        printf("\n");
        *money += 997;
        printf("Anda mendapatkan 997 uang\n");
    }
    else {
        printf("%s Pekerjaan tidak ditemukan\n", currentWord.TabWord);
    }
//     printf(">> ");
//     STARTWORD();
//     if (stringEquals(currentWord.TabWord, "Evil")) {
//         ADVWORD();
//         if (stringEquals(currentWord.TabWord, "Lab")) {
//             ADVWORD();
//             if (stringEquals(currentWord.TabWord, "Assistant ")) {
//                 ADVWORD();
//                 delay(14);
//                 printf("\n");
//                 *money += 100;
//                 printf("Anda mendapatkan 100 uang\n");
//                 currentWord.Length = 0;
//             }
//         }
//     } 
//     else if(stringEquals(currentWord.TabWord, "OWCA")) {
//         ADVWORD();
//         if (stringEquals(currentWord.TabWord, "Hiring")) {
//             ADVWORD();
//             if (stringEquals(currentWord.TabWord, "Manager ")) {
//                 ADVWORD();
//                 delay(21);
//                 printf("\n");
//                 *money += 4200;
//                 printf("Anda mendapatkan 4200 uang\n");
//                 currentWord.Length = 0;
//             }
//         }
//     } 
//     else if(stringEquals(currentWord.TabWord, "Cikapundunginator")) {
//         ADVWORD();
//         if (stringEquals(currentWord.TabWord, "Caretaker")) {
//             ADVWORD();
//             if (stringEquals(currentWord.TabWord, "Inator ")) {
//                 ADVWORD();
//                 delay(30);
//                 printf("\n");
//                 *money += 7000;
//                 printf("Anda mendapatkan 7000 uang\n");
//                 currentWord.Length = 0;
//             }
//         }
//     } 
//     else if(stringEquals(currentWord.TabWord, "Mewing")) {
//         ADVWORD();
//         if (stringEquals(currentWord.TabWord, "Specialist ")) {
//             ADVWORD();
//             delay(22);
//             printf("\n");
//             *money += 10000;
//             printf("Anda mendapatkan 10000 uang\n");
//             currentWord.Length = 0;
//         }
//     } 
//     else if(stringEquals(currentWord.TabWord, "Inator")) {
//         ADVWORD();
//         if (stringEquals(currentWord.TabWord, "Connoisseur ")) {
//             ADVWORD();
//             delay(15);
//             printf("\n");
//             *money += 997;
//             printf("Anda mendapatkan 997 uang\n");
//             currentWord.Length = 0;
//         }
//     }
//     else {
//         ADVWORD();
//         printf("Pekerjaan tidak ditemukan\n");
//         currentWord.Length = 0;
//     }
//     printf("%s\n", currentWord.TabWord);
}


// int main() {
//     int money = 0;
//     doWork(&money);
//     printf("%d",money);
// }

