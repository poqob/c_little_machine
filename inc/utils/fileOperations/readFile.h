#if !defined(READ_FILE_)
#define READ_FILE_
#include "../../lfdr/jval.h"
#include "../../lfdr/fields.h"
#include "../../lfdr/dllist.h"
typedef struct _ReadFile _ReadFile;
struct _ReadFile
{
    Jval path; // file path
    IS is;     // file op
};

// @param char* path
_ReadFile *newReadFile(char *);
void freeReadFile(_ReadFile *);

#endif // READ_FILE_
