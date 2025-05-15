#include "Parser.h"

TokenArray Parser::Tokenize(const string src, const string separator)
{
    {
        size_t posIni = 0;
        size_t fpos = src.find(separator, posIni);
        TokenArray RetVal;

        while (fpos != src.npos)
        {
            RetVal.emplace_back(src.substr(posIni, fpos - posIni));
            posIni = fpos + separator.length();
            fpos = src.find(separator, posIni);
        }


        return RetVal;
    }
}
