#if !defined(CODELINE)
#define CODELINE
#define MAXFIELDS 1000
#include <stdlib.h>
typedef struct CodeLine CodeLine;
// each code line have to start with a valid operator word. [look for operatorsEnum.h]
struct CodeLine
{
    char **words;
    int wordCount;
};
CodeLine *newCodeLine();
CodeLine *newCodeLineWithParameters(char **words, int wordCount);

#endif // CODELINE
