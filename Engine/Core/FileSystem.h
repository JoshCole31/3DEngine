#pragma once
#include<string>

namespace jc
{
	void SetFilePath(const std::string& pathname);
	bool ReadFileToString(const std::string& filename, std::string& filestring);
	std::string GetFilePath();

}