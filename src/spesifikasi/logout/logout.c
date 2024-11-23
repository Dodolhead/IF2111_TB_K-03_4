#include "logout.h"
#include <stdio.h>

void LOGOUT(int *loggedInUserIndex) {
    if (*loggedInUserIndex == -1) {
        printf("Tidak ada pengguna yang sedang login.\n");
    } else {
        printf("Berhasil logout. Anda tidak lagi login di PURRMART.\n");
        *loggedInUserIndex = -1; // Set loggedInUserIndex ke -1 untuk menandakan tidak ada pengguna login
    }
}
