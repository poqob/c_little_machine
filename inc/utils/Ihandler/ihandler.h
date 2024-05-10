#if !defined(IHANDLER)
#define IHANDLER
#include "../dataTypes/Boolean.h"
#include "stdlib.h"
#include <stdio.h>

typedef struct IHandler
{
    boolean (*handle)(int argc, char **argv);
} IHandler;
boolean _fileExists(const char *filename);
boolean _handle(int argc, char **argv);
IHandler *newHandler(IHandler *);
#endif // IHANDLER
