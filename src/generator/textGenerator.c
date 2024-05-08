#include "../../inc/generator/textGenerator.h"
// dump

TextGenerator *initializeTextGenerator(TextGenerator *tg)
{

    tg = (TextGenerator *)malloc(sizeof(TextGenerator));
    tg->cf = CreateFileConstructor(tg->cf, "./data/output.dat");
    tg->cursorPos = 0;
    tg->text = newString("");
    tg->write = &_writeTextGenerator;
    tg->remove = &_removeTextGenerator;
    tg->goLast = &_goLastTextGenerator;
    tg->stop = &_stopTextGenerator;
    return tg;
}

boolean _writeTextGenerator(TextGenerator *tg, int count, char *text)
{
    for (int i = 0; i < count; i++)
    {
        tg->text->overrideFromLocation(tg->text, tg->cursorPos, text);
        tg->cursorPos += strlen(text);
    }
    return true;
}

// scan the text from the CURRENT position to the beginning if there is a CHARACTER to remove then remove it.
boolean _removeTextGenerator(TextGenerator *tg, int count, char *text)
{
    int removedCharCount = 0;
    while (tg->cursorPos > -1 && removedCharCount < count)
    {
        if (tg->text->str[tg->cursorPos] == text[0])
        {
            tg->text->removeAt(tg->text, tg->cursorPos);
            removedCharCount++;
        }
        tg->cursorPos--;
    }
    if (tg->cursorPos < 0)
        tg->cursorPos = 0;
    return true;
}

boolean _goLastTextGenerator(TextGenerator *tg)
{
    tg->cursorPos = strlen(tg->text->str);
    return true;
}

// write to a file.
boolean _stopTextGenerator(TextGenerator *tg)
{
    tg->text->str[tg->text->len - 1] = '\0';
    return tg->cf->create(tg->cf, tg->text->str);
}