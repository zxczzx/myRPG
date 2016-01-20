#pragma once
#include "Inventory.h"
#include "Requirements.h"
#include "ItemSlot.h"

class Player;

class UsableItem : public Inventory
{
protected:
	int maxDurability;
	int durability;
	bool used;
	ItemSlot itemSlot;
	std::shared_ptr<Requirements> requirements;
	std::shared_ptr<UsableItem> thisObj;

public:
	UsableItem();
	~UsableItem();
	
	template<class T>
	std::shared_ptr<UsableItem> createItem();

	virtual void use(Player& player);
	virtual void unuse(Player& player);

	ItemSlot getItemSlot();
	bool getUsed();
};


template<class T>
std::shared_ptr<UsableItem> UsableItem::createItem(){
	std::shared_ptr<UsableItem> item = std::make_shared<T>();
	item->thisObj = item;
	return item;
}