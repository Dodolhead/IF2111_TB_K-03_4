#include "register.h"
#include <stdio.h>
#include "../../adt/mesinkata.h"
#include "../../adt/mesinkarakter.h"

void REGISTER(User users) {
    printf(">> REGISTER\n");

    // Input username
    printf("Masukkan username: ");
    STARTWORD();
    char username[100];
    for (int i = 0; i < CurrentWord.Length; i++) {
        username[i] = CurrentWord.TabWord[i];
    }
    username[CurrentWord.Length] = '\0';

    // Periksa apakah username sudah ada
    for (int i = 0; i < *jumlahUsers; i++) {
        if (stringEquals(users[i].name, username)) {
            printf("Username %s sudah terdaftar. Silakan gunakan username lain.\n", username);
            return;
        }
    }

    // Input password
    printf("Masukkan password: ");
    STARTWORD();
    char password[100];
    for (int i = 0; i < CurrentWord.Length; i++) {
        password[i] = CurrentWord.TabWord[i];
    }
    password[CurrentWord.Length] = '\0';

    // Tambahkan pengguna baru
    stringCopy(users[*jumlahUsers].name, username);
    stringCopy(users[*jumlahUsers].password, password);
    users[*jumlahUsers].money = 0; // Default uang adalah 0
    (*jumlahUsers)++;

    printf("Pendaftaran berhasil. Selamat datang, %s!\n", username);
}
