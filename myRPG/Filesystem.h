#pragma once
#include "libraries.h"
#include "Inventory.h"
#include <LuaBridge.h>
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

class Filesystem
{
private:
	luabridge::lua_State* L;

public:
	Filesystem();
	~Filesystem();

	typedef std::map<std::string, std::vector<std::string> > statsMap;

	void deleteFile(std::string filename);
	void writeToFile(statsMap stats, statsMap equipment, std::vector<std::shared_ptr<Inventory> > items, std::string filename);
	std::map<std::string, std::vector<std::string> > readSaveGameData(std::string filename);
	std::map<std::string, std::vector<std::string> > readItemData(std::string filename);
	std::map<std::string, std::vector<std::string> > readCharacterData(std::string filename);
	std::vector<std::string> listDirectory();
};

