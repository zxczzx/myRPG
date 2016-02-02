#include <fstream>
#include <cstdio>
#include "Filesystem.h"
#include "dirent.h"

#include <LuaBridge.h>
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}
using namespace luabridge;

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
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
	luaL_dofile(L, "scandir.lua");

	LuaRef myTable = getGlobal(L, "result");

	std::vector<std::string> result;
	myTable.push(L);
	push(L, Nil());
	while (lua_next(L, -2))
	{
		LuaRef val = LuaRef::fromStack(L, -1);
		result.push_back(val);
		lua_pop(L, 1);
	}
	return result;
}

void Filesystem::deleteFile(std::string filename){
	std::string file("./SavedGames/" + filename);
	std::remove(file.c_str());
}