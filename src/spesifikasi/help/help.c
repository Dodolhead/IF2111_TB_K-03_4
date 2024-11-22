#include <stdio.h>
#include <string.h>

void displayHelp(const char *menu) {
    if (strcmp(menu, "welcome") == 0) {
        printf("=====[ Welcome Menu Help PURRMART ]=====\n");
        printf("1. START    >> Untuk masuk sesi baru\n");
        printf("2. LOAD     >> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("3. HELP     >> Untuk menampilkan bantuan\n");
        printf("4. QUIT     >> Untuk keluar dari program\n");
    } else if (strcmp(menu, "login") == 0) {
        printf("=====[ Login Menu Help PURRMART ]=====\n");
        printf("1. REGISTER >> Untuk melakukan pendaftaran akun baru\n");
        printf("2. LOGIN    >> Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("3. HELP     >> Untuk menampilkan bantuan\n");
        printf("4. QUIT     >> Untuk keluar dari program\n");
    } else if (strcmp(menu, "main") == 0) {
        printf("=====[ Main Menu Help PURRMART ]=====\n");
        printf("1. WORK             >> Untuk bekerja\n");
        printf("2. WORK CHALLENGE   >> Untuk mengerjakan challenge\n");
        printf("3. STORE LIST       >> Untuk melihat barang-barang di toko\n");
        printf("4. STORE REQUEST    >> Untuk meminta penambahan barang\n");
        printf("5. STORE SUPPLY     >> Untuk menambahkan barang dari permintaan\n");
        printf("6. STORE REMOVE     >> Untuk menghapus barang\n");
        printf("7. LOGOUT           >> Untuk keluar dari sesi\n");
        printf("8. SAVE <filename>  >> Untuk menyimpan state ke dalam file\n");
        printf("9. HELP             >> Untuk menampilkan bantuan\n");
        printf("10. QUIT            >> Untuk keluar dari program\n");
    } else {
        printf("Menu tidak ditemukan. Silakan pilih menu yang valid: welcome, login, main\n");
    }
}
