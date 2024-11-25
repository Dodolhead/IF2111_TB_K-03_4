#include "listuser.h"
#include <stdio.h>

int main() {
    List U = MakeList();
    InsertFirst(&U, 100000, "admin", "admin");
    InsertAt(&U, 100000, "dapid", "idiot",1);
    InsertLast(&U, 50000, "user", "user");
    InsertLast(&U, 50000, "asu", "user");

    printf("Length before DeleteAt: %d\n", Length(U));
    DeleteAt(&U, 2);
    printf("Length after DeleteAt: %d\n", Length(U));


    char buffer[50];
    for (int i = 0; i < Length(U); i++) {
        printf("%d\n", GetMoney(U, i));
        GetName(U, i, buffer);
        printf("%s\n", buffer);
        GetPassword(U, i, buffer);
        printf("%s\n", buffer);
    }
}