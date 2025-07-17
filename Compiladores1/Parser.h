#pragma once

#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <unordered_map>

#include "Tokens.h"
#include "Node.cpp"


using std::string;
using std::vector;
using std::stack;
using std::cout;
using std::endl;

using TokenArray = vector<Tokens>;

using std::unordered_map;

class Parser {
public:

    Parser() = default;

    void Parse(const string& src, const string& separator = "");

    double Evaluate(); 

    void PrintTokens() const;

    unordered_map<string, Object* > SymolTable;

private:

    TokenArray Tokenize(const string& src);

    void AddToken(string Value);

    string Trim(const string& str) const;

    bool IsValid(char c) const;

    bool IsOperator(const string& str) const;

	int GetPriority(const string& op) const;

    TokenArray ToReversePolish() const;

    double EvaluatePolish(const TokenArray& rpn) const;

    void VariableDeclaration(const std::string& name, const std::string& value);

private:
	vector<Tokens> m_tokens; // Store tokens
     
	const vector<string> m_operators = { "+", "-", "*", "/", "=", "(", ")" }; // defined operators

    Node* CurrentNode = nullptr; 
};
