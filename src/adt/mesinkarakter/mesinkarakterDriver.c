#include <stdio.h>
#include "../../adt/mesinkata/mesinkata.h"

int main(){
    char filename[] = "config.txt";
    STARTWORD(filename);
    while (!IsEOP())
    {
        printf("%c", GetCC());
        ADV();
    }
    
}