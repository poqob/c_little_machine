#include "../inc/lfdr/fields.h"
#include "../inc/lfdr/jval.h"
#include "../inc/lfdr/dllist.h"
#include "../inc/utils/fileOperations/readFile.h"
#include "../inc/utils/dataTypes/Stack.h"
#include "../inc/utils/dataTypes/Queue.h"
#include "../inc/utils/dataTypes/Boolean.h"
#include "../inc/utils/dataTypes/String.h"
#include "../inc/generator/textGenerator.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/parser/parser.h"
#include "../inc/parser/operatorsEnum.h"
int main(int argc, char **argv)
{
    _ReadFile *rf = newReadFile(rf, "./data/input.dat");
    rf->parse(rf);
    return 0;
}