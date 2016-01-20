#include "ConsumableItem.h"

ConsumableItem::ConsumableItem(){
}

ConsumableItem::~ConsumableItem(){
}

void ConsumableItem::use(Player& player){
	quantity--;
	use(player);
}

void ConsumableItem::unuse(Player& player){
}