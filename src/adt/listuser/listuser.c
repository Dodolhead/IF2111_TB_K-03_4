#include <stdio.h>
#include <stdlib.h>
#include "listuser.h"

List MakeList() {
    List U;
    for (int i = 0; i < MaxEl; i++) {
        U.A[i].money = MarkNumber; // Inisialisasi nilai `money` dengan tanda khusus
        U.A[i].name[0] = '\0';     // Set nama awal menjadi string kosong
        U.A[i].password[0] = '\0'; // Set password awal menjadi string kosong

        // Inisialisasi elemen-elemen dalam struct User
        CreateMapEmpty(&U.A[i].keranjang);             // Pastikan Map diinisialisasi dengan benar
        CreateStackEmpty(&U.A[i].riwayat_pembelian);   // Pastikan Stack diinisialisasi dengan benar
        CreateLinkedListEmpty(&U.A[i].wishlist);       // Pastikan LinkedList diinisialisasi dengan benar
    }
    return U;
}

boolean isEmptyUser(User U) {
    return IsLinkedListEmpty(U.wishlist) && IsMapEmpty(U.keranjang) && IsStackEmpty(U.riwayat_pembelian);
}
boolean isEmptyUserLinkedList(User U) {
    return IsLinkedListEmpty(U.wishlist);
}
boolean isEmptyUserMap(User U) {
    return IsMapEmpty(U.keranjang);
}
boolean isEmptyUserStack(User U) {
    return IsStackEmpty(U.riwayat_pembelian);
}

/* Membentuk list kosong dengan elemen yang diisi MarkNumber/MarkName */

boolean IsListEmpty(List U) {
    return (U.A[0].money == MarkNumber && U.A[0].name[0] == '\0' && U.A[0].password[0] == '\0' && IsLinkedListEmpty(U.A[0].wishlist) && IsMapEmpty(U.A[0].keranjang) && IsStackEmpty(U.A[0].riwayat_pembelian));
}
/* Mengembalikan true jika list kosong */

int GetMoney(List U, IdxType i) {
    return U.A[i].money;
}

void GetName(List U, IdxType i, char* buffer) {
    copyString(buffer, U.A[i].name);
}

void GetPassword(List U, IdxType i, char* buffer) {
    copyString(buffer, U.A[i].password);
}

/* Mengambil elemen pada indeks ke-i */

void Set(List *U, IdxType i, int money, char* name, char* password) {
    U->A[i].money = money;
    copyString(U->A[i].name, name);
    copyString(U->A[i].password, password);
}
/* Mengubah elemen pada indeks ke-i dengan nilai baru */

int ListUserLength(List U) {
    int count = 0;
    while (count < MaxEl && U.A[count].money != MarkNumber) {
        count++;
    }
    return count;
}
/* Mengembalikan jumlah elemen efektif dalam list */

IdxType FirstIdx(List U) {
    return 0;
}
/* Mengembalikan indeks elemen pertama */

IdxType LastIdx(List U) {
    return ListUserLength(U) - 1;
}
/* Mengembalikan indeks elemen terakhir */

boolean IsIdxValid(List U, IdxType i) {
    return i < MaxEl && i >= 0;
}
/* Mengecek apakah indeks valid untuk list */

boolean IsIdxEff(List U, IdxType i) {
    return i <= LastIdx(U) && i >= FirstIdx(U);
}
/* Mengecek apakah indeks efektif (elemen diisi) dalam list */

boolean ListSearch(List U, char* X) {
    for (int i = 0; i < ListUserLength(U); i++) {
        if (stringEquals(U.A[i].name, X)) {
            return true;
        }
    }
    return false;
}
/* Mengecek apakah elemen X terdapat dalam list */

void InsertListFirst(List *U, int money, char* name, char* password) {
    InsertListAt(U, money, name, password, 0);
}
/* Menyisipkan elemen di posisi pertama */

void InsertListAt(List *U, int money, char* name, char* password, IdxType i) {
    if (ListUserLength(*U) < MaxEl && i >= 0 && i <= ListUserLength(*U)) {
        for (int j = ListUserLength(*U); j > i; j--) {
            U->A[j] = U->A[j - 1];
        }
        Set(U, i, money, name, password);
    }
}
/* Menyisipkan elemen di posisi indeks ke-i */

