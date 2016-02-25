#pragma once
#include "libraries.h"
#include "Filesystem.h"
#include "ItemSlot.h"

class Inventory;
class Abilities;
class Requirements;
class Resistance;
class Player;

class ObjectSpawn
{
public:
	ObjectSpawn();
	~ObjectSpawn();

	std::shared_ptr<Filesystem> filesystem;

	typedef std::map<std::string, std::vector<std::string> > statsMap;

	std::shared_ptr<Inventory> spawnItem(std::string filename, int count);
	std::shared_ptr<Player> spawnActor(std::string filename);
	std::shared_ptr<Abilities> spawnAbility(std::string filename, int count);

	ItemSlot getSlotFromString(std::string slot);

	int getIntegerValue(statsMap map, std::string key);
	std::string getStringValue(statsMap map, std::string key);

	std::shared_ptr<Requirements> createRequirements(statsMap map);
	std::shared_ptr<Resistance> createResistance(statsMap map);
};