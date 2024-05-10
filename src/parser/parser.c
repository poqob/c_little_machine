#include "../../inc/parser/parser.h"

Parser *initializeParser(Parser *parser, char *outputPath)
{
    parser = (Parser *)malloc(sizeof(Parser));
    parser->textGenerator = initializeTextGenerator(parser->textGenerator, outputPath);
    parser->isOperator = isOperator;
    parser->isNumber = isNumber;
    parser->parse = parse;
    parser->snapshot = snapshotForExecutedLine;
    return parser;
}

boolean isNumber(char *c)
{
    if (atoi(c) != 0)
        return true;
    return false;
}

boolean isOperator(char *c)
{
    if (getOperator(c) != -1)
        return true;
    return false;
}

// TODO: Implement this function.
void parse(Parser *p, CodeLine *codeline)
{
    int numberSequence = 1;
    int wordSequence = 2;
    p->codeLine = codeline;

    // controll if the first word is an operator.
    if (isOperator(codeline->words[0]).value == false.value || codeline->wordCount % 2 != 1) // wordcount must be odd.
    {
        printf("Syntax Error: Invalid Expression\n");
        exit(1);
    }
    else
        p->operator= getOperator(codeline->words[0]);
    // printf("TEST IN PARSER\n");
    // printf("snapshot before parser: %s\n", p->snapshot(p));
    //  get in a loop and fetch the words one by one in (number,word) order.
    switch (p->operator)
    {
    case WRITE:
        // printf("snapshot before write: %s\n", p->snapshot(p));
        while (wordSequence < p->codeLine->wordCount)
        {
            // syntax control
            if (p->isNumber(p->codeLine->words[numberSequence]).value == false.value)
            {
                printf("Syntax Error: Invalid Expression\n");
                exit(1);
            }
            // write to the text generator.
            p->textGenerator->write(p->textGenerator, atoi(p->codeLine->words[numberSequence]), p->codeLine->words[wordSequence]);
            numberSequence += 2;
            wordSequence += 2;
        }
        break;
    case REMOVE:
        // printf("snapshot before remove: %s\n", p->snapshot(p));
        while (wordSequence < p->codeLine->wordCount)
        {
            // syntax control
            if (p->isNumber(p->codeLine->words[numberSequence]).value == false.value)
            {
                printf("Syntax Error: Invalid Expression\n");
                exit(1);
            }
            // write to the text generator.
            p->textGenerator->remove(p->textGenerator, atoi(p->codeLine->words[numberSequence]), p->codeLine->words[wordSequence]);
            numberSequence += 2;
            wordSequence += 2;
        }
        break;
        break;
    case GOLAST:
        p->textGenerator->goLast(p->textGenerator);
        break;
    case STOP:
        // printf("snapshot before stop: %s\n", p->snapshot(p));

        p->textGenerator->stop(p->textGenerator);
        break;
    default:
        break;
    }
}

char *snapshotForExecutedLine(Parser *parser)
{
    String *st = newString("");
    for (int i = 0; i < parser->codeLine->wordCount; i++)
    {
        st->appendChar(st, parser->codeLine->words[i]);
        st->appendChar(st, " ");
    }
    return st->str;
}
