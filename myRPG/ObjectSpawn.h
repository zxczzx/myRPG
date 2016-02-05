#pragma once
#include "libraries.h"
#include "Filesystem.h"
#include "ItemSlot.h"

class UsableItem;
class Character;
class Abilities;

class ObjectSpawn
{
public:
	ObjectSpawn();
	~ObjectSpawn();

	std::shared_ptr<Filesystem> filesystem;

	typedef std::map<std::string, std::vector<std::string> > statsMap;

	std::shared_ptr<UsableItem> spawnItem(std::string filename);
	std::shared_ptr<Character> spawnCharacter(std::string filename);
	std::shared_ptr<Abilities> spawnAbility(std::string filename);

	ItemSlot getSlotFromString(std::string slot);
};

