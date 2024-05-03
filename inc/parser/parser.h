#if !defined(PARSER)
#define PARSER
#include "../lfdr/fields.h"
#include "../lfdr/jval.h"
#include "../utils/dataTypes/Boolean.h"
#include "../utils/dataTypes/Stack.h"
#include "../utils/dataTypes/CodeLine.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "operatorsEnum.h"
typedef struct Parser Parser;
struct Parser
{
    CodeLine *codeLine;
    Operators operator;
    Stack *stack;
    Stack *stackRes;
    boolean (*isOperator)(char *c);
    boolean (*isNumber)(char *c);
    void (*parse)(Parser *p, char *expression);
};

boolean isOperator(char *c);
boolean isNumber(char *c);
void parse(Parser *p, CodeLine *codeLine);
void initializeParser(Parser *parser);
void destroyParser(Parser *parser);

#endif // PARSER
