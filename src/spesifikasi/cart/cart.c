#include "cart.h"
#include <stdio.h>

void MakeCart(Map *cart) {
    CreateMapEmpty(cart);
}

// Menambahkan barang ke dalam Cart (CARD ADD)
void AddToCart(Map *cart, keytype name, int n) {
    if (IsMember(cart, name)) {
        // Jika barang sudah ada di cart, tambahkan jumlahnya
        for (int i = 0; i <= cart->Count; i++) {
            if (cart->Elements[i].Key == name) {
                cart->Elements[i].Value += n;
            }
        }
    } else {
        // Jika barang belum ada, tambahkan sebagai item baru
        Insert(cart, name, n);
    }
}

// Mengurangi barang dari Cart (CARD REMOVE)
void RemoveFromCart(Map *cart, char* name, int n) {
    if (IsMember(cart, name)) {
        for (int i = 0; i <= cart->Count; i++) {
            if (stringEquals(cart->Elements[i].Key, name) == 0) {  // Periksa nama barang
                if (cart->Elements[i].Value > n) {
                    cart->Elements[i].Value -= n;  // Kurangi jumlah barang
                    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", n, name);
                } else if (cart->Elements[i].Value == n) {
                    Delete(cart, name);  // Hapus barang jika jumlahnya habis
                    printf("%s habis dari keranjang belanja dan telah dihapus!\n", name);
                } else {
                    printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", cart->Elements[i].Value, name);
                }
            }
        }
    } else {
        printf("Barang dengan nama %s tidak ada di dalam cart.\n", name);
    }
}


// Menampilkan semua barang dalam Cart
void DisplayCart(Map cart) {
    if (IsMapEmpty(&cart)) {
        printf("Cart kosong.\n");
    } else {
        printf("Isi Cart:\n");
        for (int i = 0; i <= cart.Count; i++) {
            printf("- %s: %d\n", cart.Elements[i].Key, cart.Elements[i].Value);
        }
    }
}
// ini untuk ngetes (driver)
// int main() {
//     Map cart;
//     MakeCart(&cart);

//     AddToCart(&cart, "Baju", 2);
//     DisplayCart(cart);
// }