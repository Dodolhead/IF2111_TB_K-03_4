int main() {
    List U;
    MakeList(&U);
    LinkedList wishlist;
    CreateLinkedListEmpty(&wishlist);

    wishlistAdd(&U.A[0]);
    PrintWishlist(&U,0);
}