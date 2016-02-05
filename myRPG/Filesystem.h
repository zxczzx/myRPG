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
	luabridge::lua_State* luaState();

public:
	Filesystem();
	~Filesystem();

	typedef std::map<std::string, std::vector<std::string> > statsMap;

	void writeToFile(statsMap stats, statsMap equipment, std::vector<std::shared_ptr<Inventory> > items, std::string filename);
	statsMap readSaveGameData(std::string filename);
	statsMap readItemData(std::string filename);
	statsMap readCharacterData(std::string filename);
	statsMap readAbilityData(std::string filename);
	std::vector<std::string> listDirectory();
};

