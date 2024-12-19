#include "cart_show.h"
#include <stdio.h>

void CartShow(Map cart, ArrayDin Info) {
    int total = 0;

    if (IsMapEmpty(cart)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi keranjangmu.\n");
    printf("Kuantitas  Nama    Total\n");
    
    for (int i = 0; i < cart.Count; i++) {
        // Mencetak jumlah barang yang ada di keranjang
        printf("%d ", cart.Elements[i].Value);

        // Mencetak nama barang
        for (int j = 0; cart.Elements[i].keytype[j] != '\0'; j++) {
            printf("%c", cart.Elements[i].keytype[j]);
        }

        // Menghitung subtotal harga barang
        int k = 0;
        while (k < ArrLength(Info)) {
            if (stringEquals(cart.Elements[i].keytype, Info.A[k].name)) {
                break;
            } else {
                k++;
            }
        }

        // Mencetak subtotal harga barang
        printf(" %d", cart.Elements[i].Value * Info.A[k].price);
        total = total + cart.Elements[i].Value * Info.A[k].price;
    }
    
    printf("Total biaya yang harus dikeluarkan adalah %d.\n", total);
}