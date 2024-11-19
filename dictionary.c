#include <stdio.h>
#include "dictionary.h"

boolean stringEquals(char* str1, char* str2){
    int i = 0;

    // Bandingkan karakter satu per satu
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0; 
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

int stringLength(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringConcat(char* dest, char* src) {
    
    int destLen = stringLength(dest);  // Pastikan stringLength mengembalikan panjang yang benar
    int srcLen = stringLength(src);    // Pastikan ini juga benar

    // Gabungkan kedua string
    for (int i = 0; i < srcLen; i++) {
        dest[destLen + i] = src[i];
    }
    dest[destLen + srcLen] = '\0';  // Menambahkan null-terminator pada akhir string
}

void copyString(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
