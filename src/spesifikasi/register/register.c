#include "register.h"
#include <stdio.h>
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/mesinkarakter/mesinkarakter.h"
#include "../../adt/listuser/listuser.h"
#include "../../adt/map/map.h"
#include "../../adt/stack/stack.h"
#include "../../adt/listlinier/listlinier.h"

void REGISTER(List *users) {
    printf(">> REGISTER\n");

    // Input username
    printf("Masukkan username: ");
    STARTWORD();
    char username[MAX_LEN];
    for (int i = 0; i < currentWord.Length; i++) {
        username[i] = currentWord.TabWord[i];
    }
    username[currentWord.Length] = '\0';

    // Periksa apakah username sudah ada
    if (ListSearch(*users, username)) {
        printf("Username %s sudah terdaftar. Silakan gunakan username lain.\n", username);
        return;
    }

    // Input password
    printf("Masukkan password: ");
    STARTWORD();
    char password[MAX_LEN];
    for (int i = 0; i < currentWord.Length; i++) {
        password[i] = currentWord.TabWord[i];
    }
    password[currentWord.Length] = '\0';
    Map keranjang;
    CreateMapEmpty(&keranjang);
    Stack riwayatPembelian;
    CreateStackEmpty(&riwayatPembelian);
    LinkedList wishlist;
    CreateLinkedListEmpty(&wishlist);

    // Tambahkan pengguna baru
    InsertListLast(users, 0, username, password,keranjang ,riwayatPembelian ,wishlist); // Tambahkan pengguna baru dengan saldo awal 0

    printf("Pendaftaran berhasil. Selamat datang, %s!\n", username);
}

// int main() {
//     List users;
//     MakeList(&users);

//     printf("--- DRIVER REGISTER ---\n");

//     printf("Simulasi 1: Pendaftaran pengguna baru\n");
//     REGISTER(&users);

//     printf("\nSimulasi 2: Pendaftaran dengan username yang sama\n");
//     REGISTER(&users);

//     printf("\n--- DEBUG LIST USERS ---\n");
//     for (int i = 0; i < ListUserLength(users); i++) {
//         char bufferName[MAX_LEN];
//         char bufferPassword[MAX_LEN];
//         GetName(users, i, bufferName);
//         GetPassword(users, i, bufferPassword);

//         printf("User %d:\n", i + 1);
//         printf("- Username: %s\n", bufferName);
//         printf("- Password: %s\n", bufferPassword);
//         printf("- Saldo: %d\n", GetMoney(users, i));
//     }

//     return 0;
// }
