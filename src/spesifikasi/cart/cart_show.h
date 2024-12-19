#ifndef CART_SHOW_H
#define CART_SHOW_H

#include "cart.h"

/**
 * Shows the contents of the shopping cart
 * If the cart is empty, displays "Keranjang kamu kosong!"
 * If the cart has items, displays:
 * - A list of items with their quantity, name, and total price
 * - The total cost of all items in the cart
 * 
 * @param cart The shopping cart to display
 */
void CartShow(Cart cart);

#endif /* CART_SHOW_H */