#include "login.h"

// Fungsi untuk membandingkan dua string
boolean stringEquals(char *str1, char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0; // False jika ada karakter yang tidak cocok
        }
        i++;
    }

    return str1[i] == '\0' && str2[i] == '\0'; // True jika keduanya selesai bersamaan
}

// Fungsi untuk login
int LOGIN(User users[], int jumlahUsers, int *loggedInUserIndex) {
    if (*loggedInUserIndex != -1) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", users[*loggedInUserIndex].name);
        return *loggedInUserIndex; // Tetap login dengan user yang sebelumnya
    }

    // Input username
    printf("Username: ");
    STARTWORD();
    char username[NMax];
    for (int i = 0; i < CurrentWord.Length; i++) {
        username[i] = CurrentWord.TabWord[i];
    }
    username[CurrentWord.Length] = '\0';

    // Input password
    printf("Password: ");
    STARTWORD();
    char password[NMax];
    for (int i = 0; i < CurrentWord.Length; i++) {
        password[i] = CurrentWord.TabWord[i];
    }
    password[CurrentWord.Length] = '\0';

    // Proses pengecekan login
    for (int i = 0; i < jumlahUsers; i++) {
        if (stringEquals(users[i].name, username) && stringEquals(users[i].password, password)) {
            *loggedInUserIndex = i; // Tandai sebagai login
            printf("Anda telah login ke PURRMART sebagai %s.\n", users[i].name);
            return i;
        }
    }

    // Jika tidak ditemukan
    printf("Username atau password salah.\n");
    return -1;
}
