/* IMPORT HEADER ---------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "utilities.h"
#include "src/adt/boolean/boolean.h"
#include "src/adt/mesinangka/mesinangka.h"
#include "src/adt/mesinkarakter/mesinkarakter.h"
#include "src/adt/mesinkata/mesinkata.h"  
#include "src/adt/queue/queue.h"
#include "src/adt/arraydinBarang/arraydinBarang.h"
#include "src/adt/barang/barang.h"
#include "src/adt/stack/stack.h"
#include "src/adt/listlinier/listlinier.h"
#include "src/adt/map/map.h"
#include "src/adt/barang/barang.h"

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

#include "src/spesifikasi/profile/profile.h"
#include "src/spesifikasi/cart/cart_pay.h"
#include "src/spesifikasi/cart/cart.h"
#include "src/spesifikasi/cart/cart_show.h"
#include "src/spesifikasi/history/history.h"
#include "src/spesifikasi/wishlist_swap/wishlist_swap.h"
#include "src/spesifikasi/wishlist_remove/wishlist_remove.h"
#include "src/spesifikasi/wishlist_remove_i/wishlist_remove_i.h"
#include "src/spesifikasi/wishlist_clear/wishlist_clear.h"


/* DESCRIPTION ----------------------------------------------------------------------------- */

//AKSES DATA BARANG = barang
//AKSES DATA USER = users

/*
TOLONG NAMA FUNGSI DAN INPUTNYA SESUAIN SAMA NAMA FUNGSI DISINI
INI UDAH CARA PALING SEDERHANA TOLONG JANGAN DIUBAH
KALO ADA YANG INGIN DITANYAKAN BILANG DI GRUP PLIZ!!
*/


/*
run:
gcc -o program main.c src/adt/mesinkalimat/linemachine.c src/adt/mesinangka/mesinangka.c src/adt/listuser/listuser.c src/adt/mesinkarakter/mesinkarakter.c utilities.c src/adt/mesinkata/mesinkata.c src/adt/queue/queue.c src/adt/arraydinBarang/arraydinBarang.c src/adt/barang/barang.c src/adt/stack/stack.c src/adt/listlinier/listlinier.c src/adt/map/map.c src/spesifikasi/start/start.c src/spesifikasi/load/load.c src/spesifikasi/login/login.c src/spesifikasi/logout/logout.c src/spesifikasi/register/register.c src/spesifikasi/work/work.c src/spesifikasi/work_challenge/work_challenge.c src/spesifikasi/store_list/store_list.c src/spesifikasi/store_remove/store_remove.c src/spesifikasi/store_request/store_request.c src/spesifikasi/store_supply/store_supply.c src/spesifikasi/help/help.c src/spesifikasi/save/save.c src/spesifikasi/profile/profile.c src/spesifikasi/cart/cart_pay.c src/spesifikasi/cart/cart.c src/spesifikasi/cart/cart_show.c src/spesifikasi/history/history.c src/spesifikasi/wishlist_swap/wishlist_swap.c src/spesifikasi/wishlist_remove/wishlist_remove.c src/spesifikasi/wishlist_remove_i/wishlist_remove_i.c src/spesifikasi/wishlist_clear/wishlist_clear.c -lm
*/

