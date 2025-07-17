#include<iostream>

#include "FileBuffer.h"
#include "Parser.h"
#include "Node.cpp"

int main()
{

	Parser parser;

	FileBuffer fB("SourceCode.txt");
	
	Node node;

	double Result = 0;
	
	std::cout << fB.GetAsString() << std::endl;

	//auto Tokens = parser.Tokenize(fB.GetAsString(), "exe");

	parser.Parse(fB.GetAsString(), " ");

	parser.PrintTokens();

	Result = parser.Evaluate();

	TokenVariable <double> token;
	
	token.SetValue(Result);

	std::cout << "Resultado de la ecuacion: " << Result << std::endl;


	return 0;
}