#include "../../../inc/utils/dataTypes/CodeLine.h"
// dump
CodeLine *newCodeLine()
{
    CodeLine *this = (CodeLine *)malloc(sizeof(CodeLine));
    this->wordCount = 0;
    return this;
}

CodeLine *newCodeLineWithParameters(char **words, int wordCount)
{
    CodeLine *this = (CodeLine *)malloc(sizeof(CodeLine));
    this->wordCount = wordCount;
    this->words = words;
    return this;
}