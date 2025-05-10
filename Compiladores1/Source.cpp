#include<iostream>

#include "FileBuffer.h"
#include "Parser.h"

int main()
{
	FileBuffer fB("SourceCode.txt");
	
	std::cout << fB.GetAsString() << std::endl;

	Parser::Tokenize(fB.GetAsString(), ".exe");

	return 0;
}