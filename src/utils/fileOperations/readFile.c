#include "../../../inc/utils/fileOperations/readFile.h"
#include <stdlib.h>
_ReadFile *newReadFile(char *path)
{
    int wordCount = 0;
    _ReadFile *this = (_ReadFile *)malloc(sizeof(_ReadFile));
    this->path = new_jval_s(strdup(path));
    this->is = new_inputstruct(jval_s(this->path));

    while (get_line(this->is) >= 0) // loop for lines
    {
        for (int i = 0; i < this->is->NF; i++) // loop for words
        {
            wordCount++;
            // printf("%d: %s\n", this->is->line, this->is->fields[i]);
        }
        // send words to parser
        wordCount = 0;
    }
}

void freeReadFile(_ReadFile *this)
{
    // free(this->is);
    // jettison_inputstruct(this->path);
    //  free(this);
}