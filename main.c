#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "utilities.h"
#include "../../adt/boolean.h"
#include "../../adt/list.h"
#include "../../adt/mesinkarakter.h"
#include "../../adt/mesinkata.h"  
#include "../../adt/queue.h"
#include "../../adt/stack.h"
#include "../../spesifikasi/start/start.h"
#include "../../spesifikasi/load/load.h"
#include "../../spesifikasi/start/start.h"
#include "../../adt/arraydinBarang.h"


//AKSES DATA BARANG = barang
//AKSES DATA USER = users


int main(){

    int indicator= 1;    
    int help_menu = 1;//1 untuk welcome 2 untuk login 3 untuk main menu
    Barang barang[100]; // deklarasi awal biar bisa manggil fungsi
    User users[100];
    int jumlahBarang = 0, jumlahUsers = 0;
    int loggedInUserIndex = -1; //buat ngecek user yang lagi login
 

    printf("  _____  _    _ _____  _____  __  __          _____ _______ \n");
    printf(" |  __ \\| |  | |  __ \\|  __ \\|  \\/  |   /\\   |  __ \\__   __|\n");
    printf(" | |__) | |  | | |__) | |__) | \\  / |  /  \\  | |__) | | |   \n");
    printf(" |  ___/| |  | |  _  /|  _  /| |\\/| | / /\\ \\ |  _  /  | |   \n");
    printf(" | |    | |__| | | \\ \\| | \\ \\| |  | |/ ____ \\| | \\ \\  | |   \n");
    printf(" |_|     \\____/|_|  \\_\\_|  \\_\\_|  |_/_/    \\_\\_|  \\_\\ |_|   \n");
    printf("                                                            \n");
    printf("***** | (START) Start shopping | (LOAD) Load your file | (HELP) Help | (QUIT) | *****\n");
    while (1) {
        printf(">> ");
        STARTWORD();

        if (stringEquals(CurrentWord.TabWord, "START")) {
            START_PURRMART();
            printf("***** | (LOGIN) Login to your account| (REGISTER) Register account | (HELP) Help | *****\n");
            help_menu=2;
        } 

        else if(stringEquals(CurrentWord.TabWord, "LOAD")) { //ini gimana caranya biar ke kirim ke LOADnya cuma file namenya aja ga LOAD filename... soalnya awalnya kan pake STARTWORD
            ADVSKIPWORD();
            char filename[100];
            int i;
            for (i = 0; i < CurrentWord.Length; i++) {
                filename[i] = CurrentWord.TabWord[i];
            }
            filename[i] = '\0';
            LOAD(filename);
            printf("***** | (LOGIN) Login to your account| (REGISTER) Register account | (HELP) Help | *****\n");
            help_menu=2;
        }

        else if (stringEquals(CurrentWord.TabWord, "LOGIN")) { // nanti ditambahin kondisi biar kalo belum START/LOAD gabisa login berlaku buat yg dua kebawah ini
            LOGIN(users, jumlahUsers, &loggedInUserIndex);
        }

        else if (stringEquals(CurrentWord.TabWord, "LOGOUT")) {
            LOGIN(users, jumlahUsers, &loggedInUserIndex);
        }

        else if (stringEquals(CurrentWord.TabWord, "REGISTER")) {
            LOGIN(users, jumlahUsers, &loggedInUserIndex);
        }

        else if (stringEquals(CurrentWord.TabWord, "STORE")) {
            ADVWORD();
            if (stringEquals(CurrentWord.TabWord, "LIST")) {
                StoreList(Info);
            }

            else if (stringEquals(CurrentWord.TabWord, "REQUEST")) {
                StoreRequest(q, Info);
            }

            else if (stringEquals(CurrentWord.TabWord, "SUPPLY")) {
                StoreSupply(q, Info);
            }

            else if (stringEquals(CurrentWord.TabWord, "REMOVE")) {
                StoreRemove(Info);
            }
        }

        else if(stringEquals(CurrentWord.TabWord, "HELP")) {
            if (help_menu==1) welcomeMenu();
            else if (help_menu==2) loginMenu();
            else if (help_menu==3) mainMenu();
        }

        else if(stringEquals(CurrentWord.TabWord, "SAVE")) {
            Save(Info, User);
        }

        else if (stringEquals(CurrentWord.TabWord, "QUIT")) {
            break;
        }

        else {
            while (!IsEOP()) {
                ADVWORD();
            }
        }
    }
}
