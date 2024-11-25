#include <stdio.h>
#include "mesinkata.h"

int main(){
    START();
    while (!IsEOP())
    {
        printf("%c", GetCC());
        ADV();
    }
    
}