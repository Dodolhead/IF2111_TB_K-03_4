#include <stdio.h>
#include <stdlib.h>
#include "wishlist_swap.h"
// #include "../../spesifikasi/wishlist_add/wishlist_add.c"
// #include "../../adt/listuser/listuser.c"
// #include "../../adt/mesinkata/mesinkata.c"
// #include "../../adt/map/map.c"
// #include "../../adt/listlinier/listlinier.c"
// #include "../../adt/mesinkarakter/mesinkarakter.c"
// #include "../../adt/stack/stack.c"
// #include "../../../utilities.c"

void wishlistSwap(User *U, int firstPos, int secondPos) {
    // STARTANGKA();  // Mulai membaca angka pertama
    // STARTWORD();   // Mulai membaca kata kedua (untuk posisi kedua)
    // int firstPos = GetAngka();  // Posisi pertama
    // firstPos--;  // Mengubahnya menjadi indeks array yang dimulai dari 0

    // char* temp = currentWord.TabWord;
    // int secondPos = *temp - '0';  // Posisi kedua
    // secondPos--;  // Mengubahnya menjadi indeks array yang dimulai dari 0
    firstPos -= 1;
    secondPos -=1;
    // Validasi posisi agar tidak keluar dari ukuran wishlist
    if (firstPos < 0 || secondPos < 0 || firstPos == secondPos) {
        printf("Posisi tidak valid!\n");
    }

    // Menemukan node pertama
    addressLinkedList P1 = First(U->wishlist);
    addressLinkedList P2 = First(U->wishlist);

    int i = 0;
    // Mencari node pertama
    while (P1 != Nil && i < firstPos) {
        P1 = Next(P1);
        i++;
    }

    i = 0;
    // Mencari node kedua
    while (P2 != Nil && i < secondPos) {
        P2 = Next(P2);
        i++;
    }

    // Jika kedua node ditemukan, tukar informasi antara keduanya
    if (P1 != Nil && P2 != Nil) {
        // Menukar informasi antara P1 dan P2
        char tempItem[50];
        copyString(tempItem, Info(P1));  // Menyimpan informasi item pertama
        copyString(Info(P1), Info(P2)); // Menukar informasi item pertama dengan item kedua
        copyString(Info(P2), tempItem); // Menyimpan informasi item pertama ke posisi kedua

        printf("Berhasil menukar posisi Item %d dengan Item %d pada wishlist!\n", firstPos + 1, secondPos + 1);
    } else {
        printf("Posisi tidak valid!\n");
    }
}

// int main() {
//     List U;
//     MakeList(&U);
//     LinkedList wishlist;
//     CreateLinkedListEmpty(&wishlist);
//     wishlistAdd(&U.A[0]);
//     wishlistAdd(&U.A[0]);
//     wishlistSwap(&U.A[0],1,2);
//     PrintWishlist(&U,0);
// }