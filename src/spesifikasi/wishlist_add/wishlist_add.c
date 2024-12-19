#include <stdio.h>
#include <stdlib.h>
#include "wishlist_add.h"
#include "..\..\adt\user2.c"

void wishlistAdd(User *U){
    printf("Masukkan nama barang: ");
    STARTWORD();
    addressList P = SearchWishList(U, currentWord.TabWord);
    if (P == Nil || isEmptyUserList(U)) {
        AddToWishlist(U, currentWord.TabWord);
        printf("Berhasil menambahkan %s ke wishlist!\n",currentWord.TabWord);
    }
    else{
        printf("%s sudah ada di wishlist!\n",currentWord.TabWord);
    }
}

int main() {
    User U;
    CreateUser(&U, "JohnDoe", "password123", 1000);

    wishlistAdd(&U);
    PrintUserInfo(&U);
    wishlistAdd(&U);
    PrintUserInfo(&U);
    wishlistAdd(&U);
    PrintUserInfo(&U);
}