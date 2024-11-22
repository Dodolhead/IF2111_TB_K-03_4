#include "start.h"
#include "../../adt/mesinkata.h" 
#include "../../adt/mesinkarakter.h"
#include "../../adt/mesinangka.h"
#include <stdio.h>

void STARTREAD(Barang barang[], int *jumlahBarang, User users[], int *jumlahUsers) {
    STARTANGKA();
    printf("DEBUG: Jumlah Barang = %d\n", currentAngka); // Tambahkan ini
    *jumlahBarang = currentAngka;

    for (int i = 0; i < *jumlahBarang; i++) {
        STARTANGKA();
        printf("DEBUG: Harga Barang ke-%d = %d\n", i + 1, currentAngka); // Tambahkan ini
        barang[i].price = currentAngka;

        STARTWORD();
        printf("DEBUG: Nama Barang ke-%d = %.*s\n", i + 1, CurrentWord.Length, CurrentWord.TabWord); // Tambahkan ini
        for (int k = 0; k < CurrentWord.Length; k++) {
            barang[i].name[k] = CurrentWord.TabWord[k];
        }
        barang[i].name[CurrentWord.Length] = '\0';
    }

    STARTANGKA();
    printf("DEBUG: Jumlah Pengguna = %d\n", currentAngka); // Tambahkan ini
    *jumlahUsers = currentAngka;

    for (int i = 0; i < *jumlahUsers; i++) {
        STARTANGKA();
        printf("DEBUG: Uang Pengguna ke-%d = %d\n", i + 1, currentAngka); // Tambahkan ini
        users[i].money = currentAngka;

        STARTWORD();
        printf("DEBUG: Nama Pengguna ke-%d = %.*s\n", i + 1, CurrentWord.Length, CurrentWord.TabWord); // Tambahkan ini
        for (int k = 0; k < CurrentWord.Length; k++) {
            users[i].name[k] = CurrentWord.TabWord[k];
        }
        users[i].name[CurrentWord.Length] = '\0';

        STARTWORD();
        printf("DEBUG: Password Pengguna ke-%d = %.*s\n", i + 1, CurrentWord.Length, CurrentWord.TabWord); // Tambahkan ini
        for (int k = 0; k < CurrentWord.Length; k++) {
            users[i].password[k] = CurrentWord.TabWord[k];
        }
        users[i].password[CurrentWord.Length] = '\0';
    }
}


int main() {
    Barang barang[100];
    User users[100];
    int jumlahBarang, jumlahUsers;

    STARTREAD(barang, &jumlahBarang, users, &jumlahUsers);

    printf("Daftar Barang:\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("- %s: %d\n", barang[i].name, barang[i].price);
    }

    printf("Daftar Pengguna:\n");
    for (int i = 0; i < jumlahUsers; i++) {
        printf("- Nama: %s, Password: %s, Uang: %d\n", users[i].name, users[i].password, users[i].money);
    }

    return 0;
}
