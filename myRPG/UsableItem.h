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
	ItemSlot itemSlot;
	std::shared_ptr<Requirements> requirements;
	std::shared_ptr<UsableItem> thisObj;

public:
	UsableItem();
	~UsableItem();
	
	template<class T>
	std::shared_ptr<UsableItem> createItem();
	template<class T>
	std::shared_ptr<UsableItem> createItem(int count);

	virtual void use(Player& player);
	virtual void unuse(Player& player);

	ItemSlot getItemSlot();
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