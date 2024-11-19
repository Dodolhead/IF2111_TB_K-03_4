#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "dictionary.h"
#include "dictionary.c"
#include "src/adt/boolean.h"
#include "src/adt/list.h"
#include "src/adt/mesinkarakter.h"
#include "src/adt/mesinkarakter.c"
#include "src/adt/mesinkata.h"  
#include "src/adt/mesinkata.c"  
#include "src/adt/queue.h"
#include "src/adt/queue.c"
#include "src/adt/stack.h"
#include "src/adt/stack.c"

int main(){
    int indicator= 1;
    printf("  _____  _    _ _____  _____  __  __          _____ _______ \n");
    printf(" |  __ \\| |  | |  __ \\|  __ \\|  \\/  |   /\\   |  __ \\__   __|\n");
    printf(" | |__) | |  | | |__) | |__) | \\  / |  /  \\  | |__) | | |   \n");
    printf(" |  ___/| |  | |  _  /|  _  /| |\\/| | / /\\ \\ |  _  /  | |   \n");
    printf(" | |    | |__| | | \\ \\| | \\ \\| |  | |/ ____ \\| | \\ \\  | |   \n");
    printf(" |_|     \\____/|_|  \\_\\_|  \\_\\_|  |_/_/    \\_\\_|  \\_\\ |_|   \n");
    printf("                                                            \n");
    printf("(START) Start shopping | (CART) View your cart | (HELP) Help | (EXIT) Exit\n");
    while (1) {
        printf(">> ");
        STARTWORD();
        if (stringEquals(CurrentWord.TabWord, "START")) {
            printf("insert start function here");
        } 
        else if(stringEquals(CurrentWord.TabWord, "CART")) {
            printf("insert cart function here");
        }
        else if(stringEquals(CurrentWord.TabWord, "CART")) {
            printf("insert help function here");
        }
        else if (stringEquals(CurrentWord.TabWord, "EXIT")) {
            break;
        }
        else {
            while (!IsEOP()) {
                ADVWORD();
            }
        }
    }
}
