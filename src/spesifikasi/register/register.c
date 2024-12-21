#include "register.h"
#include <stdio.h>

void REGISTER(User users) {
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
        if (copyString(users.name, username)) {
            printf("Username %s sudah terdaftar. Silakan gunakan username lain.\n", username);
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
}
