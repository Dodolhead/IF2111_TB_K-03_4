//#include <stdio.h>
#include "store_list.h"

void StoreList() {
    int i, j, barang = 0, baris = 1;
    STARTWORD();

    // Mengecek jumlah barang dalam toko
    for (i = 0; i < CurrentWord.Length; i++) {
        barang = barang * 10 + ((CurrentWord.TabWord[i]) - '0');
    }

    // Mencetak barang dalam toko
    if (barang == 0) {
        printf("TOKO KOSONG");
    } else {
        printf("List barang yang ada di toko :\n");
        
        while (baris <= barang) {
            ADVWORD();
            ADVWORD();

            printf("- ");
            for (j = 0; j < CurrentWord.Length; j++) {
                printf("%c", CurrentWord.TabWord[j]);
            }

            // Mencetak barang yang memiliki lebih dari satu kata
            while (!EndWord && GetCC() != '\n') {
                ADVWORD();

                printf(" ");

                for (j = 0; j < CurrentWord.Length; j++) {
                    printf("%c", CurrentWord.TabWord[j]);
                }
            }
            printf("\n");
            baris++;
        }
    }
}
