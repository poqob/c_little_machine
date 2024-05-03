#ifndef Operators_ENUMS_H
#define Operators_ENUMS_H

typedef enum Operators
{
    WRITE,
    REMOVE,
    GOLAST,
    STOP,
} Operators;
Operators getOperator(char *c);

#endif
