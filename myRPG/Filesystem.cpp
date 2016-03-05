#include <fstream>
#include <cstdio>
#include "Filesystem.h"

using namespace luabridge;

Filesystem::Filesystem(){
}

Filesystem::~Filesystem(){
}

void Filesystem::writeToFile(statsMap stats, statsMap equipment, std::vector<std::shared_ptr<Inventory> > items,
	std::vector<std::shared_ptr<Abilities> > abilities, std::shared_ptr<Resistance> resistance, std::string filename) {
	//create loadable lua script
	auto getValue = [](statsMap map, std::string name){
		return map.find(name)->second[0];
	};
	//TODO rework needed
	std::ofstream fout("./SavedGames/" + filename);
	fout << "--lua script\nplayer = {" << std::endl;
	fout << "\tname = \"" << getValue(stats, "name") << "\"," << std::endl;
	fout << "\tclass = \"" << getValue(stats, "class") << "\"," << std::endl;
	fout << "\tlevel = " << getValue(stats, "level") << "," << std::endl;
	fout << "\texp = " << getValue(stats, "exp") << "," << std::endl;
	fout << "\tinit = " << getValue(stats, "init") << "," << std::endl;
	fout << "\thp = " << getValue(stats, "hp") << "," << std::endl;
	fout << "\tmaxHP = " << getValue(stats, "maxHP") << "," << std::endl;
	fout << "\tmp = " << getValue(stats, "mp") << "," << std::endl;
	fout << "\tmaxMP = " << getValue(stats, "maxMP") << "," << std::endl;

	fout << "\tdamage = " << getValue(stats, "damage") << "," << std::endl;
	fout << "\tarmor = " << getValue(stats, "armor") << "," << std::endl;
	fout << "\tfriendly = " << getValue(stats, "friendly") << "," << std::endl;
	fout << "\thpGrowth = " << getValue(stats, "hpGrowth") << "," << std::endl;
	fout << "\tmpGrowth = " << getValue(stats, "mpGrowth") << "," << std::endl;
	fout << "\tdmgGrowth = " << getValue(stats, "dmgGrowth") << "," << std::endl;

	fout << "\tequipment = {\n\t\tusing = {" << std::endl;
	fout << "\t\t\thead = " << getValue(equipment, "head") << "," << std::endl;
	fout << "\t\t\tbody = " << getValue(equipment, "body") << "," << std::endl;
	fout << "\t\t\tlegs = " << getValue(equipment, "legs") << "," << std::endl;
	fout << "\t\t\tfeet = " << getValue(equipment, "feet") << "," << std::endl;
	fout << "\t\t\tshoulders = " << getValue(equipment, "shoulders") << "," << std::endl;
	fout << "\t\t\tgloves = " << getValue(equipment, "gloves") << "," << std::endl;
	fout << "\t\t\tmainhand = " << getValue(equipment, "mainhand") << "," << std::endl;
	fout << "\t\t\toffhand = " << getValue(equipment, "offhand") << "," << std::endl;
	fout << "\t\t}," << std::endl;
	fout << "\t\tbackpack = {" << std::endl;
	for (auto& i : items){
		fout << "\t\t\t{" << std::endl;
		fout << "\t\t\t\titem = \"" << i->getName() << "\"," << std::endl;
		fout << "\t\t\t\tcount = " << i->getQuantity() << "," << std::endl;
		fout << "\t\t\t}," << std::endl;
	}
	fout << "\t\t}," << std::endl;
	fout << "\t}," << std::endl;
	fout << "\tAbilities = {" << std::endl;
	for (auto& i : abilities) {
		fout << "\t\t\"" << i->getName() << "\"," << std::endl;
	}
	fout << "\t}," << std::endl;
	fout << "\tResistance = {" << std::endl;
	fout << "\t\tcold = " << resistance->getColdImmunity() << "," << std::endl;
	fout << "\t\tfire = " << resistance->getFireImmunity() << "," << std::endl;
	fout << "\t\telectricity = " << resistance->getElectricityImmunity() << "," << std::endl;
	fout << "\t\twater = " << resistance->getWaterImmunity() << "," << std::endl;
	fout << "\t}," << std::endl;
	fout << "}" << std::endl;
}

