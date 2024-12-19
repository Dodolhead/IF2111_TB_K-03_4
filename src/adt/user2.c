#include <stdio.h>
#include <string.h>
#include "user2.h"



boolean isEmptyUser(User U) {
    return IsListEmpty(U.wishlist) && IsMapEmpty(U.keranjang) && IsStackEmpty(U.riwayat_pembelian);
}
boolean isEmptyUserList(User U) {
    return IsListEmpty(U.wishlist);
}
boolean isEmptyUserMap(User U) {
    return IsMapEmpty(U.keranjang);
}
boolean isEmptyUserStack(User U) {
    return IsStackEmpty(U.riwayat_pembelian);
}
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
    // Alokasi memori untuk string baru
    char* copyItem = (char*)malloc((strlen(item) + 1) * sizeof(char));
    copyString(copyItem, item);  // Salin string ke memori baru

    InsVLast(&U->wishlist, copyItem);  // Tambahkan string baru ke wishlist
}
// Fungsi untuk menghapus item dari wishlist
void RemoveFromWishlist(User *U, infoListtype item) {
    addressList P = SearchWishList(U, item); // Cari item dalam wishlist
    if (P != Nil) { // Jika ditemukan
        DelPWishList(&U->wishlist, item); // Hapus elemen
    } else {
        printf("Item '%s' tidak ditemukan di wishlist.\n", item);
    }
}

addressList SearchWishList(User *U, char* item) {
    addressList P = First(U->wishlist);  // Mulai dari elemen pertama di wishlist
    while (P != Nil) {
        if (stringEquals(P->info, item)) {  // Gunakan stringEquals untuk membandingkan
            return P;  // Jika ditemukan, kembalikan alamat elemen
        }
        P = P->next;  // Lanjut ke elemen berikutnya
    }
    return Nil;  // Tidak ditemukan
}

void DelPWishList(List *L, infoListtype X) {
    addressList P = First(*L);
    addressList Prec = Nil;

    // Cari elemen yang cocok
    while (P != Nil && !stringEquals(Info(P), X)) {
        Prec = P;
        P = Next(P);
    }

    // Jika ditemukan, hapus elemen
    if (P != Nil) {
        if (Prec == Nil) { // Jika elemen pertama
            First(*L) = Next(P);
        } else { // Jika elemen di tengah/akhir
            Next(Prec) = Next(P);
        }
        Dealokasi(&P);
    }
}

int WishlistCount(User *U) {
    int count = NbElmt(U->wishlist);
    return count;
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
        printf("Key: %d, Value: %d\n", U->keranjang.Elements[i].Key, U->keranjang.Elements[i].Value);
    }

    // Menampilkan riwayat pembelian
    printf("Riwayat Pembelian:\n");
    for (int i = 0; i <= U->riwayat_pembelian.TOP; i++) {
        printf(" %d\n", U->riwayat_pembelian.T[i]);
    }

    // Menampilkan wishlist
    printf("Wishlist:\n");
    addressList P = First(U->wishlist);
    while (P != Nil) {
        printf("- %s\n", Info(P));
        P = Next(P);
    }
    printf("\n");
}
