#include "login.h"

// Fungsi untuk login
int LOGIN(List users, int *loggedInUserIndex) {
    if (*loggedInUserIndex != -1) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", users.A[*loggedInUserIndex].name);
        return *loggedInUserIndex; // Tetap login dengan user yang sebelumnya
    }

    // Input username
    printf("Username: ");
    STARTWORD();
    char username[NMax];
    for (int i = 0; i < currentWord.Length; i++) {
        username[i] = currentWord.TabWord[i];
    }
    username[currentWord.Length] = '\0';

    // Input password
    printf("Password: ");
    STARTWORD();
    char password[NMax];
    for (int i = 0; i < currentWord.Length; i++) {
        password[i] = currentWord.TabWord[i];
    }
    password[currentWord.Length] = '\0';

    // Proses pengecekan login
    for (int i = 0; i < MaxEl; i++) {
        if (stringEquals(users.A[i].name, username) && stringEquals(users.A[i].password, password)) {
            *loggedInUserIndex = i; // Tandai sebagai login
            printf("Anda telah login ke PURRMART sebagai %s.\n", users.A[i].name);
            return i;
        }
    }

    // Jika tidak ditemukan
    printf("Username atau password salah.\n");
    return -1;
}
