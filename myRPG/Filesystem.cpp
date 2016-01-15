#include <fstream>
#include <cstdio>
#include "Filesystem.h"
#include "dirent.h"

Filesystem::Filesystem(){
}

Filesystem::~Filesystem(){
}

void Filesystem::writeToFile(std::string filename){
}

std::map<std::string, std::string> Filesystem::readFromFile(std::string filename){
	std::map<std::string, std::string> map;
	std::ifstream infile(filename);

	std::string a, b;
	while (infile >> a >> b){
		// process pair (a,b)
		map[a] = b;
	}

	return map;
}

std::vector<std::string> Filesystem::listDirectory(){
	std::vector<std::string> result;
	//find files and push them to vector
	const std::string& path = std::string();
	dirent* de;
	DIR* dp;
	errno = 0;
	dp = opendir(path.empty() ? "./SavedGames/" : path.c_str());
	if (dp)
	{
		while (true)
		{
			errno = 0;
			de = readdir(dp);
			if (de == NULL) 
				break;
			result.push_back(std::string(de->d_name));
		}
		closedir(dp);
		//std::sort(result.begin(), result.end());
	}
	std::vector<std::string> resultParsed;
	for (unsigned i = 2; i < result.size(); i++){
		resultParsed.push_back(result[i]);
	}
	return resultParsed;
}

void Filesystem::deleteFile(std::string filename){
	std::string file("./SavedGames/" + filename + ".saved");
	std::remove(file.c_str());
}