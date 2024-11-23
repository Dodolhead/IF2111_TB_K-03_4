#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "dictionary.h"
#include "../../adt/boolean.h"
#include "../../adt/list.h"
#include "../../adt/mesinkarakter.h"
#include "../../adt/mesinkata.h"  
#include "../../adt/queue.h"
#include "../../adt/stack.h"
#include "../../spesifikasi/start/start.h"
#include "../../spesifikasi/load/load.h"
#include "../../spesifikasi/start/start.h"

int main(){
    int indicator= 1;

    printf("  _____  _    _ _____  _____  __  __          _____ _______ \n");
    printf(" |  __ \\| |  | |  __ \\|  __ \\|  \\/  |   /\\   |  __ \\__   __|\n");
    printf(" | |__) | |  | | |__) | |__) | \\  / |  /  \\  | |__) | | |   \n");
    printf(" |  ___/| |  | |  _  /|  _  /| |\\/| | / /\\ \\ |  _  /  | |   \n");
    printf(" | |    | |__| | | \\ \\| | \\ \\| |  | |/ ____ \\| | \\ \\  | |   \n");
    printf(" |_|     \\____/|_|  \\_\\_|  \\_\\_|  |_/_/    \\_\\_|  \\_\\ |_|   \n");
    printf("                                                            \n");
    printf("***** | (START) Start shopping | (LOAD) Load you file | (HELP) Help | *****\n");
    while (1) {
        printf(">> ");
        STARTWORD();
        if (stringEquals(CurrentWord.TabWord, "START")) {
            START_PURRMART();
        } 
        else if(stringEquals(CurrentWord.TabWord, "LOAD")) { //ini gimana caranya biar ke kirim ke LOADnya cuma filenamenya aja ga LOAD filename... soalnya awalnya kan pake STARTWORD
            ADVSKIPWORD();
            char filename[100];
            int i;
            for (i = 0; i < CurrentWord.Length; i++) {
                filename[i] = CurrentWord.TabWord[i];
            }
            filename[i] = '\0';
            LOAD(filename);

        }
        else if(stringEquals(CurrentWord.TabWord, "HELP")) {
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
