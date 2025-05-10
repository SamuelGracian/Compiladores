#pragma once

#include <vector>
#include <string>

//using std::vector;
//using TokenArray = vector<string>;
using std::string;

class Parser
{
public: 
	Parser() = default;

	static  std::vector<string> Tokenize(const string src, const string separator)
    {
        size_t posIni = 0;
        size_t fpos = src.find(separator, posIni);
        std::vector<string> RetVal;

        while (fpos != src.npos)
        {
            RetVal.emplace_back(src.substr(posIni, fpos));
            posIni = fpos + separator.length();
            fpos = src.find(separator, posIni);
        }


        return RetVal;
    }

};