void InsertListLast(List *U, int money, char* name, char* password) {
    if (ListUserLength(*U) < MaxEl) {
        Set(U, ListUserLength(*U), money, name, password);
    }
}
/* Menyisipkan elemen di posisi terakhir */

void DeleteListFirst(List *U) {
    DeleteListAt(U, 0);
}
/* Menghapus elemen di posisi pertama */

void DeleteListAt(List *U, IdxType i) {
    int panjang = ListUserLength(*U);
    if (panjang > 0 && i >= 0 && i < panjang) {
        // Geser elemen dari indeks i ke depan
        for (IdxType j = i; j < panjang - 1; j++) {
            U->A[j] = U->A[j + 1];
        }
        // Hapus elemen terakhir (nilai tidak terpakai)
        U->A[panjang - 1].money = MarkNumber;
        U->A[panjang - 1].name[0] = '\0';
        U->A[panjang - 1].password[0] = '\0';

        // Update panjang list
        panjang--;  // Pastikan untuk mengurangi jumlah elemen
    }
}

/* Menghapus elemen di posisi indeks ke-i */

void DeleteListLast(List *U) {
    DeleteListAt(U, LastIdx(*U));
}
/* Menghapus elemen di posisi terakhir */


// Fungsi untuk menambahkan item ke wishlist
void AddToWishlist(User *U, infoLinkedListtype item) {
    // Alokasi memori untuk string baru
    char* copyItem = (char*)malloc((WishlistCount(U)) * sizeof(char));
    copyString(copyItem, item);  // Salin string ke memori baru

    InsVLast(&U->wishlist, copyItem);  // Tambahkan string baru ke wishlist
}
// Fungsi untuk menghapus item dari wishlist
void RemoveFromWishlist(User *U, infoLinkedListtype item) {
    addressLinkedList P = SearchWishList(U, item); // Cari item dalam wishlist
    if (P != Nil) { // Jika ditemukan
        DelPWishList(&U->wishlist, item); // Hapus elemen
    } else {
        printf("Item '%s' tidak ditemukan di wishlist.\n", item);
    }
}

addressLinkedList SearchWishList(User *U, char* item) {
    addressLinkedList P = First(U->wishlist);  // Mulai dari elemen pertama di wishlist
    while (P != Nil) {
        if (stringEquals(P->info, item)) {  // Gunakan stringEquals untuk membandingkan
            return P;  // Jika ditemukan, kembalikan alamat elemen
        }
        P = P->next;  // Lanjut ke elemen berikutnya
    }
    return Nil;  // Tidak ditemukan
}

void DelPWishList(LinkedList *L, infoLinkedListtype X) {
    addressLinkedList P = First(*L);
    addressLinkedList Prec = Nil;

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
// Menampilkan riwayat pembelian
    printf("Riwayat Pembelian:\n");
    for (int i = 0; i <= U->riwayat_pembelian.TOP; i++) {
        printf("Nama Barang: %s, Harga: %d, Jumlah: %d\n",
            U->riwayat_pembelian.T[i].name,
            U->riwayat_pembelian.T[i].price,
            U->riwayat_pembelian.T[i].jumlahBarang);
    }


    // Menampilkan wishlist
    printf("Wishlist:\n");
    addressLinkedList P = First(U->wishlist);
    while (P != Nil) {
        printf("- %s\n", Info(P));
        P = Next(P);
    }
    printf("\n");
}

// int main() {
//     List U = MakeList();
//     InsertListFirst(&U, 100000, "admin", "admin");
//     InsertListAt(&U, 100000, "dapid", "idiot",1);
//     InsertListLast(&U, 50000, "user", "user");
//     InsertListLast(&U, 50000, "asu", "user");

//     printf("ListUserLength before DeleteAt: %d\n", ListUserLength(U));
//     DeleteListAt(&U, 2);
//     printf("ListUserLength after DeleteAt: %d\n", ListUserLength(U));


//     char buffer[50];
//     for (int i = 0; i < ListUserLength(U); i++) {
//         printf("%d\n", GetMoney(U, i));
//         GetName(U, i, buffer);
//         printf("%s\n", buffer);
//         GetPassword(U, i, buffer);
//         printf("%s\n", buffer);
//     }
// }