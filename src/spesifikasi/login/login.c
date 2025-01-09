#include "login.h"
#include <stdio.h>

// Fungsi untuk login
int LOGIN(List users, int *loggedInUserIndex) {
    if (*loggedInUserIndex != -1) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", users.A[*loggedInUserIndex].name);
        return *loggedInUserIndex; // Tetap login dengan user yang sebelumnya
    }

    // Input username
    printf("Username: ");
    STARTWORD();
    for(int i = 0; i < MaxEl; i++) {
        printf("user %s\n", users.A[i].name);
        printf("www %s\n", currentWord.TabWord);
        if (stringEquals(currentWord.TabWord, users.A[i].name)) {
            printf("%s", users.A[i].name);
            ClearBuffer();
            printf("Password: ");
            STARTWORD();
            if (stringEquals(currentWord.TabWord, users.A[i].password)) {
                printf("Anda telah login ke PURRMART sebagai %s.\n", users.A[i].name);
                return i;   
                ClearBuffer();
            }
            else{
                printf("Username atau password salah. Silakan coba lagi.\n");
                break;
            }
        }
        else{
            printf("Username atau password salah. Silakan coba lagi.\n");
            printf("%s", users.A[i].name);
            break;
        }
    }
    
    // Jika tidak ditemukan
    return -1;
}

// int main(){

// }