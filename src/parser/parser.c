#include "../../inc/parser/parser.h"

void initializeParser(Parser *parser)
{
    parser->stack = (Stack *)malloc(sizeof(Stack));
    initializeStack(parser->stack);
    initializeStack(parser->stackRes);
    parser->isOperator = isOperator;
    parser->isNumber = isNumber;
    parser->parse = parse;
}

// TODO: use stoi
boolean isNumber(char *c)
{
    if (c[0] >= '0' && c[0] <= '9')
        return true;
    return false;
}

boolean isOperator(char *c)
{
    if (getOperator(c) != -1)
        return true;
    return false;
}

void parse(Parser *p, CodeLine *codeline)
{
    char *expression;
    int i;
    boolean flag = false; // keeps queue of number variable after operator. false: number, true: operand
    for (i = 0; i < codeline->wordCount; i++)
    {
        expression = codeline->words[i];
        if (isOperator(expression).value == true.value) // if the expression is an operator
        {
            // controll does codeline valid or not.
            if ((codeline->wordCount - 1) % 2 == 1)
            {
                printf("Syntax Error: Invalid Expression\n");
                exit(1);
            }

            // set if the word is an operator.
            if (getOperator(expression) != -1)
                p->operator= getOperator(expression);

            // fetch number fetch character then send them to text generator.
        }
    }
}