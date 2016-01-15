#pragma once
#include "libraries.h"

class Filesystem
{
public:
	Filesystem();
	~Filesystem();

	void deleteFile(std::string filename);
	void writeToFile(std::string filename);
	std::map<std::string, std::string> readFromFile(std::string filename);
	std::vector<std::string> listDirectory();
};

