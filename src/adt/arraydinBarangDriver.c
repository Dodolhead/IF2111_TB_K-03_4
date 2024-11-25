#include "arraydinBarang.h"
#include <stdio.h>

int main() {
    ArrayDin Test = MakeArrayDin();
    
    if (IsEmpty(Test)) {
        printf("Array kosong\n");
    }

    ArrInsertLast(&Test, "Barang1", 5000);
    printf("Barang ditambahkan: %s - %d\n", Test.A[0].name, Test.A[0].price);

    printf("Daftar Barang:\n");
    for (int i = 0; i < ArrLength(Test); i++) {
        printf("%d. %s - %d\n", i + 1, Test.A[i].name, Test.A[i].price);
    }

    DeallocateArrayDin(&Test);

    return 0;
}

//gcc driverarraydinBarang.c arraydinBarang.c mesinkata.c mesinkarakter.c barang.c ../../utilities.c ../../adt/mesinangka.c -o arraydinBarangDriver.c
//./arraydinBarangDriver
