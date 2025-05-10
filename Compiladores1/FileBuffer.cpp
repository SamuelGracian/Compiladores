#include "FileBuffer.h"
#include <fstream>

using std::ifstream;

FileBuffer::FileBuffer(const string& filePath)
{
	ifstream file(filePath, std::ios::in | std::ios::binary | std::ios::ate);

	if (!file)
	{
		return;
	}

	int fileSize = file.tellg();
	file.seekg(std::ios::beg);
	m_fileData.resize(fileSize);

	file.read(m_fileData.data(), fileSize);

}

string FileBuffer::GetAsString()
{
	string retVal;
	retVal.insert(retVal.end(), m_fileData.begin(), m_fileData.end());

	return retVal;
}
