#include "cart.h"
#include <stdio.h>
#include "../../../utilities.c"
// Konstruktor Cart
Cart MakeCart() {
    Cart newCart;
    newCart.Cart = MakeArrayDin();  // Membuat array dinamis kosong untuk Cart
    return newCart;
}

// Destruktor Cart
void DeallocateCart(Cart *cart) {
    DeallocateArrayDin(&cart->Cart);  
}

// Menambahkan barang ke dalam Cart (CARD ADD)
void AddToCart(Cart *cart, char* name, int n) {
    int found = 0;
    for (int i = 0; i < ArrLength(cart->Cart); i++) {
        Barang currentBarang = Get(cart->Cart, i);
        if (stringEquals(currentBarang.name, name) == 0) {
            currentBarang.jumlahBarang += n;
            ArrInsertAt(&cart->Cart, currentBarang.name, currentBarang.price, i); // Update barang
            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", n, name);
            found = 1;
            break;
        }
    }
    if (!found) {
        // Barang tidak ditemukan, tambahkan sebagai barang baru
        printf("Barang tidak ada di toko!\n");
    }
}

// Mengurangi barang dari Cart (CARD REMOVE)
void RemoveFromCart(Cart *cart, char* name, int n) {
    int found = 0;
    for (int i = 0; i < ArrLength(cart->Cart); i++) {
        Barang currentBarang = Get(cart->Cart, i);
        if (stringEquals(currentBarang.name, name) == 0) {
            if (currentBarang.jumlahBarang >= n) {
                // Barang ada dan cukup banyak untuk dikurangi
                currentBarang.jumlahBarang -= n;
                if (currentBarang.jumlahBarang > 0) {
                    ArrInsertAt(&cart->Cart, currentBarang.name, currentBarang.price, i);
                    printf("Berhasil mengurangi %d barang dari keranjang!\n", n);
                } else if (currentBarang.jumlahBarang == 0) {
                    printf("Berhasil mengurangi %d barang dari keranjang!\n", n);
                }
            } else {
                // Kuantitas barang di keranjang lebih sedikit dari yang diminta
                printf("Tidak berhasil mengurangi, hanya terdapat %d %s di keranjang!\n", currentBarang.jumlahBarang, name);
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Barang tidak ada di keranjang belanja!\n");
    }
}

// Menampilkan semua barang dalam Cart
void DisplayCart(Cart cart) {
    printf("Daftar barang dalam keranjang:\n");
    for (int i = 0; i < ArrLength(cart.Cart); i++) {
        Barang currentBarang = Get(cart.Cart, i);
        printf("Nama: %s, Harga: %d, Kuantitas: %d\n", currentBarang.name, currentBarang.price, currentBarang.jumlahBarang);
    }
}

// ini untuk ngetes (driver)
// int main() {
//     Barang B;
//     B.price = 100000;
//     int jumlah;
//     char nama;
//     scanf("Masukkan nama barang: %c", &nama);
//     scanf("Masukkan jumlah barang yang ingin dimasukkan ke cart: %d", &jumlah);
//     Cart keranjang;
//     AddToCart(&keranjang, &nama, jumlah);
//     DisplayCart(keranjang);
// }