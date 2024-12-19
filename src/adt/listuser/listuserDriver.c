#include <stdio.h>
#include "listuser.h"

int main() {
    // Membuat List User
    List userList = MakeList();

    // Menambahkan beberapa pengguna ke dalam list
    InsertListFirst(&userList, 100000, "admin", "admin");
    InsertListAt(&userList, 50000, "user1", "pass1", 1);
    InsertListLast(&userList, 25000, "user2", "pass2");

    // Menampilkan jumlah pengguna di list
    printf("Jumlah pengguna: %d\n", ListUserLength(userList));

    // Menampilkan informasi setiap pengguna
    char buffer[100];
    for (int i = 0; i < ListUserLength(userList); i++) {
        printf("Pengguna %d:\n", i + 1);
        printf("  Saldo: %d\n", GetMoney(userList, i));
        GetName(userList, i, buffer);
        printf("  Nama: %s\n", buffer);
        GetPassword(userList, i, buffer);
        printf("  Password: %s\n", buffer);
    }

    // Menghapus pengguna
    DeleteListAt(&userList, 1);
    printf("\nSetelah menghapus pengguna kedua:\n");
    printf("Jumlah pengguna: %d\n", ListUserLength(userList));

    // Menampilkan informasi pengguna yang tersisa
    for (int i = 0; i < ListUserLength(userList); i++) {
        printf("Pengguna %d:\n", i + 1);
        printf("  Saldo: %d\n", GetMoney(userList, i));
        GetName(userList, i, buffer);
        printf("  Nama: %s\n", buffer);
        GetPassword(userList, i, buffer);
        printf("  Password: %s\n", buffer);
    }

    return 0;
}
