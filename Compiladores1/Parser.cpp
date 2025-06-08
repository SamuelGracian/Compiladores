
#include "Parser.h"

TokenArray Parser::Tokenize(const string& src)
{
    vector<string> separators = { "+", "-", "*", "/", "(", ")", " " };
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
            if (!last_token.empty()) tokens.emplace_back("Unknown", last_token);
            break;
        }

        if (next_pos > start)
        {
            tokens.emplace_back("Unknown", src.substr(start, next_pos - start));
        }

        if (next_sep != " ")
        {
            tokens.emplace_back("Unknown", next_sep);
        }

        start = next_pos + next_sep.length();
    }

    return tokens;
}

void Parser::AddToken(string value)
{
    string type;

    if (isdigit(value[0]))
    {
        type = "Number";
    }
    else if (IsOperator(value))
    {
        type = "operator";
    }
    else if (value == "(" || value == ")")
    {
        type = "Bracket";
    }
    else
    {
        type = "Unknown";
    }

    m_tokens.emplace_back(type, value);
}

void Parser::Parse(const string& src, const string& /*unused*/)
{
    TokenArray rawTokens = Tokenize(src);
    for (const auto& token : rawTokens)
    {
        string trimmed = Trim(token.m_value);
        if (!trimmed.empty())
        {
            AddToken(trimmed);
        }
    }
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
    return (c != ' ' && c != '\n' && c != '\r');
}

bool Parser::IsOperator(const string& str) const
{
    for (const auto& op : m_operators)
    {
        if (str == op)
        {
            return true;
        }
    }
    return false;
}

int Parser::GetPriority(const string& op) const
{
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

TokenArray Parser::ToReversePolish() const
{
    TokenArray output;
    stack<Tokens> operators;

    for (const auto& token : m_tokens)
    {
        if (token.m_type == "Number")
        {
            output.push_back(token);
        }
        else if (token.m_type == "operator")
        {
            while (!operators.empty() &&
                operators.top().m_type == "operator" &&
                GetPriority(operators.top().m_value) >= GetPriority(token.m_value))
            {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
        else if (token.m_value == "(")
        {
            operators.push(token);
        }
        else if (token.m_value == ")")
        {
            while (!operators.empty() && operators.top().m_value != "(")
            {
                output.push_back(operators.top());
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // Pop the "("
        }
    }

    while (!operators.empty())
    {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}

double Parser::EvaluatePolish(const TokenArray& rpn) const
{
    stack<double> evluation;

    for (const auto& token : rpn)
    {
        if (token.m_type == "Number")
        {
            evluation.push(stod(token.m_value));
        }
        else if (token.m_type == "operator")
        {
            double b = evluation.top(); evluation.pop();
            double a = evluation.top(); evluation.pop();

            if (token.m_value == "+") evluation.push(a + b);
            else if (token.m_value == "-") evluation.push(a - b);
            else if (token.m_value == "*") evluation.push(a * b);
            else if (token.m_value == "/") evluation.push(a / b);
        }
    }

    return evluation.top();
}

double Parser::Evaluate()
{
    auto reversePolish = ToReversePolish();
    return EvaluatePolish(reversePolish);
}

void Parser::PrintTokens() const
{
    for (const auto& token : m_tokens)
    {
        cout << "[" << token.m_type << "] " << token.m_value << "\n";
    }
}
