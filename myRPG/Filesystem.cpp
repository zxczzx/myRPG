#include <fstream>
#include <cstdio>
#include "Filesystem.h"

using namespace luabridge;

Filesystem::Filesystem(){
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
	lua_State* L = luaState();
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
	//start lua script
	lua_State* L = luaState();
	//luaL_dofile(L, filename.c_str());
	luaL_dofile(L, filename.c_str());
	LuaRef item = getGlobal(L, "item");
	//normal values
	LuaRef name = item["name"];
	LuaRef description = item["description"];
	LuaRef quantity = item["quantity"];
	LuaRef attackValue = item["attackValue"];
	LuaRef armorValue = item["armorValue"];
	LuaRef usable = item["usable"];
	LuaRef maxDurability = item["maxDurability"];
	LuaRef durability = item["durability"];
	LuaRef itemSlot = item["itemSlot"];
	//Abilities handler
	LuaRef Abilities = item["Abilities"];
	//Resistance handler
	LuaRef Resistance = item["Resistance"];
	LuaRef cold = Resistance["cold"];
	LuaRef fire = Resistance["fire"];
	LuaRef electricity = Resistance["electricity"];
	LuaRef water = Resistance["water"];
	//Requirements handler
	LuaRef Requirements = item["Requirements"];
	LuaRef pclass = Requirements["class"];
	LuaRef level = Requirements["level"];

	if (mapValues(usable)[0] == "0") {
		std::map<std::string, std::vector<std::string> > map = {
			{ "name", mapValues(name) },
			{ "description", mapValues(description) },
			{ "quantity", mapValues(quantity) },
			{ "usable", mapValues(usable) },
		};
		return map;
	}

	std::map<std::string, std::vector<std::string> > map = {
		{ "name", mapValues(name) },
		{ "description", mapValues(description) },
		{ "quantity", mapValues(quantity) },
		{ "attackValue", mapValues(attackValue) },
		{ "armorValue", mapValues(armorValue) },
		{ "usable", mapValues(usable) },
		{ "maxDurability", mapValues(maxDurability) },
		{ "durability", mapValues(durability) },
		{ "itemSlot", mapValues(itemSlot) },
	};
	//Abilities
	std::vector<std::string> abil;
	for (auto i = 1; i < Abilities.length() + 1; i++){
		abil.push_back(Abilities[i].cast<std::string>());
	}
	map.insert(std::pair<std::string, std::vector<std::string> >("Abilities", abil));
	//Resistance
	map.insert(makePair("cold", cold));
	map.insert(makePair("fire", fire));
	map.insert(makePair("electricity", electricity));
	map.insert(makePair("water", water));
	//Requirements
	std::vector<std::string> classes;
	for (auto i = 1; i < pclass.length()+1 ; i++){
		classes.push_back(pclass[i].cast<std::string>());
	}
	map.insert(std::pair<std::string, std::vector<std::string> >("class", classes));
	map.insert(makePair("level", level));

	return map;
}

std::map<std::string, std::vector<std::string> > Filesystem::readCharacterData(std::string filename){
	std::map<std::string, std::vector<std::string> > map;
	return map;
}

std::map<std::string, std::vector<std::string> > Filesystem::readAbilityData(std::string filename){
	//start lua script
	lua_State* L = luaState();
	//luaL_dofile(L, filename.c_str());
	luaL_dofile(L, filename.c_str());
	LuaRef item = getGlobal(L, "ability");
	//normal values
	LuaRef name = item["name"];
	LuaRef description = item["description"];
	LuaRef quantity = item["quantity"];
	LuaRef useString = item["useString"];
	LuaRef damage = item["damage"];
	LuaRef manaConsumprion = item["manaConsumprion"];
	LuaRef usable = item["usable"];
	//Requirements handler
	LuaRef Requirements = item["Requirements"];
	LuaRef pclass = Requirements["class"];
	LuaRef level = Requirements["level"];

	std::map<std::string, std::vector<std::string> > map = {
		{ "name", mapValues(name) },
		{ "description", mapValues(description) },
		{ "quantity", mapValues(quantity) },
		{ "useString", mapValues(useString) },
		{ "damage", mapValues(damage) },
		{ "usable", mapValues(usable) },
		{ "manaConsumprion", mapValues(manaConsumprion) },
	};
	//Requirements
	std::vector<std::string> classes;
	for (auto i = 1; i < pclass.length() + 1; i++){
		classes.push_back(pclass[i].cast<std::string>());
	}
	map.insert(std::pair<std::string, std::vector<std::string> >("class", classes));
	map.insert(makePair("level", level));

	return map;
}

std::vector<std::string> Filesystem::listDirectory(){
	//open file
	lua_State* L = luaState();
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

lua_State* Filesystem::luaState(){
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
	return L;
}

std::vector<std::string> Filesystem::mapValues(LuaRef ref){
	return std::vector<std::string>(1, ref.cast<std::string>());
}

std::pair<std::string, std::vector<std::string> > Filesystem::makePair(std::string str, LuaRef ref){
	return std::pair<std::string, std::vector<std::string> >(str, mapValues(ref));
}