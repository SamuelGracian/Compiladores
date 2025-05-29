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

	 void Parse(const string& src, const string& seprator);
private:
	 void AddToken(string Value);

	 bool isOperator(string& Token);

	 string Trim(string& str) const ;

	 bool IsValid(const char& Char) const ;
	
	 //Token container
	vector <Tokens> m_tokens;

	static const string m_operators[];
};

