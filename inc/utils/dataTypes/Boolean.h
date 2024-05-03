#ifndef BOOLEAN_H
#define BOOLEAN_H

typedef struct
{
    int value;
} boolean;

#define true ((boolean){1})
#define false ((boolean){0})

// Function prototypes (optional, for clarity)
boolean not(boolean a);
boolean and (boolean a, boolean b);
boolean or (boolean a, boolean b);

#endif
