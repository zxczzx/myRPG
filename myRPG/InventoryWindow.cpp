#include "InventoryWindow.h"

InventoryWindow::InventoryWindow(World* world)
{
	charSize = 16;
	int width = 160;
	sf::Vector2f screenPos = sf::Vector2f(475, 267);
	setup(8, charSize, width, screenPos);
	this->world = world;
	update(world);

	selectedItemIndex = 0;
}

InventoryWindow::~InventoryWindow()
{
	clear();
}

void InventoryWindow::handleInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (selectedItemIndex - 1 > 0)
			{
				messages[selectedItemIndex].setFillColor(sf::Color::White);
				selectedItemIndex--;
				messages[selectedItemIndex].setFillColor(sf::Color::Red);
				std::cout << "up" << std::endl;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (selectedItemIndex + 1 < messages.size())
			{
				messages[selectedItemIndex].setFillColor(sf::Color::White);
				selectedItemIndex++;
				messages[selectedItemIndex].setFillColor(sf::Color::Red);
				std::cout << "down" << std::endl;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			if (items[selectedItemIndex - 1]->isUsable()) {
				world->getActor()->useItem(items[selectedItemIndex - 1]);
				update(world);
				std::cout << std::endl << "You have used " << items[selectedItemIndex - 1]->getName() << std::endl;
				--selectedItemIndex;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) || sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
			std::cout << messages[selectedItemIndex].getString().toAnsiString() << std::endl;
			removeItem(world);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			std::cout << "\t" << items[selectedItemIndex - 1]->getName() << std::endl;
			items[selectedItemIndex - 1]->showDescription();
			if (items[selectedItemIndex - 1]->isUsable()) {
				if (items[selectedItemIndex - 1]->getArmorValue() != 0)
					std::cout << "Armor: \t" << items[selectedItemIndex - 1]->getArmorValue() << std::endl;
				if (items[selectedItemIndex - 1]->getAttackValue() != 0)
					std::cout << "Damage: \t" << items[selectedItemIndex - 1]->getAttackValue() << std::endl;
				if (items[selectedItemIndex - 1]->getMaxDurability() != 0)
					std::cout << "Durability: \t" << items[selectedItemIndex - 1]->getDurability() << "/"
					<< items[selectedItemIndex - 1]->getMaxDurability() << std::endl;
				if (items[selectedItemIndex - 1]->getResistance()->getColdImmunity() != 0)
					std::cout << "Cold resistnce: " << items[selectedItemIndex - 1]->getResistance()->getColdImmunity() << std::endl;
				if (items[selectedItemIndex - 1]->getResistance()->getElectricityImmunity() != 0)
					std::cout << "Electricity resistnce: "
					<< items[selectedItemIndex - 1]->getResistance()->getElectricityImmunity() << std::endl;
				if (items[selectedItemIndex - 1]->getResistance()->getFireImmunity() != 0)
					std::cout << "Fire resistnce: " << items[selectedItemIndex - 1]->getResistance()->getFireImmunity() << std::endl;
				if (items[selectedItemIndex - 1]->getResistance()->getWaterImmunity() != 0)
					std::cout << "Water resistnce: " << items[selectedItemIndex - 1]->getResistance()->getWaterImmunity() << std::endl;
				std::cout << "Required level: " << items[selectedItemIndex - 1]->getRequirements()->level << std::endl;
				if (items[selectedItemIndex - 1]->getRequirements()->classType.size() != 2) {
					std::cout << "(Only for ";
					for (auto& i : items[selectedItemIndex - 1]->getRequirements()->classType) {
						std::cout << i;
					}
					std::cout << ")" << std::endl;
				}
			}
		}
	}
}

void InventoryWindow::removeItem(World* world)
{
	world->getActor()->getBackpack()->removeFromBackpack(items[selectedItemIndex - 1]);
	update(world);
	std::cout << std::endl << "Item " << items[selectedItemIndex - 1]->getName() << " has been removed" << std::endl;
	--selectedItemIndex;
}

void InventoryWindow::update(World* world)
{
	messages.clear();
	content.setPosition(sf::Vector2f(497, 283));
	content.setString("\tBackpack:");
	add(content);

	for (unsigned i = 0; i < world->getActor()->getBackpack()->getItems().size(); i++) {
		content.setString(std::to_string(world->getActor()->getBackpack()->getItems()[i]->getQuantity()) + "x " +
			world->getActor()->getBackpack()->getItems()[i]->getName());
		items.push_back(world->getActor()->getBackpack()->getItems()[i]);

		content.setPosition(content.getPosition().x, content.getPosition().y + charSize*1.2f);
		add(content);
	}
}
