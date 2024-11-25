#include "queue.h"
#include <stdio.h>
#include "queue.c"
#include "../../utilities.c"
#include "mesinkarakter.c"
#include "mesinkata.c"
#include "mesinangka.c"

int main(){
    char val[20];
    Queue q;
    CreateQueue(&q);
    enqueue(&q, "A");
    enqueue(&q, "B");
    enqueue(&q, "C");
    enqueue(&q, "D");
    enqueue(&q, "E");
    displayQueue(q);
    dequeue(&q, val);
    displayQueue(q);
    printf("%s",val);

}