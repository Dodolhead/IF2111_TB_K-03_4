#include <stdio.h>
#include "..\..\..\dictionary.h"
#include "..\..\..\dictionary.c" 
#include "..\..\adt\mesinkata.c"  // Pastikan ini juga benar
#include "..\..\adt\mesinkarakter.c"  // Pastikan ini juga benar

void workDisplay() {
    printf("Daftar Pekerjaan:\n");
    printf("    1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("    2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("    3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("    4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("    5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
}

void doWork() {
    char buffer[200] = "";  // Buffer untuk menampung input
    workDisplay();  // Menampilkan daftar pekerjaan

    // Memulai pembacaan input
    printf(">> ");
    STARTWORD();  
    while (!IsEOP()) {  // Selama tidak mencapai end of input (EOP)
        stringConcat(buffer, CurrentWord.TabWord);  // Gabungkan kata ke buffer
        stringConcat(buffer, " ");  // Menambahkan spasi antar kata
        printf("\nInput yang diterima: %s\n", buffer);
        ADVWORD();  // Lanjutkan ke kata berikutnya
    }

    printf("\nInput yang diterima: %s\n", buffer);
}

int main() {
    doWork();  // Menjalankan fungsi doWork
}
