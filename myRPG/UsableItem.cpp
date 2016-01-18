#include "UsableItem.h"

UsableItem::UsableItem(){
	requirements = std::make_shared<Requirements>();
}

UsableItem::~UsableItem(){
}

ItemSlot UsableItem::getItemSlot(){
	return itemSlot;
}