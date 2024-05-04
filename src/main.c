#include "../inc/lfdr/fields.h"
#include "../inc/lfdr/jval.h"
#include "../inc/lfdr/dllist.h"
#include "../inc/utils/fileOperations/readFile.h"
#include "../inc/utils/dataTypes/Stack.h"
#include "../inc/utils/dataTypes/Queue.h"
#include "../inc/utils/dataTypes/Boolean.h"
#include "../inc/utils/dataTypes/String.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/parser/parser.h"
#include "../inc/parser/operatorsEnum.h"
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

    printf("is number %d\n", isNumber("2000a0").value);

    FILE *f = fopen("./data/output.dat", "wb");
    char *text = "Hello,\nWorld!";
    fwrite(text, sizeof(char), strlen(text), f);

    fclose(f);

    String *st = newString("");
    char *str = "bu bir string ifade:";
    appendCharacterArray(st, str);
    char *str2 = "bu da ikinci\nstring ifade";
    appendCharacterArray(st, str2);
    st->overrideFromLocation(st, 3, "zu");
    st->appendChar(st, "\ntest satiri.");

    printf("%s\n", st->str);
    return 0;
}