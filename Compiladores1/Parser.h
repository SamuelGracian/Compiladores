#pragma once

#include <vector>
#include <string>

using std::vector;
using TokenArray = vector<string>;
using std::string;

class Parser
{
public: 
	Parser() = default;

	static  TokenArray Tokenize(const string src, const string separator);

};

