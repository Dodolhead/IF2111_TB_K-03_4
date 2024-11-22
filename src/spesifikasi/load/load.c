#include "../../spesifikasi/start/start.h"
#include "../../adt/mesinkata.h" 
#include "../../adt/mesinkarakter.h"
#include "../../adt/mesinangka.h"
#include <stdio.h>

void LOAD(Barang barang[], int *jumlahBarang, User users[], int *jumlahUsers) {;
    ADVUSER();
    char filename[CurrentWord.Length + 1];
    for (int i = 0; i < CurrentWord.Length; i++) {
        filename[i] = CurrentWord.TabWord[i];
    }
    filename[CurrentWord.Length] = '\0';

    if (!EOP) {
        STARTREAD(barang, jumlahBarang, users, jumlahUsers, filename);
    } printf("Save berhasil, %s\n", filename);
}

int main() {
    Barang barang[100];
    User users[100];
    int jumlahBarang = 0, jumlahUsers = 0;
    
    printf(">> ");
    STARTWORD();
    LOAD(barang, &jumlahBarang, users, &jumlahUsers);

    if (jumlahBarang > 0) {
        printf("\nDaftar Barang:\n");
        for (int i = 0; i < jumlahBarang; i++) {
            printf("- %s, Harga : %d\n", barang[i].name, barang[i].price);
        }
    } else {
        printf("\nTidak ada barang yang ditemukan.\n");
    }

    if (jumlahUsers > 0) {
        printf("\nDaftar Pengguna:\n");
        for (int i = 0; i < jumlahUsers; i++) {
            printf("- Nama: %s, Password: %s, Uang: %d\n", users[i].name, users[i].password, users[i].money);
        }
    } else {
        printf("\nTidak ada pengguna yang ditemukan.\n");
    }

    return 0;
}
