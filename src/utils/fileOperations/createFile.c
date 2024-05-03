#include "../../../inc/utils/fileOperations/createFile.h"

CreateFile *CreateFileConstructor(CreateFile *createFile, char *fileName)
{
    createFile = (CreateFile *)malloc(sizeof(CreateFile));
    createFile->fileName = fileName;
    return createFile;
}

boolean create(CreateFile *createFile, char *content)
{
    FILE *f = fopen(createFile->fileName, "wb");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return false;
    }
    fwrite(content, sizeof(char), strlen(content), f);
    fclose(f);
    return true;
}