std::map<std::string, std::vector<std::string> > Filesystem::readCharacterData(std::string filename){
	//TODO rework needed
	//start lua script
	lua_State* L = luaState();
	luaL_dofile(L, filename.c_str());
	LuaRef player = getGlobal(L, "player");
	//normal values
	LuaRef name = player["name"];
	LuaRef pclass = player["class"];
	LuaRef level = player["level"];
	LuaRef exp = player["exp"];
	LuaRef initiative = player["init"];
	LuaRef hp = player["hp"];
	LuaRef maxHP = player["maxHP"];
	LuaRef mp = player["mp"];
	LuaRef maxMP = player["maxMP"];
	LuaRef damage = player["damage"];
	LuaRef armor = player["armor"];
	LuaRef friendly = player["friendly"];
	LuaRef hpGrowth = player["hpGrowth"];
	LuaRef mpGrowth = player["mpGrowth"];
	LuaRef dmgGrowth = player["dmgGrowth"];
	//equipment handler
	LuaRef equipment = player["equipment"];
	//using items handler
	LuaRef use = equipment["using"];
	LuaRef head = use["head"];
	LuaRef body = use["body"];
	LuaRef legs = use["legs"];
	LuaRef feet = use["feet"];
	LuaRef shoulders = use["shoulders"];
	LuaRef gloves = use["gloves"];
	LuaRef mainhand = use["mainhand"];
	LuaRef offhand = use["offhand"];
	//backpack handler
	LuaRef backpack = equipment["backpack"];
	//Abilities handler
	LuaRef Abilities = player["Abilities"];
	//Resistance handler
	LuaRef Resistance = player["Resistance"];
	LuaRef cold = Resistance["cold"];
	LuaRef fire = Resistance["fire"];
	LuaRef electricity = Resistance["electricity"];
	LuaRef water = Resistance["water"];

	std::map<std::string, std::vector<std::string> > map = { 
		{ "name", mapValues(name) },
		{ "class", mapValues(pclass) },
		{ "level", mapValues(level) },
		{ "exp" , mapValues(exp) },
		{ "init", mapValues(initiative) },
		{ "mp", mapValues(mp) },
		{ "maxMP", mapValues(maxMP) },
		{ "hp", mapValues(hp) },
		{ "maxHP", mapValues(maxHP) },
		{ "damage", mapValues(damage) },
		{ "armor", mapValues(armor) },
		{ "friendly", mapValues(friendly) },
		{ "hpGrowth", mapValues(hpGrowth) },
		{ "mpGrowth", mapValues(mpGrowth) },
		{ "dmgGrowth", mapValues(dmgGrowth) },
	};

	//Abilities
	std::vector<std::string> abil;
	for (auto i = 1; i < Abilities.length() + 1; i++) {
		abil.push_back(Abilities[i].cast<std::string>());
	}
	map.insert(std::pair<std::string, std::vector<std::string> >("Abilities", abil));
	//Resistance
	map.insert(makePair("cold", cold));
	map.insert(makePair("fire", fire));
	map.insert(makePair("electricity", electricity));
	map.insert(makePair("water", water));
	//Equipment
	//using
	map.insert(makePair("head", head));
	map.insert(makePair("body", body));
	map.insert(makePair("legs", legs));
	map.insert(makePair("feet", feet));
	map.insert(makePair("shoulders", shoulders));
	map.insert(makePair("gloves", gloves));
	map.insert(makePair("mainhand", mainhand));
	map.insert(makePair("offhand", offhand));
	//backpack
	std::vector<std::string> items;
	for (auto i = 1; i < backpack.length() + 1; i++) {
		LuaRef item = backpack[i];
		items.push_back(item["item"].cast<std::string>());
		items.push_back(item["count"].cast<std::string>());
	}
	map.insert(std::pair<std::string, std::vector<std::string> >("backpack", items));

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