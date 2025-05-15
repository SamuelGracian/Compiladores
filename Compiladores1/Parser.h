#pragma once
#include "Tokens.h"

#include <vector>
#include <string>

using std::vector;
using TokenArray = vector<string>;
using std::string;

class Parser
{
public: 
	Parser() = default;

	 TokenArray Tokenize(const string src, const string separator);

private:
	 void AddToken(string Value);

	 bool isOperator(string& Token);
	
	vector <Tokens> m_tokens;

	static const string m_operators[];
};

