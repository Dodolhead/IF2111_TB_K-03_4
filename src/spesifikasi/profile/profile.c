#include <stdio.h>
#include "profile.h"

void displayProfile(User user) {

    printf("\n=== PROFILE ===\n");
    printf("Nama : %s\n", users.name);
    printf("Saldo: %d\n", users.money);
}