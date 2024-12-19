#include <stdio.h>
#include "listuser.h"

int main() {
    // Membuat list pengguna
    List userList = MakeList();

    // Menambahkan pengguna ke list
    printf("Menambahkan pengguna ke list:\n");
    InsertListFirst(&userList, 100000, "admin", "admin123");
    InsertListAt(&userList, 50000, "user1", "password1", 1);
    InsertListLast(&userList, 75000, "user2", "password2");

    // Menampilkan panjang list setelah penambahan
    printf("\nJumlah pengguna dalam list: %d\n", ListUserLength(userList));

    // Menampilkan informasi pengguna
    printf("\nInformasi pengguna dalam list:\n");
    char buffer[50];
    for (int i = 0; i < ListUserLength(userList); i++) {
        printf("Index %d:\n", i);
        printf("  Money: %d\n", GetMoney(userList, i));
        GetName(userList, i, buffer);
        printf("  Name: %s\n", buffer);
        GetPassword(userList, i, buffer);
        printf("  Password: %s\n", buffer);
    }

    // Menghapus pengguna pada indeks ke-1
    printf("\nMenghapus pengguna pada indeks ke-1:\n");
    DeleteListAt(&userList, 1);

    // Menampilkan panjang list setelah penghapusan
    printf("Jumlah pengguna setelah penghapusan: %d\n", ListUserLength(userList));

    // Menampilkan informasi pengguna setelah penghapusan
    printf("\nInformasi pengguna dalam list setelah penghapusan:\n");
    for (int i = 0; i < ListUserLength(userList); i++) {
        printf("Index %d:\n", i);
        printf("  Money: %d\n", GetMoney(userList, i));
        GetName(userList, i, buffer);
        printf("  Name: %s\n", buffer);
        GetPassword(userList, i, buffer);
        printf("  Password: %s\n", buffer);
    }

    // Menambahkan wishlist ke pengguna pertama
    printf("\nMenambahkan wishlist ke pengguna pertama:\n");
    AddToWishlist(&userList.A[0], "Wishlist Item 1");
    AddToWishlist(&userList.A[0], "Wishlist Item 2");

    // Menampilkan wishlist pengguna pertama
    printf("Wishlist pengguna pertama:\n");
    PrintUserInfo(&userList.A[0]);

    // Menghapus elemen wishlist
    printf("\nMenghapus wishlist 'Wishlist Item 1':\n");
    DelPWishList(&userList.A[0].wishlist, "Wishlist Item 1");

    // Menampilkan wishlist setelah penghapusan
    printf("Wishlist pengguna pertama setelah penghapusan:\n");
    PrintUserInfo(&userList.A[0]);

    return 0;
}
