#include "cart.h"
#include <stdio.h>
#include "../../adt/map/map.c"


void MakeCart(Map *cart) {
    CreateMapEmpty(cart);
}

// Menambahkan barang ke dalam Cart (CARD ADD)
void AddToCart(Map *cart, keytype name, int n) {
    if (IsMember(*cart, name)) {
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
void RemoveFromCart(Map *cart, char* name) {
    if (IsMember(*cart, name)) {
        // Hapus barang berdasarkan nama
        Delete(cart, name);
    } else {
        printf("Barang dengan nama %s tidak ada di dalam cart.\n", name);
    }
}

// Menampilkan semua barang dalam Cart
void DisplayCart(Map cart) {
    if (IsMapEmpty(cart)) {
        printf("Cart kosong.\n");
    } else {
        printf("Isi Cart:\n");
        for (int i = 0; i <= cart.Count; i++) {
            printf("- %s: %d\n", cart.Elements[i].Key, cart.Elements[i].Value);
        }
    }
}
// ini untuk ngetes (driver)
int main() {
    Map cart;
    MakeCart(&cart);

    AddToCart(&cart, "Baju", 2);
    DisplayCart(cart);
}