#include "start.h"
#include "../../adt/mesinkata.h" 
#include "../../adt/mesinkarakter.h"
#include "../../adt/mesinangka.h"
#include <stdio.h>

void STARTREAD(Barang barang[], int *jumlahBarang, User users[], int *jumlahUsers, char filename[]) {
    STARTFILE(filename);

    // Membaca jumlah barang
    STARTANGKA();
    *jumlahBarang = currentAngka;
    printf("DEBUG: Jumlah Barang = %d\n", *jumlahBarang);
    ADV(); // Pindah ke elemen berikutnya

    // Membaca data barang
    for (int i = 0; i < *jumlahBarang; i++) {
        STARTANGKA();
        barang[i].price = currentAngka;
        ADVWORD();
        for (int k = 0; k < CurrentWord.Length; k++) {
            barang[i].name[k] = CurrentWord.TabWord[k];
        }
        barang[i].name[CurrentWord.Length] = '\0';
        printf("DEBUG: Barang ke-%d: Nama = %s, Harga = %d\n", i + 1, barang[i].name, barang[i].price);

        ADV(); // Pindah ke elemen berikutnya
    }

    STARTANGKA();
    *jumlahUsers = currentAngka;
    printf("DEBUG: Jumlah Pengguna = %d\n", *jumlahUsers);
    ADV(); // Pindah ke elemen berikutnya

    // Membaca data pengguna
    for (int i = 0; i < *jumlahUsers; i++) {
        STARTANGKA();
        users[i].money = currentAngka;
        ADVUSER();

        for (int k = 0; k < CurrentWord.Length; k++) {
            users[i].name[k] = CurrentWord.TabWord[k];
        }
        users[i].name[CurrentWord.Length] = '\0';
        ADVUSER();

        for (int k = 0; k < CurrentWord.Length; k++) {
            users[i].password[k] = CurrentWord.TabWord[k];
        }
        users[i].password[CurrentWord.Length] = '\0';
        printf("DEBUG: Pengguna ke-%d: Nama = %s, Password = %s, Uang = %d\n", i + 1, users[i].name, users[i].password, users[i].money);

        ADV();
    }
}

int main() {
    Barang barang[100];
    User users[100];
    int jumlahBarang, jumlahUsers;

    STARTREAD(barang, &jumlahBarang, users, &jumlahUsers, "test.txt");

    printf("\nDaftar Barang:\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("- %s: %d\n", barang[i].name, barang[i].price);
    }

    printf("\nDaftar Pengguna:\n");
    for (int i = 0; i < jumlahUsers; i++) {
        printf("- Nama: %s, Password: %s, Uang: %d\n", users[i].name, users[i].password, users[i].money);
    }

    return 0;
}
