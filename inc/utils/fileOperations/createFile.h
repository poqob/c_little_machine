#if !defined(CREATEFILE)
#define CREATEFILE
#include "../dataTypes/Boolean.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct CreateFile CreateFile;
struct CreateFile
{
    char *fileName;
    boolean (*create)(CreateFile *createFile);
};
CreateFile *CreateFileConstructor(CreateFile *createFile, char *fileName);

#endif // CREATEFILE
