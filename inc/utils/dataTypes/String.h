#if !defined(STRING)
#define STRING
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

// String data type.

typedef struct String String;
struct String
{
    char *str;
    int len;
    void (*destroy)(String *this);
    int (*getSize)(String *this);
    void (*appendStr)(String *this, String *string);
    void (*appendInt)(String *this, int val);
    void (*appendChar)(String *this, char *val);
    void (*removeAt)(String *this, int location);
    void (*overrideFromLocation)(String *this, int location, char *val);

    String *(*trim)(String *this);
};

String *newString(char *s);
void destroyString(String *str);
int getStringSize(String *str);
void appendString(String *this, String *str);
void appendIntager(String *this, int val);
void appendCharacterArray(String *this, char *val);
void overrideFromLoc(String *this, int location, char *val);
void removeAtString(String *this, int location);
String *trimString(String *str);
String *newMultiplyString(char *chararr, int count);
#endif // STRING