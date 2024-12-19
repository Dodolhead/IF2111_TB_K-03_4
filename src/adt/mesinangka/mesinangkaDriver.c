#include <stdio.h>
#include "../../adt/mesinkata/mesinkata.h"

int main(){
    char filename[] = "config.txt"; // Use double quotes for string literals
    START(filename);
    while (!IsEOP())
    {
        printf("%c", GetCC());
        ADV();
    }
    
    return 0;
}