#if !defined(PARSER)
#define PARSER
#include "../lfdr/fields.h"
#include "../lfdr/jval.h"
#include "../utils/dataTypes/Boolean.h"
#include "../utils/dataTypes/String.h"
#include "../utils/dataTypes/CodeLine.h"
#include "../generator/textGenerator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operatorsEnum.h"
typedef struct Parser Parser;
struct Parser
{
    CodeLine *codeLine;
    Operators operator;
    TextGenerator *textGenerator;
    boolean (*isOperator)(char *c);
    boolean (*isNumber)(char *c);
    char *(*snapshot)(Parser *p);
    void (*parse)(Parser *p, CodeLine *expression);
};

boolean isOperator(char *c);
boolean isNumber(char *c);
void parse(Parser *p, CodeLine *codeLine);
Parser *initializeParser(Parser *parser);
void destroyParser(Parser *parser);
char *snapshotForExecutedLine(Parser *parser);

#endif // PARSER
