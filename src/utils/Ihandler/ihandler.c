#include "../../../inc/utils/Ihandler/ihandler.h"

IHandler *newHandler(IHandler *handler)
{
    handler = (IHandler *)malloc(sizeof(IHandler));
    handler->handle = &_handle;
}

boolean _fileExists(const char *filename)
{
    // controll if the file extension is .dat
    if (filename[strlen(filename) - 4] != '.' || filename[strlen(filename) - 3] != 'd' || filename[strlen(filename) - 2] != 'a' || filename[strlen(filename) - 1] != 't')
    {
        printf("File extension must be .dat\n");
        return false;
    }

    FILE *file;

    if (file = fopen(filename, "r"))
    {
        fclose(file);
        return true;
    }
    return false;
}

boolean _handle(int argc, char **argv)
{
    // Check the command line arguments.
    if (argc < 3)
    {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return false;
    }

    // does the file exist?
    if (_fileExists(argv[1]).value != 1)
    {
        printf("File %s does not exist.\n", argv[1]);
        return false;
    }

    return true;
    // Read the file.
}
