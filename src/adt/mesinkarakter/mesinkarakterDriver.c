#include <stdio.h>
#include "mesinkarakter.h"

int main() {
    char filename[100];

    // Input nama file
    printf("Masukkan nama file: ");
    scanf("%s", filename);

    // Mulai membaca file
    START(filename);

    // Cetak isi file
    printf("Isi file:\n");
    while (1) { // Loop hingga akhir file
        printf("%c", GetCC());
        ADV();
    }


    printf("\nSelesai membaca file.\n");

    return 0;
}
