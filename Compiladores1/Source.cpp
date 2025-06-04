#include<iostream>

#include "FileBuffer.h"
#include "Parser.h"

int main()
{
	Parser parser;

	FileBuffer fB("SourceCode.txt");
	
	std::cout << fB.GetAsString() << std::endl;

	//auto Tokens = parser.Tokenize(fB.GetAsString(), "exe");

	parser.Parse(fB.GetAsString(), " ");

	parser.PrintTokens();

	//Tokens.size();

	return 0;
}