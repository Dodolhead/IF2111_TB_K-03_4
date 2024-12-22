#include <stdio.h>
#include "listuser.h"
#include "listuser.c"
#include "../../adt/map/map.c"
#include "../../adt/stack/stack.c"
#include "../../adt/mesinkata/mesinkata.c"
#include "../../adt/mesinkarakter/mesinkarakter.c"
#include "../../adt/mesinangka/mesinangka.c"
#include "../../adt/listlinier/listlinier.c"
#include "../../../utilities.c"

// #include <stdio.h>
// #include "listuser.h"
// #include "../../adt/map/map.h"
// #include "../../adt/stack/stack.h"
// #include "../../adt/mesinkata/mesinkata.h"
// #include "../../adt/mesinkarakter/mesinkarakter.h"
// #include "../../adt/mesinangka/mesinangka.h"
// #include "../../adt/listlinier/listlinier.h"


int main() {
    // Inisialisasi list pengguna
    List userList;
    MakeList(&userList);

    printf("=== TEST LISTUSER ===\n");

    // Test IsListEmpty
    if (IsListEmpty(&userList)) {
        printf("[PASSED] IsListEmpty: List pengguna kosong.\n");
    } else {
        printf("[FAILED] IsListEmpty: List pengguna tidak kosong.\n");
    }

    // Menambahkan pengguna baru
    Map keranjang;
    CreateMapEmpty(&keranjang);
    Stack riwayat;
    CreateStackEmpty(&riwayat);
    LinkedList wishlist;
    CreateLinkedListEmpty(&wishlist);

    InsertListLast(&userList, 100, "user1", "pass1", keranjang, riwayat, wishlist);
    InsertListLast(&userList, 200, "user2", "pass2", keranjang, riwayat, wishlist);

    // Test ListUserLength
    printf("[INFO] Jumlah pengguna: %d\n", ListUserLength(&userList));

    // Test GetName dan GetPassword
    char bufferName[MAX_LEN];
    char bufferPassword[MAX_LEN];
    GetName(&userList, 0, bufferName);
    GetPassword(&userList, 0, bufferPassword);
    printf("[INFO] Pengguna 1: Nama=%s, Password=%s\n", bufferName, bufferPassword);

    GetName(&userList, 1, bufferName);
    GetPassword(&userList, 1, bufferPassword);
    printf("[INFO] Pengguna 2: Nama=%s, Password=%s\n", bufferName, bufferPassword);

    // // Test AddToWishlist
    AddToWishlist(&userList.A[0], "Barang A");
    AddToWishlist(&userList.A[0], "Barang B");
    PrintWishlist(&userList, 0);

    // Test RemoveFromWishlist
    RemoveFromWishlist(&userList.A[0], "Barang A");
    PrintWishlist(&userList, 0);

    // Test AddToKeranjang
    AddToKeranjang(&userList.A[0], "Barang A", 10);
    AddToKeranjang(&userList.A[0], "Barang B", 20);
    PrintKeranjang(&userList, 0);

    // // Test RemoveFromKeranjang
    RemoveFromKeranjang(&userList.A[0], "Barang A");
    PrintKeranjang(&userList, 0);

    // Test DeleteListFirst
    DeleteListFirst(&userList);
    printf("[INFO] Setelah DeleteListFirst: Jumlah pengguna=%d\n", ListUserLength(&userList));

    // // Test DeleteListLast
    DeleteListLast(&userList);
    printf("[INFO] Setelah DeleteListLast: Jumlah pengguna=%d\n", ListUserLength(&userList));

    printf("=== TEST SELESAI ===\n");

    return 0;
}
