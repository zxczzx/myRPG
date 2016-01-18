#include "ConsumableItem.h"

ConsumableItem::ConsumableItem(){
}

ConsumableItem::~ConsumableItem(){
}

void ConsumableItem::use(std::shared_ptr<Player> player){
	quantity--;
	use(player);
}