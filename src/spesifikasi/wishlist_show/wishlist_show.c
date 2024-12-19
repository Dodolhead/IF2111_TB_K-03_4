#include <stdio.h>
#include <stdlib.h>
#include "wishlist_show.h"
#include "../../adt/listuser/listuser.c"

void wishlistShow(User U){
    printf("Wishlist:\n");
    addressLinkedList P = First(U.wishlist);
    if (isEmptyUserLinkedList(U)){
        printf("Wishlist kamu kosong!");
    }
    else{
        while (P != Nil) {
            printf("- %s\n", Info(P));
            P = Next(P);
        }
    }
}

int main() {
    User U;
    CreateUser(&U, "JohnDoe", "password123", 1000);

    // Menambah item ke keranjang
    AddToKeranjang(&U, 1, 10);  // Misal item dengan key=1, value=10
    AddToKeranjang(&U, 2, 20);  // Misal item dengan key=2, value=20

    // Menambah item ke wishlist
    AddToWishlist(&U, "Item 0");
    AddToWishlist(&U, "Item 1");
    AddToWishlist(&U, "Item 2");
    wishlistShow(U);
}