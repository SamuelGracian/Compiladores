#include<iostream>

#include "FileBuffer.h"
#include "Parser.h"

int main()
{

	Parser parser;

	FileBuffer fB("SourceCode.txt");


	double Result = 0;
	
	std::cout << fB.GetAsString() << std::endl;

	//auto Tokens = parser.Tokenize(fB.GetAsString(), "exe");

	parser.Parse(fB.GetAsString(), " ");

	parser.PrintTokens();

	Result = parser.Evaluate();

	std::cout << "Resultado de la ecuacion: " << Result << std::endl;


	return 0;
}