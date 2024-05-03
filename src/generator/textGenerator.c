#include "../../inc/generator/textGenerator.h"
// dump

TextGenerator *initializeTextGenerator(TextGenerator *tg)
{

    tg = (TextGenerator *)malloc(sizeof(TextGenerator));
    tg->cursorPos = 0;
    tg->text = newString("");
    tg->write = _write;
    tg->remove = _remove;
    tg->goLast = _goLast;
    tg->stop = _stop;
    return tg;
}

// yazdıkça cursor pozisyonunu günceller
// eğer silme işlemi gerçekleşirse iki durum oluşur
// 1. cursor ortada ya da başta bir yerde kalır
// 2. hiçbir şey silinmez ve cursor en sonda konumlarnır.
// TODO: ilk durum için yapılması gereken metnin override edilmesi. Bunu String kütüphanesi ile nasıl uyumlu başarırsın düşün???
static boolean _write(TextGenerator *tg, Operators operator, int count, char *text)
{
    if (operator== WRITE)
    {
        for (int i = 0; i < count; i++)
            appendCharacterArray(tg->text, text);

        return true;
    }
    return false;
}

static boolean _remove(TextGenerator *tg, Operators operator, int count, char *text)
{
    if (operator== REMOVE)
    {
        for (int i = 0; i < count; i++)
            removeCharacterArray(tg->text, text);
        return true;
    }
    return false;
}