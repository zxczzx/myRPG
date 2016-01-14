#pragma once
#include "libraries.h"

class Filesystem
{
public:
	Filesystem();
	~Filesystem();

	void AppendToFile(FILE f);
	std::map<std::string, std::string> ReadFromFile(FILE f);
	std::string listDirectory();
};

