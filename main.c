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
#include "src/adt/stack.h"
#include "src/adt/listlinier.h"
#include "src/adt/map.h"
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

#include "src/spesifikasi/profile/profile.h"
#include "src/spesifikasi/cart/cart.h"
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

/* MAIN ----------------------------------------------------------------------------------- */
int main(){
    // KAMUS
    // System state
    boolean startup = false;
    boolean loggedin = false;
    int quantity;
    int urutan;
    int help_menu = 1;
    int acc_id = -1;

    // Penyimpanan
    ArrayDin Information;
    Queue request;
    List User;

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
    
    while (1) {
        printf(">> ");
        scanf("%s", perintah);

        // START
        if (stringEquals(perintah, "START")) {
            // Membuat penyimpanan sistem
            Information = MakeArrayDin();
            CreateQueue(&request);
            User = MakeList();

            START_PURRMART(Information, User); // START bakal import data barang ke Information dan data pengguna ke user dari config.txt
            
            // Mengubah tampilan HELP
            help_menu = 2;
        }

        // LOAD
        else if (stringEquals(perintah, "LOAD")) {
            // Membuat penyimpanan sistem
            Information = MakeArrayDin();
            CreateQueue(&request);
            User = MakeList();

            // Masukkan nama file
            scanf("%s", keterangan); // 'keterangan' -> nama file yang ingin di load

            // Membuka dan membaca file
            LOAD(keterangan, Information, User); // LOAD bakal import data barang ke Information dan data pengguna ke user dari 'keterangan'

            printf("***** | (LOGIN) Login to your account| (REGISTER) Register account | (HELP) Help | *****\n");
            
            // Mengubah tampilan HELP
            help_menu = 2;
        }

        // LOGIN
        else if (stringEquals(perintah, "LOGIN")) {
            if (startup) {
                acc_id = LOGIN(); // LOGIN bakal mengembalikan index user dari List User
                loggedin = true;
            } else {
                printf("ERROR: There's no file loaded\n");
            }
        }
        
        // LOGOUT
        else if (stringEquals(perintah, "LOGOUT")) {
            if (loggedin) {
                acc_id = LOGOUT(); // LOGOUT bakal mengubah acc_id = -1
                loggedin = false;
            } else {
                printf("ERROR: There's no account loaded\n");
            }
        }

        // REGISTER
        else if (stringEquals(perintah, "REGISTER")) {
            if (startup) {
                REGISTER(User); // REGISTER bakal insert nama dan password ke List User 
            } else {
                printf("ERROR: There's no file loaded\n");
            }
        }

        // WORK
        else if (stringEquals(perintah, "WORK")) {
            // Masukkan keterangan
            scanf("%s", keterangan);

            // validasi input
            if (loggedin) {
                if (stringEquals(keterangan, "CHALLENGE")) {
                    workChallenge(User.A[acc_id].money); // WORK CHALLENGE bakal menambah uang user
                }
            } else if (!loggedin) {
                printf("ERROR: No account is loaded\n");
            } else {
                doWork(User.A[acc_id].money); // WORK bakal menambah uang user
            }
        }

        // STORE
        else if (stringEquals(perintah, "STORE")) {
            // Masukkan keterangan
            scanf("%s", keterangan); // Masukkan perintah tambahan

            // validasi input
            if (loggedin) {
                // STORE LIST
                if (stringEquals(keterangan, "LIST")) {
                    StoreList(Information); // Menampilkan isi ArrayDin Information
                }
                // STORE REQUEST
                else if (stringEquals(keterangan, "REQUEST")) {
                    StoreRequest(request, Information); // Meminta barang baru
                }
                // STORE SUPPLY
                else if (stringEquals(keterangan, "SUPPLY")) {
                    StoreSupply(request, Information); // Masukkan harga barang
                }
                // STORE REMOVE
                else if (stringEquals(keterangan, "REMOVE")) {
                    StoreRemove(Information); // Menghapus barang di Information
                }
            } 
            else if (!loggedin) { printf("ERROR: There's no file loaded\n"); } 
            else { printf("ERROR: Input tidak valid!\n"); }
        }
        
        // HELP
        else if(stringEquals(perintah, "HELP")) {
            if (help_menu == 1) welcomeMenu();
            else if (help_menu == 2) loginMenu();
            else if (help_menu == 3) mainMenu();
        }
        
        // SAVE
        else if(stringEquals(perintah, "SAVE")) {
            Save(Information, User); // SAVE menyalin informasi dari ArrayDin Information dan List User ke file
        }
        
        // QUIT
        else if (stringEquals(perintah, "QUIT")) {
            printf("\n");
            DeallocateArrayDin(&Information);
            printf("***** | Thank you for visiting PURRMART! | *****\n");
            startup = false;
            loggedin = false;
            break;
        } 
        
        // PROFILE
        else if (stringEquals(perintah, "PROFILE")) {
            if (loggedin) {
                Profile(acc_id); // Menampilkan informasi user dari List User dengan index acc_id
            } else {
                printf("ERROR: No account is loaded\n");
            }
        }

        // CART
        else if (stringEquals(perintah, "CART")) {
            // Masukkan keterangan
            scanf("%s", keterangan);

            // validasi input
            if (loggedin) {
                // CART ADD
                if (stringEquals(keterangan, "ADD")) {
                    scanf("%s %d", cartItem, quantity);
                    AddToCart(User.A[acc_id].keranjang, cartItem, quantity); // Menyimpan barang ke keranjang
                }
                // CART REMOVE
                else if (stringEquals(keterangan, "REMOVE")) {
                    scanf("%s %d", cartItem, quantity);
                    RemoveFromCart(User.A[acc_id].keranjang, cartItem, quantity); // Menghapus barang dari keranjang
                }
                // CART SHOW
                else if (stringEquals(keterangan, "SHOW")) {
                    DisplayCart(User.A[acc_id].keranjang); // Menampilkan keranjang
                }
                // CART PAY
                else if (stringEquals(keterangan, "PAY")) {
                    PayCart(User.A[acc_id]); // Membayar keranjang, INFO: ini pake User.A[acc_id] soalnya yang dirubah User.A[acc_id].money, User.A[acc_id].keranjang, dan User.A[acc_id].riwayat_pembelian
                }
            } 
            else if (!loggedin) { printf("ERROR: There's no file loaded\n"); } 
            else { printf("ERROR: Input tidak valid!\n"); }
        }

        // HISTORY
        else if (stringEquals(perintah, "HISTORY")) {
            scanf("%d", quantity);

            if (loggedin) {
                History(User.A[acc_id].riwayat_pembelian, quantity); // Menampilkan jumlah history
            } else {
                printf("ERROR: No account is loaded\n");
            }
        }

        // WISHLIST
        else if (stringEquals(perintah, "WISHLIST")) {
            // Masukkan keterangan
            scanf("%s", keterangan);

            // validasi input
            if (loggedin) {
                // SWAP
                if (stringEquals(keterangan, "SWAP")) {
                    scanf("%s %d", cartItem, quantity);
                    wishlistSwap(User.A[acc_id].wishlist);
                }
                // REMOVE
                else if (stringEquals(keterangan, "REMOVE")) {
                    urutan = -1;
                    scanf("%d", urutan);

                    // REMOVE <i>
                    if (urutan != -1) {
                        wishlistRemove(User.A[acc_id].wishlist);
                    } else {
                        wishlistRemoveI(User.A[acc_id].wishlist, urutan);
                    }
                }
                // CLEAR
                else if (stringEquals(keterangan, "CLEAR")) {
                    wishlistClear(User.A[acc_id].wishlist);
                }
            } 
            else if (!loggedin) { printf("ERROR: No account is loaded\n"); } 
            else { printf("ERROR: Input tidak valid!\n"); }
        }

        else {
            printf("ERROR: Input tidak valid!\n");
        }
    }
    return 0;
}