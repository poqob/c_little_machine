#include "../../../inc/utils/fileOperations/readFile.h"
#include <stdlib.h>
_ReadFile *newReadFile(_ReadFile *this, char *path)
{
    this = (_ReadFile *)malloc(sizeof(_ReadFile));
    this->parser = initializeParser(this->parser);
    this->path = new_jval_s(strdup(path));
    this->is = new_inputstruct(jval_s(this->path));
    this->parse = parseFile;

    return this;
}

void freeReadFile(_ReadFile *this)
{
    // free(this->is);
    // jettison_inputstruct(this->path);
    //  free(this);
}

char *validCharacterControll(char *c)
{
    if (strchr(c, '\\b') != NULL && c[0] != 'b')
        return " ";
    if (strchr(c, '\\n') != NULL && c[0] != 'n')
        return "\n";
    return c;
}

void *parseFile(_ReadFile *this)
{
    while (get_line(this->is) >= 0) // loop for lines
    {
        // special character validation.
        for (int i = 0; i < this->is->NF; i++) // loop for words
            this->is->fields[i] = validCharacterControll(this->is->fields[i]);

        this->codeLine = newCodeLineWithParameters(this->is->fields, this->is->NF);
        this->parser->parse(this->parser, this->codeLine);

        free(this->codeLine);
    }
};