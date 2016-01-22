#include "Backpack.h"

Backpack::Backpack(){
}

Backpack::~Backpack(){
}

void Backpack::appendToBackpack(std::shared_ptr<Inventory> item){
	if (item->isUsable() == false){
		for (auto& i : items){
			if (i->getName() == item->getName()){
				i->setQuantity(i->getQuantity() + item->getQuantity());
				return;
			}
		}
		items.push_back(item);
	}
	else{
		items.push_back(item);
	}
}

void Backpack::removeFromBackpack(std::shared_ptr<Inventory> item){
	for (unsigned i = 0; items.size(); i++){
		if (items[i]->getName() == item->getName()){
			items.erase(items.begin() + i);
			break;
		}
	}
}

std::vector<std::shared_ptr<Inventory> > Backpack::getItems(){
	return items;
}