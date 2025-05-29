#pragma once
#include <string>

using std::string;

class Tokens
{
public:
    Tokens(const string& Type, const string& Value)
        : m_type(Type), m_value(Value) {
    }

    string m_type;
    string m_value;
};


