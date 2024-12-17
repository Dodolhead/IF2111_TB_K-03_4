#include <stdio.h>
#include "mesinkata.h"

int main(){
    char filename = "test.txt";
    STARTWORD(filename);
    while (!IsEOP())
    {
        printf("%c", GetCC());
        ADV();
    }
    
}