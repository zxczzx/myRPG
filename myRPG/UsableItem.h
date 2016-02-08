#pragma once
#include "Inventory.h"
#include "Requirements.h"
#include "ItemSlot.h"
#include "Abilities.h"
#include "Resistance.h"

class Player;

class UsableItem : public Inventory
{
protected:
	int maxDurability;
	int durability;
	int attackValue;
	int armorValue;
	ItemSlot itemSlot;
	std::shared_ptr<Requirements> requirements;
	std::shared_ptr<UsableItem> thisObj;
	//special items
	std::shared_ptr<Resistance> resistance;
	std::shared_ptr<Abilities> abilities;

public:
	UsableItem();
	~UsableItem();
	
	template<class T>
	static std::shared_ptr<UsableItem> createItem();
	template<class T>
	static std::shared_ptr<UsableItem> createItem(int count);

	void use(std::shared_ptr<Player> player);
	void unuse(std::shared_ptr<Player> player);

	//getters
	int getAttackValue();
	int getArmorValue();
	ItemSlot getItemSlot();
	int getDurability();
	int getMaxDurability();
	std::shared_ptr<Requirements> getRequirements();
	std::shared_ptr<Resistance> getResistance();
	std::shared_ptr<Abilities> getAbilities();
	//setters
	void setAttackValue(int value);
	void setArmorValue(int value);
	void setItemSlot(ItemSlot slot);
	void setDurability(int value);
	void setMaxDurability(int value);
	void setRequirements(std::shared_ptr<Requirements> obj);
	void setResistance(std::shared_ptr<Resistance> obj);
	void setAbilities(std::shared_ptr<Abilities> obj);
	void setThisObj(std::shared_ptr<UsableItem> me);
};

template<class T>
std::shared_ptr<UsableItem> UsableItem::createItem(){
	std::shared_ptr<UsableItem> item = std::make_shared<T>();
	item->thisObj = item;
	return item;
}

template<class T>
std::shared_ptr<UsableItem> UsableItem::createItem(int count){
	std::shared_ptr<UsableItem> item = std::make_shared<T>(count);
	item->thisObj = item;
	return item;
}