#include "../inc/utils/fileOperations/readFile.h"
int main(int argc, char **argv)
{
    _ReadFile *rf = newReadFile(rf, "./data/input.dat");
    rf->parse(rf);
    return 0;
}