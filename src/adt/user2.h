#ifndef USER2_H
#define USER2_H

#include "boolean.h"
#include "map.h"
#include "stack.h"
#include "listlinier.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "mesinangka.h"
#include "../../utilities.h"

/*#define MAX_LEN 100

// Struktur User
typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
    Map keranjang;             // Map untuk keranjang belanja
    Stack riwayat_pembelian;   // Stack untuk riwayat pembelian
    List wishlist;             // List untuk wishlist
} User;

boolean isEmptyUser(User U);
boolean isEmptyUserList(User U);
boolean isEmptyUserMap(User U);
boolean isEmptyUserStack(User U);
// Fungsi untuk membuat User baru
void CreateUser(User *U, const charname, const char *password, int money);

// Fungsi untuk menambahkan item ke wishlist
void AddToWishlist(UserU, infoListtype item);

// Fungsi untuk menghapus item dari wishlist
void RemoveFromWishlist(User U, infoListtype item);

addressList SearchWishList(UserU, infoListtype item);

// Fungsi untuk menambahkan item ke keranjang
void AddToKeranjang(User U, keytype k, valuetype v);

// Fungsi untuk menghapus item dari keranjang
void RemoveFromKeranjang(UserU, keytype k);

// Fungsi untuk menambah riwayat pembelian ke Stack
void AddToRiwayat(User U, infoStacktype item);

// Fungsi untuk menampilkan informasi user
void PrintUserInfo(UserU);

#endif // USER2_H

*/
 // Untuk ADT List Linear

typedef struct {
    char name[50];
    char password[50];
    int money;
    Map keranjang;           // Keranjang belanja menggunakan Map
    Stack riwayat_pembelian; // Riwayat pembelian menggunakan Stack
    List wishlist;           // Wishlist menggunakan List Linear
} User;

/* *** Fungsi dan Prosedur User *** */
void CreateUser(User *U, const char *name, const char *password, int money);
void AddToWishlist(User *U, infoListtype item);
addressList SearchWishList(User *U, infoListtype item);
int WishlistCount(User *U);
void AddToKeranjang(User *U, keytype k, valuetype v);
void RemoveFromKeranjang(User *U, keytype k);
void PrintUserInfo(User *U);

#endif /* USER2_H */
