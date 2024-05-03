#if !defined(TEXTGENERATOR)
#define TEXTGENERATOR
#include "../utils/fileOperations/createFile.h"
#include "../parser/operatorsEnum.h"
#include "../utils/dataTypes/String.h"
typedef struct TextGenerator TextGenerator;
struct TextGenerator
{
    int cursorPos;
    String *text;
    boolean (*write)(TextGenerator *tg, Operators operator, int count, char *text);
    boolean (*remove)(TextGenerator *tg, Operators operator, int count, char *text);
    boolean (*goLast)(TextGenerator *tg);
    boolean (*stop)(TextGenerator *tg);
};
TextGenerator *initializeTextGenerator(TextGenerator *tg);
#endif // TEXTGENERATOR
