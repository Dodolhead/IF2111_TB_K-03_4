#include <stdio.h>
#include "mesinkata.h"
#include "../../../utilities.c"
<<<<<<< HEAD
#include "mesinkarakter.c"
#include "mesinkata.c"
#include "mesinangka.c"
=======
#include "../mesinkarakter/mesinkarakter.c"
#include "../mesinkata/mesinkata.c"
#include "../mesinangka/mesinangka.c"
>>>>>>> b586eafebee56248fef35858176a7576d43b3a14

int main(){
    char filename[] = "config.txt";
    STARTWORD(filename);
    while (!endWord)
    {
        ADVWORD();
    }
    printf("%s\n", currentWord.TabWord);
    
}