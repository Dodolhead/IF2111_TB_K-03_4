#include <stdio.h>
#include "listuser.h"
/*#include "listuser.c"
#include "../../adt/map/map.c"
#include "../../adt/stack/stack.c"
#include "../../adt/mesinkata/mesinkata.c"
#include "../../adt/mesinkarakter/mesinkarakter.c"
#include "../../adt/mesinangka/mesinangka.c"
#include "../../adt/listlinier/listlinier.c"
#include "../../../utilities.c"*/

#include <stdio.h>
#include "listuser.h"
#include "../../adt/map/map.h"
#include "../../adt/stack/stack.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/mesinkarakter/mesinkarakter.h"
#include "../../adt/mesinangka/mesinangka.h"
#include "../../adt/listlinier/listlinier.h"

void testAllFunctions() {
    // Membuat list user
    List userList = MakeList();

    // Menambahkan user baru ke list
    printf("Menambahkan User ke List:\n");
    Map keranjang;
    Stack riwayat;
    LinkedList wishlist;
    CreateMapEmpty(&keranjang);
    CreateStackEmpty(&riwayat);
    CreateLinkedListEmpty(&wishlist);

    InsertListLast(&userList, 1000, "User1", "password1", keranjang, riwayat, wishlist);
    InsertListLast(&userList, 500, "User2", "password2", keranjang, riwayat, wishlist);
    PrintUserLengkap(&userList, 0);
    PrintUserLengkap(&userList, 1);

    // Mengakses atribut user
    printf("\nMengakses atribut user:\n");
    char buffer[50];
    GetName(userList, 0, buffer);
    printf("Nama user pertama: %s\n", buffer);

    GetPassword(userList, 1, buffer);
    printf("Password user kedua: %s\n", buffer);

    printf("Uang user pertama: %d\n", GetMoney(userList, 0));

    // Menambah item ke wishlist
    printf("\nMenambah item ke wishlist:\n");
    AddToWishlist(&userList.A[0], "Item1");
    AddToWishlist(&userList.A[0], "Item2");
    PrintWishlist(&userList, 0);

    // Menghapus item dari wishlist
    printf("\nMenghapus item dari wishlist:\n");
    RemoveFromWishlist(&userList.A[0], "Item1");
    PrintWishlist(&userList, 0);

    // Menambah item ke keranjang
    printf("\nMenambah item ke keranjang:\n");
    AddToKeranjang(&userList.A[0], 1, 10);
    AddToKeranjang(&userList.A[0], 2, 20);
    PrintKeranjang(&userList, 0);

    // Menghapus item dari keranjang
    printf("\nMenghapus item dari keranjang:\n");
    RemoveFromKeranjang(&userList.A[0], 1);
    PrintKeranjang(&userList, 0);

    // Menambah riwayat pembelian
    printf("\nMenambah riwayat pembelian:\n");
    Push(&userList.A[0].riwayat_pembelian, "Barang1", 500);
    Push(&userList.A[0].riwayat_pembelian, "Barang2", 1000);
    PrintRiwayatPembelian(&userList, 0);

    // Menghapus user dari list
    printf("\nMenghapus user pertama dari list:\n");
    DeleteListFirst(&userList);
    if (IsListEmpty(userList)) {
        printf("List kosong setelah penghapusan.\n");
    } else {
        PrintUserLengkap(&userList, 0);
    }

    printf("\nTesting selesai.\n");
}

int main() {
    printf("Testing semua fungsi:\n\n");
    testAllFunctions();
    return 0;
}
