#include "cart_show.h"
#include <stdio.h>

void CartShow(Cart cart) {
    if (IsArrDinEmpty(cart.Cart)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi keranjangmu.\n");
    printf("Kuantitas  Nama    Total\n");
    
    int totalBiaya = 0;
    
    // Iterate through items in cart and display them
    for (int i = 0; i < ArrLength(cart.Cart); i++) {
        Barang currentBarang = GetArrDin(cart.Cart, i);
        int itemTotal = currentBarang.jumlahBarang * currentBarang.price;
        totalBiaya += itemTotal;
        
        // Print item details with proper formatting
        printf("%-10d %-7s %d\n", 
            currentBarang.jumlahBarang, 
            currentBarang.name, 
            itemTotal);
    }
    
    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalBiaya);
}