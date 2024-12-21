#include <stdio.h>
#include <stdlib.h>
#include "wishlist_swap.h"
#include "../../adt/listuser/listuser.c"

void wishlistSwap(User *U, int firstPos, int secondPos) {
    // STARTANGKA();  // Mulai membaca angka pertama
    // STARTWORD();   // Mulai membaca kata kedua (untuk posisi kedua)
    // int firstPos = GetAngka();  // Posisi pertama
    // firstPos--;  // Mengubahnya menjadi indeks array yang dimulai dari 0

    // char* temp = currentWord.TabWord;
    // int secondPos = *temp - '0';  // Posisi kedua
    // secondPos--;  // Mengubahnya menjadi indeks array yang dimulai dari 0

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

int main(){
    User U;
    CreateUser(&U, "JohnDoe", "password123", 1000);

    // Menambah item ke keranjang
    // AddToKeranjang(&U, 1, 10);  // Misal item dengan key=1, value=10
    // AddToKeranjang(&U, 2, 20);  // Misal item dengan key=2, value=20

    // // Menambah item ke wishlist
    AddToWishlist(&U, "Item 0");
    AddToWishlist(&U, "Item 1");
    AddToWishlist(&U, "Item 2");

    // // Menampilkan informasi user setelah pembaruan
    // printf("\nInformasi User Setelah Pembuatan dan Menambah Item:\n");
    // PrintUserInfo(&U);

    // // Menghapus item dari wishlist
    // RemoveFromWishlist(&U, "Item 0");

    // // Menghapus item dari keranjang
    // RemoveFromKeranjang(&U, 2);

    // // Menampilkan informasi user setelah penghapusan
    // printf("\nInformasi User Setelah Penghapusan Item:\n");


    wishlistSwap(&U,1,2);
}