int main() {
    List U;
    MakeList(&U);
    LinkedList wishlist;
    CreateLinkedListEmpty(&wishlist);
    wishlistAdd(&U.A[0]);
    wishlistAdd(&U.A[0]);
    wishlistSwap(&U.A[0],1,2);
    PrintWishlist(&U,0);
}