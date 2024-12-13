#include <stdio.h>
#include <string.h>
#include "user2.h"
#include "map.h"
#include "stack.h"
#include "listlinier.h"
#include "mesinkata.c"
#include "mesinkarakter.c"
#include "mesinangka.c"
#include "map.c"
#include "stack.c"
#include "listlinier.c"
#include "../../utilities.c"

/* Fungsi untuk membuat User baru */void CreateUser(User *U, const char *name, const char *password, int money) {
    U->money = money;
    copyString(U->name, name); 
    copyString(U->password, password);

    // Inisialisasi Map, Stack, dan List
    CreateMapEmpty(&U->keranjang);  // Pastikan Map diinisialisasi dengan benar
    CreateStackEmpty(&U->riwayat_pembelian);  // Pastikan Stack diinisialisasi dengan benar
    CreateListEmpty(&U->wishlist);  // Pastikan List diinisialisasi dengan benar
}

// Fungsi untuk menambahkan item ke wishlist
void AddToWishlist(User *U, infoListtype item) {
    InsVLast(&U->wishlist, item);  // Menambahkan item ke akhir wishlist
}

// Fungsi untuk menghapus item dari wishlist
void RemoveFromWishlist(User *U, infoListtype item) {
    addressList P = Search(U->wishlist, item);  // Mencari posisi item dalam wishlist
    if (P != Nil) {
        DelP(&U->wishlist, item);  // Menghapus item jika ditemukan
    } else {
    }
}

// Fungsi untuk menambahkan item ke keranjang
void AddToKeranjang(User *U, keytype k, valuetype v) {
    Insert(&U->keranjang, k, v);  // Menambahkan item ke Map keranjang
}

// Fungsi untuk menghapus item dari keranjang
void RemoveFromKeranjang(User *U, keytype k) {
    Delete(&U->keranjang, k);  // Menghapus item dari Map keranjang
}

// Fungsi untuk menampilkan informasi user
void PrintUserInfo(User *U) {
    printf("User: %s\n", U->name);
    printf("Money: %d\n", U->money);

    // Menampilkan keranjang
    printf("Keranjang:\n");
    for (int i = 0; i < U->keranjang.Count; i++) {
        printf("  Key: %d, Value: %d\n", U->keranjang.Elements[i].Key, U->keranjang.Elements[i].Value);
    }

    // Menampilkan riwayat pembelian
    printf("Riwayat Pembelian:\n");
    for (int i = 0; i <= U->riwayat_pembelian.TOP; i++) {
        printf("  Item %d\n", U->riwayat_pembelian.T[i]);
    }

    // Menampilkan wishlist
    printf("Wishlist:\n");
    addressList P = First(U->wishlist);
    while (P != Nil) {
        printf("  %s\n", Info(P));
        P = Next(P);
    }
}