/* MAIN ----------------------------------------------------------------------------------- */
int main(){
    // KAMUS
    // System state
    boolean startup = false;
    boolean loggedin = false;
    int quantity = 0;
    int urutan = 0;
    int help_menu = 1;
    int acc_id = -1;
    int i;
    char filename[50] = "config.txt";

    // Penyimpanan
    ArrayDin Information;
    Queue request;
    List User;
    ArrayDin barangList;
    

    // Masukkan program utama
    char perintah[50] = "";
    char keterangan[50] = "";
    // ALGORTIMA
    printf("  _____  _    _ _____  _____  __  __          _____ _______ \n");
    printf(" |  __ \\| |  | |  __ \\|  __ \\|  \\/  |   /\\   |  __ \\__   __|\n");
    printf(" | |__) | |  | | |__) | |__) | \\  / |  /  \\  | |__) | | |   \n");
    printf(" |  ___/| |  | |  _  /|  _  /| |\\/| | / /\\ \\ |  _  /  | |   \n");
    printf(" | |    | |__| | | \\ \\| | \\ \\| |  | |/ ____ \\| | \\ \\  | |   \n");
    printf(" |_|     \\____/|_|  \\_\\_|  \\_\\_|  |_/_/    \\_\\_|  \\_\\ |_|   \n");
    printf("                                                            \n");
    printf("***** | (START) Start shopping | (LOAD) Load your file | (HELP) Help | (QUIT) | *****\n");
    
    // STARTFILE("command.txt");
    while (1) {
        ClearBuffer();
        printf("\n>> ");
        STARTWORD();
        printf("%s\n", currentWord.TabWord);
        i = 0;

        // START
        if (stringEquals(currentWord.TabWord, "START")) {
            printf("\n");
            // Mengubah state
            START_PURRMART(Information, User, request); // START bakal import data barang ke Information dan data pengguna ke user dari config.txt
            
            // Mengubah tampilan HELP
            help_menu = 2;
            if (IsListEmpty(&User)) {
                printf("***** | (REGISTER) Register account | (HELP) Help | *****\n");
            } else {
                printf("***** | (LOGIN) Login to your account| (REGISTER) Register account | (HELP) Help | *****\n");
            }
            startup = true;
        }

        // LOAD
        else if (stringEquals(currentWord.TabWord, "LOAD")){
            // Masukkan nama file
            ADVWORD(); // 'keterangan' -> nama file yang ingin di load
            copyString(filename, currentWord.TabWord);

            // Membuka dan membaca file
            LOAD(filename, Information, User, request); // LOAD bakal import data barang ke Information dan data pengguna ke user dari 'keterangan'

            printf("***** | (LOGIN) Login to your account| (REGISTER) Register account | (HELP) Help | *****\n");
            
            // Mengubah tampilan HELP
            help_menu = 2;
            ClearBuffer();
        }

        // LOGIN
        else if (stringEquals(currentWord.TabWord, "LOGIN")) {

                acc_id = LOGIN(User, &acc_id); // LOGIN bakal mengembalikan index user dari List User
                loggedin = true;

        }
        
        // LOGOUT
        else if (stringEquals(currentWord.TabWord, "LOGOUT")) {
            if (loggedin) {
                LOGOUT(&acc_id); // LOGOUT bakal mengubah acc_id = -1
                loggedin = false;
            } else {
                printf("ERROR: There's no account loaded\n");
            }
        }

        // REGISTER
        else if (stringEquals(currentWord.TabWord, "REGISTER")) {
            if (startup) {
                REGISTER(&User); // REGISTER bakal insert nama dan password ke List User 
            // } else {
            //     printf("ERROR: There's no file loaded\n");
            // }
            }
        }

        // WORK
        else if (stringEquals(currentWord.TabWord, "WORK")) {
            // validasi input
            if (loggedin) {
                if (GetCC() != '\n') {
                    ADVWORD();
                    if (stringEquals(currentWord.TabWord, "CHALLENGE")) {
                        workChallenge(&User.A[acc_id].money); // WORK CHALLENGE bakal menambah uang user
                    }
                } else {
                    doWork(&User.A[acc_id].money); // WORK bakal menambah uang user
                }
            } else {
                doWork(&User.A[acc_id].money); // WORK bakal menambah uang user
            }
            ClearBuffer();
        }

        // STORE
        else if (stringEquals(currentWord.TabWord, "STORE")) {
            // Masukkan keterangan
            ADVWORD(); // Masukkan perintah tambahan

            // validasi input
            if (loggedin) {
                // STORE LIST
                if (stringEquals(currentWord.TabWord, "LIST")) {
                    StoreList(Information); // Menampilkan isi ArrayDin Information
                }
                // STORE REQUEST
                else if (stringEquals(currentWord.TabWord, "REQUEST")) {
                    StoreRequest(request, Information); // Meminta barang baru
                }
                // STORE SUPPLY
                else if (stringEquals(currentWord.TabWord, "SUPPLY")) {
                    StoreSupply(request, Information); // Masukkan harga barang
                }
                // STORE REMOVE
                else if (stringEquals(currentWord.TabWord, "REMOVE")) {
                    StoreRemove(Information); // Menghapus barang di Information
                }
            } 
            else if (!loggedin) { printf("ERROR: nigga\n"); } 
            else { printf("ERROR STORE: Input tidak valid!\n"); }ClearBuffer();
        }
        
        // HELP
        else if(stringEquals(currentWord.TabWord, "HELP")) {
            if (help_menu == 1) welcomeMenu();
            else if (help_menu == 2) loginMenu();
            else if (help_menu == 3) mainMenu();
        }
        
        // SAVE
        else if(stringEquals(currentWord.TabWord, "SAVE")) {
            Save(Information, User, filename); // SAVE menyalin informasi dari ArrayDin Information dan List User ke file
        }
        
        // QUIT
        else if (stringEquals(currentWord.TabWord, "QUIT")) {
            printf("\n");
            DeallocateArrayDin(&Information);
            printf("***** | Thank you for visiting PURRMART! | *****\n");
            startup = false;
            loggedin = false;
            break;
        } 
        
        // PROFILE
        else if (stringEquals(currentWord.TabWord, "PROFILE")) {
            if (loggedin) {
                displayProfile(User.A[acc_id]); // Menampilkan informasi user dari List User dengan index acc_id
            } else {
                printf("ERROR: No account is loaded\n");
            }
        }

        // CART
        else if (stringEquals(currentWord.TabWord, "CART")) {
            // Masukkan keterangan
            ADVWORD();

            // validasi input
            if (loggedin) {
                // CART ADD
                if (stringEquals(currentWord.TabWord, "ADD")) {
                    ADVWORD();

                    copyString(keterangan, currentWord.TabWord);
                    while (GetCC() != '\n') {
                        ADVWORD();
                        stringConcat(keterangan, " ");
                        stringConcat(keterangan, currentWord.TabWord);
                    }

                    ADVWORD();
                    for (i = 0; i < currentWord.Length; i++) {
                        quantity = quantity * 10 + (currentWord.TabWord[i] - '0');
                    }

                    AddToCart(&User.A[acc_id].keranjang, keterangan, quantity); // Menyimpan barang ke keranjang
                }
                // CART REMOVE
                else if (stringEquals(currentWord.TabWord, "REMOVE")) {
                    ADVWORD();

                    copyString(keterangan, currentWord.TabWord);
                    while (GetCC() != '\n') {
                        ADVWORD();
                        stringConcat(keterangan, " ");
                        stringConcat(keterangan, currentWord.TabWord);
                    }

                    ADVWORD();
                    for (i = 0; i < currentWord.Length; i++) {
                        quantity = quantity * 10 + (currentWord.TabWord[i] - '0');
                    }

                    RemoveFromCart(&User.A[acc_id].keranjang, keterangan, quantity); // Menghapus barang dari keranjang
                }
                // CART SHOW
                else if (stringEquals(currentWord.TabWord, "SHOW")) {
                    DisplayCart(User.A[acc_id].keranjang); // Menampilkan keranjang
                }
                // CART PAY
                else if (stringEquals(currentWord.TabWord, "PAY")) {
                    CartPay(&User.A[acc_id]); // Membayar keranjang, INFO: ini pake User.A[acc_id] soalnya yang dirubah User.A[acc_id].money, User.A[acc_id].keranjang, dan User.A[acc_id].riwayat_pembelian
                }
            } 
            else if (!loggedin) { printf("ERROR: There's  loadno fileed\n"); } 
            else { printf("ERROR CART: Input tidak valid!\n"); }
            ClearBuffer();
        }

        // HISTORY
        else if (stringEquals(currentWord.TabWord, "HISTORY")) {
            ADVWORD();

            for (i = 0; i < currentWord.Length; i++) {
                quantity = quantity * 10 + (currentWord.TabWord[i] - '0');
            }

            if (loggedin) {
                History(User.A[acc_id].riwayat_pembelian, quantity); // Menampilkan jumlah history
            } else {
                printf("ERROR: No account is loaded\n");
            }
            ClearBuffer();
        }

        // WISHLIST
        else if (stringEquals(currentWord.TabWord, "WISHLIST")) {
            // Masukkan keterangan
            ADVWORD();

            // validasi input
            if (loggedin) {
                // SWAP
                if (stringEquals(currentWord.TabWord, "SWAP")) {
                    ADVWORD();
                    int position1 = 0;
                    for (i = 0; i < currentWord.Length; i++) {
                        position1 = position1 * 10 + (currentWord.TabWord[i] - '0');
                    }

                    ADVWORD();
                    int position2 = 0;
                    for (i = 0; i < currentWord.Length; i++) {
                        position2 = position2 * 10 + (currentWord.TabWord[i] - '0');
                    }

                    wishlistSwap(&User.A[acc_id], position1, position2);
                }
                // REMOVE
                else if (stringEquals(currentWord.TabWord, "REMOVE")) {
                    urutan = -1;

                    if (GetCC() != '\n') {
                        ADVWORD();
                        for (i = 0; i < currentWord.Length; i++) {
                            urutan = urutan * 10 + (currentWord.TabWord[i] - '0');
                        }
                    }

                    // REMOVE <i>
                    if (urutan != -1) {
                        wishlistRemove(&User.A[acc_id]);
                    } else {
                        wishlistRemoveI(&User.A[acc_id]);
                    }
                }
                // CLEAR
                else if (stringEquals(currentWord.TabWord, "CLEAR")) {
                    wishlistClear(&User.A[acc_id]);
                }
            } 
            else if (!loggedin) { printf("ERROR: No account is loaded\n"); } 
        }
        else { printf("ERROR: Input tidak valid!\n"); }
        printf("%s\n", currentWord.TabWord);
    }
    return 0;
}