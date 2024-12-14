#include <stdio.h>
#include <stdlib.h>
#include "wishlist_remove.h"
#include "..\..\adt\user2.c"

void wishlistRemove(User *U){
    printf("Masukkan nama barang yang akan dihapus: ");
    STARTSENTENCE();
    addressList P = SearchWishList(U, CurrentWord.TabWord);
    if (P == Nil || isEmptyUserList(U)) {
        printf("%s Tidak ada di wishlist\n",CurrentWord.TabWord);
    }
    else{
        RemoveFromWishlist(U, CurrentWord.TabWord);
        printf("%s berhasil dihapus dari WISHLIST!\n", CurrentWord.TabWord);
    }
}

int main() {
    User U;
    CreateUser(&U, "JohnDoe", "password123", 1000);

    // Menambah item ke keranjang
    AddToKeranjang(&U, 1, 10);  // Misal item dengan key=1, value=10
    AddToKeranjang(&U, 2, 20);  // Misal item dengan key=2, value=20

    // Menambah item ke wishlist
    AddToWishlist(&U, "Lorem");
    AddToWishlist(&U, "Item 1");
    AddToWishlist(&U, "Item 2");


    PrintUserInfo(&U);
    wishlistRemove(&U);
    PrintUserInfo(&U);
}