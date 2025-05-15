#pragma once
class Tokens
{
public:
	static bool isKeyword(const char* token);
	static bool isOperator(const char* token);
	static bool isLiteral(const char* token);

private:
	static const char* const keywords[];
	static const char* const operators[];
	static const char* const literals[];

};

