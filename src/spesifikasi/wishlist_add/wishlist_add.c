#include <stdio.h>
#include <stdlib.h>
#include "wishlist_add.h"
#include "..\..\adt\user2.c"

void wishlistAdd(User *U){
    printf("Masukkan nama barang: ");
    STARTWORD();
    addressList P = SearchWishList(U, CurrentWord.TabWord);
    if (P == Nil || isEmptyUserList(U)) {
        AddToWishlist(U, CurrentWord.TabWord);
        printf("Berhasil menambahkan %s ke wishlist!\n",CurrentWord.TabWord);
    }
    else{
        printf("%s sudah ada di wishlist!\n",CurrentWord.TabWord);
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