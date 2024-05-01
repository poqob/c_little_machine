#include "../inc/lfdr/fields.h"
#include "../inc/lfdr/jval.h"
#include "../inc/lfdr/dllist.h"
#include "../inc/utils/fileOperations/readFile.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    _ReadFile *rf = newReadFile("./data/input.dat");
    freeReadFile(rf);
    return 0;
}