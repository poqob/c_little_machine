#if !defined(TEXTGENERATOR)
#define TEXTGENERATOR
#include "../utils/fileOperations/createFile.h"
#include "../utils/dataTypes/String.h"
typedef struct TextGenerator TextGenerator;
struct TextGenerator
{
    int cursorPos;
    String *text;
    CreateFile *cf;
    boolean (*write)(TextGenerator *tg, int count, char *text);
    boolean (*remove)(TextGenerator *tg, int count, char *text);
    boolean (*goLast)(TextGenerator *tg);
    boolean (*stop)(TextGenerator *tg);
};
TextGenerator *initializeTextGenerator(TextGenerator *tg, char *outputPath);
boolean _writeTextGenerator(TextGenerator *tg, int count, char *text);
boolean _removeTextGenerator(TextGenerator *tg, int count, char *text);
boolean _goLastTextGenerator(TextGenerator *tg);
boolean _stopTextGenerator(TextGenerator *tg);
#endif // TEXTGENERATOR
