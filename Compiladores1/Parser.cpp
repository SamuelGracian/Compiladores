#include "Parser.h"

const string Parser::m_operators[] = { "+","-","*","/" };

TokenArray Parser::Tokenize(const string src, const string separator)
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

void Parser::AddToken(string  Value)
{
    string type;

    if (isOperator(Value))
    {
        type = "Operator";
    }
	m_tokens.emplace_back(Tokens(type, Value));
}

bool Parser::isOperator(string& Token)
{
    for (string Operator : m_operators)
    {
        if (Token == Operator)
            return true;
    }
    return false;
}
