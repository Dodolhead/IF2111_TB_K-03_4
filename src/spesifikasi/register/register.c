#include "register.h"
#include <stdio.h>

void REGISTER(List *users) {
    printf(">> REGISTER\n");

    // Input username
    printf("Masukkan username: ");
    STARTWORD();
    char username[100];
    for (int i = 0; i < currentWord.Length; i++) {
        username[i] = currentWord.TabWord[i];
    }
    username[currentWord.Length] = '\0';

    // Periksa apakah username sudah ada
    for (int i = 0; i < MaxEl; i++) {
        if (stringEquals(users->A[i].name, username)) {
            printf("Username %s sudah terdaftar. Silakan gunakan username lain.\n", username);
            return;
        }
    }

    // Input password
    printf("Masukkan password: ");
    STARTWORD();
    char password[100];
    for (int i = 0; i < currentWord.Length; i++) {
        password[i] = currentWord.TabWord[i];
    }
    password[currentWord.Length] = '\0';

    printf("Pendaftaran berhasil. Selamat datang, %s!\n", username);
    ClearBuffer();
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
//     for (int i = 0; i < ListUserLength(&users); i++) {
//         char bufferName[MAX_LEN];
//         char bufferPassword[MAX_LEN];
//         GetName(&users, i, bufferName);
//         GetPassword(&users, i, bufferPassword);

//         printf("User %d:\n", i + 1);
//         printf("- Username: %s\n", bufferName);
//         printf("- Password: %s\n", bufferPassword);
//         printf("- Saldo: %d\n", GetMoney(&users, i));
//     }

//     return 0;
// }
