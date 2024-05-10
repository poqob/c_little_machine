#if !defined(READ_FILE_)
#define READ_FILE_
#include "../../lfdr/jval.h"
#include "../../lfdr/fields.h"
#include "../../lfdr/dllist.h"
#include "../dataTypes/CodeLine.h"
#include "../../parser/parser.h"
// TODO: code the destructors.
typedef struct _ReadFile _ReadFile;
struct _ReadFile
{
    Parser *parser;
    CodeLine *codeLine;
    Jval inputPath;  // file path
    Jval outputPath; // file path
    IS is;           // file op
    void *(*parse)(_ReadFile *this);
};

// @param char* path
_ReadFile *newReadFile(_ReadFile *this, char *, char *);
void freeReadFile(_ReadFile *);
char *validCharacterControll(char *c);
void *parseFile(_ReadFile *this);

#endif // READ_FILE_