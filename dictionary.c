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