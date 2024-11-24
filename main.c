/* IMPORT HEADER ---------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "utilities.h"
#include "src/adt/boolean.h"
#include "src/adt/mesinangka.h"
#include "src/adt/mesinkarakter.h"
#include "src/adt/mesinkata.h"  
#include "src/adt/queue.h"
#include "src/adt/arraydinBarang.h"
#include "src/adt/barang.h"

#include "src/spesifikasi/start/start.h"
#include "src/spesifikasi/load/load.h"
#include "src/spesifikasi/login/login.h"
#include "src/spesifikasi/logout/logout.h"
#include "src/spesifikasi/register/register.h"
#include "src/spesifikasi/work/work.h"
#include "src/spesifikasi/work_challenge/work_challenge.h"
#include "src/spesifikasi/store_list/store_list.h"
#include "src/spesifikasi/store_remove/store_remove.h"
#include "src/spesifikasi/store_request/store_request.h"
#include "src/spesifikasi/store_supply/store_supply.h"
#include "src/spesifikasi/help/help.h"
#include "src/spesifikasi/save/save.h"
#include "src/spesifikasi/quit/quit.h"

/* DESCRIPTION ----------------------------------------------------------------------------- */

//AKSES DATA BARANG = barang
//AKSES DATA USER = users

/*
STATUS:
START v
LOAD v
LOGIN v
LOGOUT v
REGISTER v
WORK v
WORK CHALLENGE v
STORE LIST v
STORE REQUEST v
STORE SUPPLY v
STORE REMOVE v
HELP v
SAVE v
QUIT v
*/

