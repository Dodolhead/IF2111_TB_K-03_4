#include <stdio.h>
#include "barang.h"

int main() {

    Barang b1, b2;
    char tempName[100];

    b1 = MakeBarang("Ayam", 150);
    printf("Barang 1: %s - Rp %d\n", NamaBarang(&b1), HargaBarang(b1));


    b2 = MakeBarang("Ipon", 800);
    printf("Barang 2: %s - Rp %d\n", NamaBarang(&b2), HargaBarang(b2));


    copyString(tempName, "Iped");
    copyString(b1.name, tempName);
    printf("Barang 1 setelah nama diubah: %s - Rp %d\n", NamaBarang(&b1), HargaBarang(b1));

    return 0;
}
//gcc barangDriver.c barang.c ../../utilities.c mesinkata.c mesinkarakter.c mesinangka.c -o barangDriver