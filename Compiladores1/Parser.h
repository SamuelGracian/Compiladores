#pragma once
#include "Tokens.h"

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using TokenArray = vector<string>;
using std::string;

class Parser
{
public: 
	Parser() = default;

	 TokenArray Tokenize (const string src);

	 void Parse(const string& src, const string& seprator);

	 void PrintTokens() const;

private:

	 void AddToken(string Value);

	 string Trim(const string& str) const ;

	 bool IsValid( char Char) const ;

	
	 //Token container
	vector <Tokens> m_tokens;

	static const string m_operators[];
};

