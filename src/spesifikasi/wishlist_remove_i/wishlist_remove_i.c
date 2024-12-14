#include <stdio.h>
#include <stdlib.h>
#include "wishlist_remove_i.h"
#include "..\..\adt\user2.c"


void wishlistRemoveI(User *U) {
    addressList P = First(U->wishlist);
    int n;
    STARTANGKA();
    n = bacaAngka()-1;
    if (n == -1){
        printf("Penghapusan barang WISHLIST gagal dilakukan, command tidak valid!\n");
    }
    else if (n > WishlistCount(U)){
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n",n+1);
    }
    else{
        for (int i=0;i<n;i++){
            P = Next(P);
        }
        RemoveFromWishlist(U, Info(P));
        printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n",n+1);
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
    PrintUserInfo(&U);


    wishlistRemoveI(&U);
    PrintUserInfo(&U);
}