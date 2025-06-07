#include "Parser.h"


TokenArray Parser::Tokenize(const string src)
{
    vector<string> separators = { "+", "-", "*", "/", "(", ")", " "};
    TokenArray tokens;
    size_t start = 0;
    while (start < src.length())
    {
        size_t next_pos = string::npos;
        string next_sep;

        for (const auto& sep : separators) 
        {
            size_t pos = src.find(sep, start);
            if (pos != string::npos && (next_pos == string::npos || pos < next_pos)) 
            {
                next_pos = pos;
                next_sep = sep;
            }
        }

        if (next_pos == string::npos)
        {

            string last_token = src.substr(start);
            if (!last_token.empty()) tokens.push_back(last_token);
            break;
        }

        if (next_pos > start)
        {
            tokens.push_back(src.substr(start, next_pos - start));
        }

        if (next_sep != " ")
        {
            tokens.push_back(next_sep);
        }
        start = next_pos + next_sep.length();
    }
    return tokens;
}


void Parser::AddToken(string Value)
{
    string type;

     if (isdigit(Value[0]))
    {
        type = "Number";
    }
    else if (isalpha(Value[0]))
    {
         type = "Identifier";
    }
    else 
    {
        type = "Unknown";
    }
    m_tokens.emplace_back(Tokens(type, Value));
}

string Parser::Trim(const string& str) const
{
    size_t Start = 0;
    size_t End = str.length();

    while (Start < End && !IsValid(str[Start])) {
        Start++;
    }

    while (End > Start && !IsValid(str[End - 1])) {
        End--;
    }

    return str.substr(Start, End - Start);
}


bool Parser::IsValid(char c) const
{
    return (c != ' ' && c != '\n'  && c != '\r\n' && c != '\r');
}

bool Parser::IsOperator(const string& str) const
{
	for (const auto& op : m_operators)
    {
		if (str == op) {
			return true;
		}
	}
	return false;
}

void Parser::Parse(const string& src, const string& separator)
{
    TokenArray tokens = Tokenize(src);
    for (const auto& token : tokens)
    {
        string trimmed = Trim(token);  
        if (!trimmed.empty())
        {
            AddToken(trimmed);
        }
    }
}

void Parser::PrintTokens() const
{
	for (const auto& token : m_tokens) {
		std::cout << "Type: " << token.m_type << ", Value: " << token.m_value << std::endl;
	}
}