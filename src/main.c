#include "../inc/utils/fileOperations/readFile.h"
#include "../inc/utils/Ihandler/ihandler.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    // input file and output file must be given.
    IHandler *handler = newHandler(handler);
    if (handler->handle(argc, argv).value == 0)
    {
        free(handler);
        exit(1);
    }

    // create a new read file object.
    _ReadFile *rf = newReadFile(rf, argv[1], argv[2]);

    // parse the file.
    rf->parse(rf);

    // free the memory.
    free(handler);
    free(rf);
    return 0;
}

// TODO: Örnek çalışma ekran çıktılarına ait pdf döküman