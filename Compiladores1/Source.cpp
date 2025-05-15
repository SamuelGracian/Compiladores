#include<iostream>

#include "FileBuffer.h"
#include "Parser.h"

int main()
{
	FileBuffer fB("SourceCode.txt");
	
	std::cout << fB.GetAsString() << std::endl;

	auto Tokens = Parser::Tokenize(fB.GetAsString(), ".exe");
	Tokens.size();

	return 0;
}