#include "../inc/utils/fileOperations/readFile.h"
// TODO: code the destructors.
// TODO: sytax correction error handling.
int main(int argc, char **argv)
{
    _ReadFile *rf = newReadFile(rf, "./data/input.dat");
    rf->parse(rf);
    return 0;
}