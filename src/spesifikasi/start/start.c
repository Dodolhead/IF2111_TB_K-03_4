#include "start.h"
#include "..\..\adt\mesinkata.c" 
#include "..\..\adt\mesinkarakter.c"
#include <stdio.h>

void STARTREAD(Barang barang[], int *jumlahBarang, User users[], int *jumlahUsers) {
    *jumlahBarang = 0;
    *jumlahUsers = 0;

    // Membaca jumlah barang
    STARTWORD();
    for (int i = 0; i < CurrentWord.Length; i++) {
        *jumlahBarang = *jumlahBarang * 10 + (CurrentWord.TabWord[i] - '0');
    }
    ADVWORD();

    // Membaca data barang
    for (int i = 0; i < *jumlahBarang; i++) {
        Barang b;

        // Membaca harga barang
        b.price = 0;
        for (int j = 0; j < CurrentWord.Length; j++) {
            b.price = b.price * 10 + (CurrentWord.TabWord[j] - '0');
        }
        ADVWORD();

        // Membaca nama barang
        int k;
        for (k = 0; k < CurrentWord.Length; k++) {
            b.name[k] = CurrentWord.TabWord[k];
        }
        b.name[k] = '\0';
        ADVWORD();

        barang[i] = b;
    }

    // Membaca jumlah pengguna
    for (int i = 0; i < CurrentWord.Length; i++) {
        *jumlahUsers = *jumlahUsers * 10 + (CurrentWord.TabWord[i] - '0');
    }
    ADVWORD();

    // Membaca data pengguna
    for (int i = 0; i < *jumlahUsers; i++) {
        User u;

        // Membaca uang pengguna
        u.money = 0;
        for (int j = 0; j < CurrentWord.Length; j++) {
            u.money = u.money * 10 + (CurrentWord.TabWord[j] - '0');
        }
        ADVWORD();

        // Membaca nama pengguna
        int k;
        for (k = 0; k < CurrentWord.Length; k++) {
            u.name[k] = CurrentWord.TabWord[k];
        }
        u.name[k] = '\0';
        ADVWORD();

        // Membaca password pengguna
        for (k = 0; k < CurrentWord.Length; k++) {
            u.password[k] = CurrentWord.TabWord[k];
        }
        u.password[k] = '\0';
        ADVWORD();

        users[i] = u;
    }
}

void printBarang(Barang barang[], int jumlahBarang) {
    printf("Daftar barang:\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("- %s: %d\n", barang[i].name, barang[i].price);
    }
}

void printUsers(User users[], int jumlahUsers) {
    printf("Daftar pengguna:\n");
    for (int i = 0; i < jumlahUsers; i++) {
        printf("- Nama: %s, Password: %s, Uang: %d\n", users[i].name, users[i].password, users[i].money);
    }
}

void STARTFILE(char *filename) {
    Barang barang[MAX_ITEMS];
    User users[MAX_USERS];
    int jumlahBarang = 0, jumlahUsers = 0;

    freopen(filename, "r", stdin);  // Mengarahkan stdin ke file

    printf("Memulai sistem PURRMART...\n");
    STARTREAD(barang, &jumlahBarang, users, &jumlahUsers);

    if (jumlahBarang > 0 || jumlahUsers > 0) {
        printf("File konfigurasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
        printBarang(barang, jumlahBarang);
        printUsers(users, jumlahUsers);
    } else {
        printf("Gagal menjalankan PURRMART. Tidak ada data yang tersedia.\n");
    }
}

int main() {
    char filename[] = "test.txt";
    STARTFILE(filename);
    return 0;
}
