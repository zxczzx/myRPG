#pragma once
#include "libraries.h"

template<class T>
class Backpack
{
	std::vector < std::shared_ptr<T> > items;

public:
	Backpack();

	void appendToBackpack(std::shared_ptr<T> item);
	void removeFromBackpack(std::shared_ptr<T> item);
	std::vector<std::shared_ptr<T> > getItems();
};

//********* CPP *********

template<class T>
Backpack<T>::Backpack(){
}

template<class T>
void Backpack<T>::appendToBackpack(std::shared_ptr<T> item){
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

template<class T>
void Backpack<T>::removeFromBackpack(std::shared_ptr<T> item){
	for (unsigned i = 0; items.size(); i++){
		if (items[i]->getName() == item->getName()){
			items.erase(items.begin() + i);
			break;
		}
	}
}

template<class T>
std::vector<std::shared_ptr<T> > Backpack<T>::getItems(){
	return items;
}