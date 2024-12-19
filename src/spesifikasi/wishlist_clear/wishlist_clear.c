#include <stdio.h>
#include <stdlib.h>
#include "wishlist_clear.h"
#include "../../adt/listuser/listuser.c"

void wishlistClear(User *U) {
    addressLinkedLis P = First(U->wishlist);
    addressLinkedLis temp;

    while (P != Nil) {
        temp = P;            // Simpan elemen saat ini
        P = Next(P);         // Pindah ke elemen berikutnya
        free(Info(temp));    // Bebaskan memori string
        free(temp);          // Bebaskan node
    }

    First(U->wishlist) = Nil; // Setel ulang pointer wishlist menjadi kosong
    printf("Wishlist telah dikosongkan.\n");
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

    // Menampilkan informasi user setelah pembaruan
    printf("\nInformasi User Setelah Pembuatan dan Menambah Item:\n");
    PrintUserInfo(&U);

    // Menghapus item dari wishlist
    RemoveFromWishlist(&U, "Item 0");

    // Menghapus item dari keranjang
    RemoveFromKeranjang(&U, 2);

    // Menampilkan informasi user setelah penghapusan
    printf("\nInformasi User Setelah Penghapusan Item:\n");
    PrintUserInfo(&U);
    wishlistClear(&U);
    PrintUserInfo(&U);
}