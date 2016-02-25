#pragma once
#include "libraries.h"
#include "ItemSlot.h"

class Requirements;
class Abilities;
class Resistance;
class Player;

class Inventory
{
protected:
	std::string name;
	std::string description;
	unsigned quantity;
	bool usable;

	int maxDurability;
	int durability;
	int attackValue;
	int armorValue;
	ItemSlot itemSlot;
	std::shared_ptr<Requirements> requirements;
	std::shared_ptr<Inventory> thisObj;
	//special items
	std::shared_ptr<Resistance> resistance;
	std::shared_ptr<Abilities> abilities;

public:
	Inventory();
	~Inventory();

	//std::shared_ptr<Inventory> usableItem;

	//getters
	void showDescription();
	std::string getName();
	int getQuantity();
	bool isUsable();
	int getAttackValue();
	int getArmorValue();
	ItemSlot getItemSlot();
	int getDurability();
	int getMaxDurability();
	std::shared_ptr<Requirements> getRequirements();
	std::shared_ptr<Resistance> getResistance();
	std::shared_ptr<Abilities> getAbilities();
	//setters
	void setQuantity(int count);
	void setName(std::string value);
	void setDescription(std::string value);
	void setUsable(bool flag);
	void setAttackValue(int value);
	void setArmorValue(int value);
	void setItemSlot(ItemSlot slot);
	void setDurability(int value);
	void setMaxDurability(int value);
	void setRequirements(std::shared_ptr<Requirements> obj);
	void setResistance(std::shared_ptr<Resistance> obj);
	void setAbilities(std::shared_ptr<Abilities> obj);
	void setThisObj(std::shared_ptr<Inventory> me);

	void use(std::shared_ptr<Player> player);
	void unuse(std::shared_ptr<Player> player);

};