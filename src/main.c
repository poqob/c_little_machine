#include "../inc/lfdr/fields.h"
#include "../inc/lfdr/jval.h"
#include "../inc/lfdr/dllist.h"
#include "../inc/utils/fileOperations/readFile.h"
#include "../inc/utils/dataTypes/Stack.h"
#include "../inc/utils/dataTypes/Boolean.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    _ReadFile *rf = newReadFile("./data/input.dat");
    freeReadFile(rf);

    Stack s;
    initializeStack(&s);
    push(&s, "yaz:");
    push(&s, "2");
    push(&s, "r");

    printf("%s\n", (char *)peek(&s));
    pop(&s);
    printf("%s\n", (char *)peek(&s));
    pop(&s);
    printf("%s\n", (char *)peek(&s));
    pop(&s);
    printf("%d\n", isEmpty(&s));

    boolean a = true;
    boolean b = false;
    printf("NOT %d\n", or (a, b).value);

    return 0;
}