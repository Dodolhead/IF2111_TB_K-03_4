#include <stdio.h>
#include "listuser.h"
#include "../../adt/map/map.c"
#include "../../adt/stack/stack.c"
#include "../../adt/mesinkata/mesinkata.c"
#include "../../adt/mesinkarakter/mesinkarakter.c"
#include "../../adt/mesinangka/mesinangka.c"
#include "../../adt/listlinier/listlinier.c"
#include "../../../utilities.c"

int main() {
    // Inisialisasi list pengguna
    List users = MakeList();

    // Membuat pengguna contoh
    Map keranjang1;
    CreateMapEmpty(&keranjang1);
    Stack riwayat1;
    CreateStackEmpty(&riwayat1);
    LinkedList wishlist1;
    CreateLinkedListEmpty(&wishlist1);

    InsertListLast(&users, 1000, "John Doe", "pass123", keranjang1, riwayat1, wishlist1);

    // Menambahkan item ke keranjang
    InsertMap(&users.A[0].keranjang, 101, 5000); // Key: 101, Value: 5000

    // Menambahkan item ke wishlist
    AddToWishlist(&users.A[0], "Laptop Gaming");
    AddToWishlist(&users.A[0], "Headset Wireless");

    // Menambahkan item ke riwayat pembelian
    Barang purchasedItem = {"Mouse", 200000, 1};
    Push(&users.A[0].riwayat_pembelian, purchasedItem);

    // Memanggil PrintUserInfo untuk pengguna pertama
    printf("Informasi Pengguna:\n");
    PrintUserInfo(users, 0);

    return 0;
}

