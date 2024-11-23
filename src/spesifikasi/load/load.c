#include "../../spesifikasi/start/start.h"
#include "../../adt/mesinkata.h"
#include "../../adt/mesinkarakter.h"
#include "../../adt/mesinangka.h"
#include <stdio.h>
#include "../../spesifikasi/load/load.h"

void LOAD(char filename[]) {
    Barang barang[100];
    User users[100];
    int jumlahBarang, jumlahUsers;

    char fullPath[150];
    sprintf(fullPath, "../../data/%s", filename);    
    //printf("\nDEBUG: Mulai membaca file '%s'...\n", fullPath);
    STARTREAD(barang, &jumlahBarang, users, &jumlahUsers, fullPath);

    /*if (jumlahBarang > 0) {
        //printf("\nDEBUG: Total barang ditemukan: %d\n", jumlahBarang);
        //printf("Daftar Barang:\n");
        for (int i = 0; i < jumlahBarang; i++) {
            printf("- %s, Harga: %d\n", barang[i].name, barang[i].price);
        }
    } else {
        printf("\nDEBUG: Tidak ada barang yang ditemukan.\n");
    }

    if (jumlahUsers > 0) {
        printf("\nDEBUG: Total pengguna ditemukan: %d\n", jumlahUsers);
        printf("Daftar Pengguna:\n");
        for (int i = 0; i < jumlahUsers; i++) {
            printf("- Nama: %s, Password: %s, Uang: %d\n", users[i].name, users[i].password, users[i].money);
        }
    } else {
        printf("\nDEBUG: Tidak ada pengguna yang ditemukan.\n");
    }*/
}

int main() {

    LOAD("test.txt");
    /*char filename[100]; // Buffer untuk menyimpan nama file
    int i;

    printf(">> ");
    STARTWORD();
    printf("DEBUG: Perintah pertama dibaca: %.*s\n", CurrentWord.Length, CurrentWord.TabWord);
    ADVONEWORD();

    // Membaca nama file (kata berikutnya)
    i = 0;
    while (currentChar != BLANK && currentChar != MARK) {
        filename[i++] = currentChar;
        ADV(); // Pindahkan ke karakter berikutnya
    }
    filename[i] = '\0'; // Null-terminate string

    // Debug nama file
    printf("DEBUG: Nama file yang dibaca: %s\n", filename);

    // Contoh penggunaan dengan filename
    printf("Loading file: %s\n", filename);

    return 0;*/
}
