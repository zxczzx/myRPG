#pragma once
#include "libraries.h"
#include "Inventory.h"
#include "Abilities.h"
#include "Resistance.h"
#include "Backpack.h"
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

	void writeToFile(statsMap stats, statsMap equipment, std::vector<std::shared_ptr<Inventory> > items, 
		std::vector<std::shared_ptr<Abilities> > abilities, std::shared_ptr<Resistance> resistance, std::string filename);
	statsMap readItemData(std::string filename);
	statsMap readCharacterData(std::string filename);
	statsMap readAbilityData(std::string filename);
	std::vector<std::string> listDirectory();

	std::vector<std::string> mapValues(luabridge::LuaRef ref);
	std::pair<std::string, std::vector<std::string> > makePair(std::string str, luabridge::LuaRef ref);
};

