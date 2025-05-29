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

    RetVal.emplace_back(src.substr(posIni));
    return RetVal;
}


void Parser::AddToken(string Value)
{
    string type;
    if (isOperator(Value)) {
        type = "Operator";
    }
    else if (isdigit(Value[0])) {
        type = "Number";
    }
    else if (isalpha(Value[0])) {
        type = "Identifier";
    }
    else {
        type = "Unknown";
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

string  Parser::Trim(string& str) const
{
    int Start = 0;
    int End = str.length();
   
    while (Start < End)
    {
        if (!IsValid(str[Start])  )
        {
            Start++;
            continue;
        }
        break;
    }
    
    while (End >= Start)
    {
        if (!IsValid(str[End]))
        {
            End--;
            continue;
        }
        break;
    }

    return str.substr(Start,End - Start);

}

bool Parser::IsValid(const char& Char) const 
{
    if (Char == '\n' || Char == ' ' || Char == '|' || Char == '!' || Char == '(' || Char == ')') return false;
    return true;
}


void Parser::Parse(const string& src, const string& separator)
{
    TokenArray tokens = Tokenize(src, separator);
    for (const auto& token : tokens) 
    {
		string TrimmedToken = Trim(const_cast<string&>(token));

        AddToken(TrimmedToken);
    }
}
