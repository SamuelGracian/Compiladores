#pragma once

#include <vector>
#include <string>

using std::string;
using std::vector;

class FileBuffer
{
public:
	FileBuffer(const string& filePath);

	string GetAsString();

private:
	
	vector<char> m_fileData;
};

