#pragma once
#include <string>

using std::string;

class Tokens
{
public:
	Tokens(string& Type, string& Value)
		: m_type(Type), m_value(Value) {}

private:

	string m_type;

	string m_value;
};

