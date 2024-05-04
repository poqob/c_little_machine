#if !defined(CREATEFILE)
#define CREATEFILE
#include "../dataTypes/Boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct CreateFile CreateFile;
struct CreateFile
{
    char *fileName;
    boolean (*create)(CreateFile *createFile, char *content);
};
CreateFile *CreateFileConstructor(CreateFile *createFile, char *fileName);
boolean create(CreateFile *createFile, char *content);
#endif // CREATEFILE
