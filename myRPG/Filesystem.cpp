#include <fstream>
#include <cstdio>
#include "Filesystem.h"
#include "dirent.h"

using namespace luabridge;

Filesystem::Filesystem(){
	//initiate lua state
	L = luaL_newstate();
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
}

Filesystem::~Filesystem(){
}

void Filesystem::writeToFile(statsMap stats, statsMap equipment, std::vector<std::shared_ptr<Inventory> > items, std::string filename){
	//create loadable lua script
	auto getValue = [](statsMap map, std::string name){
		return map.find(name)->second[0];
	};

	std::ofstream fout("./SavedGames/" + filename);
	fout << "--lua script\nsave = {" << std::endl;
	fout << "\tname = \"" << getValue(stats, "name") << "\"," << std::endl;
	fout << "\tclass = \"" << getValue(stats, "class") << "\"," << std::endl;
	fout << "\tlevel = " << getValue(stats, "level") << "," << std::endl;
	fout << "\texp = " << getValue(stats, "exp") << "," << std::endl;
	fout << "\thp = " << getValue(stats, "hp") << "," << std::endl;
	fout << "\tmp = " << getValue(stats, "mp") << "," << std::endl;
	fout << "\tequipment = {\n\t\tusing = {" << std::endl;
	fout << "\t\t\tHead = " << getValue(equipment, "Head") << "," << std::endl;
	fout << "\t\t\tBody = " << getValue(equipment, "Body") << "," << std::endl;
	fout << "\t\t\tLegs = " << getValue(equipment, "Legs") << "," << std::endl;
	fout << "\t\t\tFeet = " << getValue(equipment, "Feet") << "," << std::endl;
	fout << "\t\t\tShoulders = " << getValue(equipment, "Shoulders") << "," << std::endl;
	fout << "\t\t\tGloves = " << getValue(equipment, "Gloves") << "," << std::endl;
	fout << "\t\t\tMainhand = " << getValue(equipment, "Mainhand") << "," << std::endl;
	fout << "\t\t\tOffhand = " << getValue(equipment, "Offhand") << "," << std::endl;
	fout << "\t\t}," << std::endl;
	fout << "\t\tbackpack = {" << std::endl;
	for (auto& i : items){
		fout << "\t\t\t\"" << i->getName() << "\"," << std::endl;
	}
	fout << "\t\t}," << std::endl;
	fout << "\t}," << std::endl;
	fout << "}" << std::endl;
}

std::map<std::string, std::vector<std::string> > Filesystem::readSaveGameData(std::string filename){
	//start lua script
	luaL_dofile(L, filename.c_str());
	LuaRef save = getGlobal(L, "save");
	//normal values
	LuaRef name = save["name"];
	LuaRef pclass = save["class"];
	LuaRef level = save["level"];
	LuaRef exp = save["exp"];
	LuaRef hp = save["hp"];
	LuaRef mp = save["mp"];

	//equipment handler
	LuaRef equipment = save["equipment"];
	LuaRef use = equipment["using"];
	LuaRef backpack = equipment["backpack"];

	//map values
	auto mapValues = [](LuaRef ref){
		return std::vector<std::string>(1, ref.cast<std::string>());
	};

	std::map<std::string, std::vector<std::string> > map = { 
		{ "name", mapValues(name) },
		{ "class", mapValues(pclass) },
		{ "level", mapValues(level) },
		{ "exp", mapValues(exp) },
		{ "hp", mapValues(hp) },
		{ "mp", mapValues(mp) },
	};
	//TODO get using and backpack values
	return map;
}

std::map<std::string, std::vector<std::string> > Filesystem::readItemData(std::string filename){
	std::map<std::string, std::vector<std::string> > map;
	return map;
}

std::map<std::string, std::vector<std::string> > Filesystem::readCharacterData(std::string filename){
	std::map<std::string, std::vector<std::string> > map;
	return map;
}

std::vector<std::string> Filesystem::listDirectory(){
	//open file
	luaL_dofile(L, "scandir.lua");
	//get variable
	LuaRef myTable = getGlobal(L, "result");
	std::vector<std::string> result;
	myTable.push(L);
	push(L, Nil());
	//read table
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