/* MAIN ----------------------------------------------------------------------------------- */
int main(){
    // KAMUS
    // File address
    char folder[] = "src/data/";
    char filename[100] = "";
    char fullpath[150] = "";
    char txt[] = ".txt";

    // System state
    boolean startup = false; // Kondisi sistem dibuka
    IdxType i, acc_id; // i untuk looping, acc_id untuk index akun user
    int help_menu = 1; // 1 untuk welcome, 2 untuk login, 3 untuk main menu
    Barang barang[100]; // deklarasi awal biar bisa manggil fungsi
    User users[100];
    int jumlahBarang = 0, jumlahUsers = 0;
    int loggedInUserIndex = -1; //buat ngecek user yang lagi login

    // Array dinamis dan antrian
    ArrayDin Information;
    Queue request;

    // ALGORTIMA
    printf("  _____  _    _ _____  _____  __  __          _____ _______ \n");
    printf(" |  __ \\| |  | |  __ \\|  __ \\|  \\/  |   /\\   |  __ \\__   __|\n");
    printf(" | |__) | |  | | |__) | |__) | \\  / |  /  \\  | |__) | | |   \n");
    printf(" |  ___/| |  | |  _  /|  _  /| |\\/| | / /\\ \\ |  _  /  | |   \n");
    printf(" | |    | |__| | | \\ \\| | \\ \\| |  | |/ ____ \\| | \\ \\  | |   \n");
    printf(" |_|     \\____/|_|  \\_\\_|  \\_\\_|  |_/_/    \\_\\_|  \\_\\ |_|   \n");
    printf("                                                            \n");
    printf("***** | (START) Start shopping | (LOAD) Load your file | (HELP) Help | (QUIT) | *****\n");
    
    STARTWORD();
    while (1) {
        printf(">> ");
        // Mencetak command
        i = 0;
        while (CurrentWord.TabWord[i] != '\0') {
            printf("%c", CurrentWord.TabWord[i]);
        }
        printf("\n");

        // START
        if (stringEquals(CurrentWord.TabWord, "START")) {
            // Mengubah state
            startup = true;

            // Membuat list barang dan antrian
            Information = MakeArrayDin();
            CreateQueue(&request);

            // Memuat isi file default ke dalam list
            copyString(fullpath, folder);
            stringConcat(fullpath, filename);
            stringConcat(fullpath, txt);
            ListBarang(&Information, fullpath);

            // Membuka dan membaca file default
            START_PURRMART();

            printf("***** | (LOGIN) Login to your account| (REGISTER) Register account | (HELP) Help | *****\n");

            // Mengubah tampilan HELP
            help_menu = 2;

        } 

        // LOAD
        else if (stringEquals(CurrentWord.TabWord, "LOAD")) {
            // Membaca nama file
            ADVWORD();

            // Membuat list barang dan antrian
            Information = MakeArrayDin();
            CreateQueue(&request);

            // Menyimpan nama file
            for (i = 0; i < CurrentWord.Length; i++) {
                filename[i] = CurrentWord.TabWord[i];
            }
            filename[i] = '\0';

            // Membuka dan membaca file
            LOAD(filename);

            // Memuat isi file default ke dalam list
            copyString(fullpath, folder);
            stringConcat(fullpath, filename);
            stringConcat(fullpath, txt);
            ListBarang(&Information, fullpath);

            printf("***** | (LOGIN) Login to your account| (REGISTER) Register account | (HELP) Help | *****\n");
            
            // Mengubah tampilan HELP
            help_menu = 2;
        }

        // LOGIN
        else if (stringEquals(CurrentWord.TabWord, "LOGIN")) {
            if (startup) {
                acc_id = LOGIN(users, jumlahUsers, &loggedInUserIndex);
            } else {
                printf("ERROR: There's no file loaded\n");
            }
        }
        
        // LOGOUT
        else if (stringEquals(CurrentWord.TabWord, "LOGOUT")) {
            if (startup) {
                LOGOUT(&loggedInUserIndex);
            } else {
                printf("ERROR: There's no file loaded\n");
            }
        }

        // REGISTER
        else if (stringEquals(CurrentWord.TabWord, "REGISTER")) {
            if (startup) {
                REGISTER(users, &jumlahUsers);
            } else {
                printf("ERROR: There's no file loaded\n");
            }
        }

        // WORK
        else if (stringEquals(CurrentWord.TabWord, "WORK")) {
            // Mengecek kata command berikutnya
            ADVWORD();

            // validasi input
            if (startup) {
                if (stringEquals(CurrentWord.TabWord, "CHALLENGE")) {
                    workChallenge(&(users[acc_id].money));
                }
            } else if (!startup) {
                printf("ERROR: No account is loaded\n");
            } else {
                doWork(&(users[acc_id].money));
            }
        }

        // STORE
        else if (stringEquals(CurrentWord.TabWord, "STORE")) {
            // Mengecek kata command berikutnya
            ADVWORD();

            // validasi input
            if (startup) {
                // STORE LIST
                if (stringEquals(CurrentWord.TabWord, "LIST")) {
                    StoreList(Information);
                }
                // STORE REQUEST
                else if (stringEquals(CurrentWord.TabWord, "REQUEST")) {
                    StoreRequest(request, Information);
                }
                // STORE SUPPLY
                else if (stringEquals(CurrentWord.TabWord, "SUPPLY")) {
                    StoreSupply(request, Information);
                }
                // STORE REMOVE
                else if (stringEquals(CurrentWord.TabWord, "REMOVE")) {
                    StoreRemove(Information);
                }
            } 
            else if (!startup) { printf("ERROR: There's no file loaded\n"); } 
            else { printf("ERROR: Invalid input\n"); }
        }
        
        // HELP
        else if(stringEquals(CurrentWord.TabWord, "HELP")) {
            if (help_menu == 1) welcomeMenu();
            else if (help_menu == 2) loginMenu();
            else if (help_menu == 3) mainMenu();
        }
        
        // SAVE
        else if(stringEquals(CurrentWord.TabWord, "SAVE")) {
            Save(Information, users, jumlahUsers);
        }
        
        // QUIT
        else if (stringEquals(CurrentWord.TabWord, "QUIT")) {
            break;
            DeallocateArrayDin(&Information);
            printf("***** | Thank you for visiting PURRMART! | *****\n");
        }
        
        // Input tidak termasuk di atas
        else {
            ADVWORD();
        }
    }

    return 0;
}
