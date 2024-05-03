#if !defined(CODELINE)
#define CODELINE
#define MAXFIELDS 1000
typedef struct CodeLine CodeLine;
struct CodeLine
{
    char *words[MAXFIELDS];
    int wordCount;
};

#endif // CODELINE
