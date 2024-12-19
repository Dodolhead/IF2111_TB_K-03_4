#include <stdio.h>
#include "../../adt/mesinkata/mesinkata.h"

#include <stdio.h>
#include "mesinangka.h"

int main() {
    char filename[] = "../../data/config.txt";

    // Mulai membaca angka
    STARTANGKA(filename);

    // Periksa apakah file kosong atau tidak
    if (IsEOPAngka()) {
        printf("File kosong atau tidak ada angka yang valid.\n");
        return 0;
    }

    // Loop untuk membaca semua angka dalam file
    printf("Angka yang ditemukan dalam file:\n");
    while (!IsEOPAngka()) {
        printf("%d ", GetAngka());
        ADVANGKA();
    }
    printf("\n");

    return 0;
}
