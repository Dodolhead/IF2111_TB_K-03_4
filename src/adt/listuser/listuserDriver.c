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

int main() {
    // Membuat list kosong
    List userList = MakeList();
    printf("List berhasil dibuat.\n");

    // Menambahkan pengguna pertama
    Map keranjang;
    Stack riwayat;
    LinkedList wishlist;

    CreateMapEmpty(&keranjang);
    CreateStackEmpty(&riwayat);
    CreateLinkedListEmpty(&wishlist);
    

    InsertListAt(&userList, 100000, "admin", "admin123", keranjang, riwayat, wishlist, 0);
    printf("Menambahkan pengguna pertama.\n");


    InsertListAt(&userList, 50000, "user1", "password1", keranjang, riwayat, wishlist, 1);
    printf("Menambahkan pengguna kedua.\n");
    PrintUserInfo(userList, 1);
    
    InsertListAt(&userList, 75000, "user2", "password2", keranjang, riwayat, wishlist, 2);
    printf("Menambahkan pengguna ketiga di posisi tengah.\n");
    //PrintUserInfo(userList, 2);
    
    ListUserLength(userList);
    PrintUserInfo(userList, 0);


    DeleteListLast(&userList);
    printf("Menghapus pengguna terakhir.\n");

    // Menampilkan ulang seluruh elemen
    printf("List pengguna setelah semua operasi:\n");


    // Menambahkan item ke wishlist pengguna pertama
    AddToWishlist(&userList.A[0], "Barang 1");
    AddToWishlist(&userList.A[0], "Barang 2");
    printf("Wishlist pengguna pertama setelah penambahan:\n");


}
