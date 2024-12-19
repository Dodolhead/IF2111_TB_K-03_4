#include <stdio.h>
#include <stdlib.h>
#include "wishlist_add.h"
#include "../../adt/listuser/listuser.c"

void wishlistAdd(User *U){
    printf("Masukkan nama barang: ");
    STARTWORD();
    addressLinkedList P = SearchWishList(U, currentWord.TabWord);
    if (P == Nil || isEmptyUserLinkedList(*U)) {
        AddToWishlist(U, currentWord.TabWord);
        printf("Berhasil menambahkan %s ke wishlist!\n",currentWord.TabWord);
    }
    else{
        printf("%s sudah ada di wishlist!\n",currentWord.TabWord);
    }
}

int main() {
    List U = MakeList();
    LinkedList wishlist;
    CreateLinkedListEmpty(&wishlist);

    wishlistAdd(&U.A[0]);
    PrintUserInfo(U.A[0],0);
}