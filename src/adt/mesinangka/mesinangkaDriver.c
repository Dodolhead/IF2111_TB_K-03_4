#include <stdio.h>
#include "../../adt/mesinkata/mesinkata.h"

int main(){
    char filename = 'test.txt';
    START(filename);
    while (!IsEOP())
    {
        printf("%c", GetCC());
        ADV();
    }
    
}