
#include "../../inc/parser/operatorsEnum.h"
// dump operatorsEnum.h

Operators getOperator(char *c)
{
    if (strcmp(c, "write:") == 0 || strcmp(c, "yaz:") == 0)
    {
        return WRITE;
    }
    if (strcmp(c, "remove:") == 0 || strcmp(c, "sil:") == 0)
    {
        return REMOVE;
    }
    if (strcmp(c, "golast:") == 0 || strcmp(c, "sonagit:") == 0)
    {
        return GOLAST;
    }
    if (strcmp(c, "stop:") == 0 || strcmp(c, "dur:" == 0))
    {
        return STOP;
    }
    return -1;
}
