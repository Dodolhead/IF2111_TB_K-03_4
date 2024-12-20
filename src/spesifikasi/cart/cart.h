#ifndef CART_H
#define CART_H

#include <stdio.h>
#include "../adt/barang/barang.h"
#include "../adt/arraydinBarang/arraydinBarang.h"
#include "../adt/map/map.h"
#include "../../../utilities.h"

// ADT Cart
typedef struct
{
    Map Cart;
} Cart;

// Fungsi untuk membuat Cart baru
Cart MakeCart();

// Fungsi untuk menghapus Cart
void DeallocateCart(Cart *cart);

// Fungsi untuk menambahkan barang ke dalam Cart
void AddToCart(Cart *cart, char* name, int n);

// Fungsi untuk mengurangi barang dari Cart
void RemoveFromCart(Cart *cart, char* name, int n);

// Fungsi untuk menampilkan semua barang dalam Cart
void DisplayCart(Cart cart);

#endif
