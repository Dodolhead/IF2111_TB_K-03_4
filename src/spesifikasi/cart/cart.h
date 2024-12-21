#ifndef CART_H
#define CART_H

#include <stdio.h>
#include "../../adt/map/map.h"
#include "../../../utilities.h"

// ADT Cart
// Fungsi untuk membuat Cart baru
void MakeCart(Map *cart);

// Fungsi untuk menambahkan barang ke dalam Cart
void AddToCart(Map *cart, keytype name, int n);

// Fungsi untuk mengurangi barang dari Cart
void RemoveFromCart(Map *cart, char* name, int n);

// Fungsi untuk menampilkan semua barang dalam Cart
void DisplayCart(Map cart);

#endif
