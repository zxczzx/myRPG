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

	virtual void use(Player& player);
	virtual void unuse(Player& player);

	int getAttackValue();
	int getArmorValue();
	ItemSlot getItemSlot();
	std::shared_ptr<Requirements> getRequirements();
	std::shared_ptr<Resistance> getResistance();
	std::shared_ptr<Abilities> getAbilities();
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