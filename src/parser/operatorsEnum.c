
#include "../../inc/parser/operatorsEnum.h"
// dump operatorsEnum.h
int strcmp(const char *str1, const char *str2);
Operators getOperator(char *c)
{
    if (strcmp(c, "write:") == 0 || strcmp(c, "yaz:") == 0)
    {
        return WRITE;
    }
    else if (strcmp(c, "remove:") == 0 || strcmp(c, "sil:") == 0)
    {
        return REMOVE;
    }
    else if (strcmp(c, "golast:") == 0 || strcmp(c, "sonagit:") == 0)
    {
        return GOLAST;
    }
    else if (strcmp(c, "stop:") == 0 || strcmp(c, "dur:") == 0) // TODO: durun nesi var??
    {
        return STOP;
    }
    return -1;
}
