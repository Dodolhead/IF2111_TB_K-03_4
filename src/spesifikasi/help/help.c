#include <stdio.h>
#include "help.h"
#include "..\..\..\dictionary.c"
#include "..\..\adt\mesinangka.c"
#include "..\..\adt\mesinkarakter.c"

int bacaAngka(){
    int total=0;
    while (!IsEOPAngka()) {
        total = total * 10 + currentAngka;
    ADVANGKA();
    }
    return total;
}

int welcomeMenu() {
    printf(">>>HELP\n");
    printf("=====[ Welcome Menu Help PURRMART]=====\n");
    printf("1. START -> Untuk masuk sesi baru\n2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n3. QUIT -> Untuk keluar dari program\n");
    STARTANGKA();
    int inputUser;
    inputUser = bacaAngka();
    while (inputUser > 3 || inputUser < 1) {
        printf("Masukkan tidak sesuai, tolong masukkan input yang valid\n");
        inputUser = bacaAngka();
        if (inputUser <= 3 && inputUser >= 1) {
            return inputUser;
        }
    }
}

int loginMenu() {
    printf(">>>HELP\n");
    printf("=====[ Login Menu Help PURRMART]=====\n");
    printf("1. REGISTER -> Untuk melakukan pendaftaran akun baru\n2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n3. QUIT -> Untuk keluar dari program\n");
    STARTANGKA();
    int inputUser;
    inputUser = bacaAngka();
    while (inputUser > 3 || inputUser < 1) {
        printf("Masukkan tidak sesuai, tolong masukkan input yang valid\n");
        inputUser = bacaAngka();
        if (inputUser <= 3 && inputUser >= 1) {
            return inputUser;
        }
    }
}

int mainMenu() {
    printf(">>>HELP\n");
    printf("=====[ Menu Help PURRMART]=====\n");
    printf("1. WORK -> Untuk bekerja\n2. WORK CHALLENGE -> Untuk mengerjakan challenge\n3. STORE LIST -> Untuk melihat barang-barang di toko\n");
    printf("4. STORE REQUEST -> Untuk meminta penambahan barang\n5. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n6. STORE REMOVE -> Untuk menghapus barang\n");
    printf("7. LOGOUT -> Untuk keluar dari sesi\n8. SAVE -> Untuk menyimpan state ke dalam file\n9. QUIT -> Untuk keluar dari program\n");
    STARTANGKA();
    int inputUser;
    inputUser = bacaAngka();
    while (inputUser > 9 || inputUser < 1) {
        printf("Masukkan tidak sesuai, tolong masukkan input yang valid\n");
        inputUser = bacaAngka();
        if (inputUser <= 9 && inputUser >= 1) {
            return inputUser;
        }
    }
}

int main(){
    mainMenu();
}