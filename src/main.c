#include "../inc/lfdr/fields.h"
#include "../inc/lfdr/jval.h"
#include "../inc/lfdr/dllist.h"
#include "../inc/utils/fileOperations/readFile.h"
#include "../inc/utils/dataTypes/Stack.h"
#include "../inc/utils/dataTypes/Queue.h"
#include "../inc/utils/dataTypes/Boolean.h"
#include "../inc/utils/dataTypes/String.h"
#include "../inc/generator/textGenerator.h"
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
    int pos = 0;
    char *txt = "test:";
    pos += strlen(txt);
    st->appendChar(st, txt);
    st->overrideFromLocation(st, pos, "deneme");
    pos += strlen("deneme");
    st->overrideFromLocation(st, pos - 1, "okul");
    pos += strlen("okul") - 1;
    st->removeAt(st, pos - 2);

    TextGenerator *tg = initializeTextGenerator(tg);
    tg->write(tg, 3, "a");
    tg->write(tg, 3, "b");
    tg->write(tg, 1, "\n");
    tg->goLast(tg);
    tg->write(tg, 3, "z");
    tg->write(tg, 3, "a");
    tg->write(tg, 3, "b");
    tg->write(tg, 3, "c");
    tg->remove(tg, 2, "z");
    // tg->goLast(tg);
    tg->write(tg, 1, "o");
    tg->write(tg, 2, " ");
    tg->write(tg, 2, "o");

    tg->stop(tg);
    printf("%s\n", st->str);

    st->destroy(st);
    return 0;
}