#include "EquipmentWindow.h"

EquipmentWindow::EquipmentWindow(World* world)
{
	charSize = 16;
	width = 220;
	screenPos = sf::Vector2f(475, 267);
	setup(11, charSize, width, screenPos);
	this->world = world;
	update(world);
	
	selectedItemIndex = 0;
}

EquipmentWindow::~EquipmentWindow()
{
}

void EquipmentWindow::handleInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (selectedItemIndex - 2 > 0)
			{
				messages[selectedItemIndex].setFillColor(sf::Color::White);
				messages[selectedItemIndex + 1].setFillColor(sf::Color::White);
				selectedItemIndex -= 2;
				messages[selectedItemIndex].setFillColor(sf::Color::Red);
				messages[selectedItemIndex + 1].setFillColor(sf::Color::Red);
				std::cout << "up" << std::endl;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (selectedItemIndex + 2 < messages.size())
			{
				messages[selectedItemIndex].setFillColor(sf::Color::White);
				messages[selectedItemIndex + 1].setFillColor(sf::Color::White);
				selectedItemIndex += 2;
				messages[selectedItemIndex].setFillColor(sf::Color::Red);
				messages[selectedItemIndex + 1].setFillColor(sf::Color::Red);
				std::cout << "down" << std::endl;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			removeItem(world);
		}
	}
}

void EquipmentWindow::removeItem(World* world)
{
	auto slot = [=] {
		if (messages[selectedItemIndex].getString().toAnsiString() == "Head") {
			return ItemSlot::HEAD;
		}
		else if (messages[selectedItemIndex].getString().toAnsiString() == "Body") {
			return ItemSlot::BODY;
		}
		else if (messages[selectedItemIndex].getString().toAnsiString() == "Legs") {
			return ItemSlot::LEGS;
		}
		else if (messages[selectedItemIndex].getString().toAnsiString() == "Feet") {
			return ItemSlot::FEET;
		}
		else if (messages[selectedItemIndex].getString().toAnsiString() == "Shoulders") {
			return ItemSlot::SHOULDERS;
		}
		else if (messages[selectedItemIndex].getString().toAnsiString() == "Gloves") {
			return ItemSlot::GLOVES;
		}
		else if (messages[selectedItemIndex].getString().toAnsiString() == "Main-hand") {
			return ItemSlot::MAIN_HAND;
		}
		else if (messages[selectedItemIndex].getString().toAnsiString() == "Off-hand") {
			return ItemSlot::OFFHAND;
		}
	};

	if (world->getActor()->BodySlots.find(slot())->second != nullptr) {
		std::string itemName = world->getActor()->BodySlots.find(slot())->second->getName();
		world->getActor()->takeOffItem(world->getActor()->BodySlots.find(slot())->second);
		std::cout << "You have taken off " << itemName << std::endl;
	}
	else {
		std::cout << "This slot is already empty" << std::endl;
	}
	update(world);
}

void EquipmentWindow::update(World* world)
{
	messages.clear();
	content.setPosition(sf::Vector2f(497, 283));
	content.setString("\tEquipment:");
	add(content);
	content.setString("");
	add(content);

	auto getSlot = [=](ItemSlot slot) {
		return world->getActor()->BodySlots[slot] == nullptr ? "Empty slot" : world->getActor()->BodySlots[slot]->getName();
	};

	content.setString("Head");
	add(content);
	content.setString(getSlot(ItemSlot::HEAD));
	add(content);
	content.setString("Body");
	add(content);
	content.setString(getSlot(ItemSlot::BODY));
	add(content);
	content.setString("Legs");
	add(content);
	content.setString(getSlot(ItemSlot::LEGS));
	add(content);
	content.setString("Feet");
	add(content);
	content.setString(getSlot(ItemSlot::FEET));
	add(content);
	content.setString("Shoulders");
	add(content);
	content.setString(getSlot(ItemSlot::SHOULDERS));
	add(content);
	content.setString("Gloves");
	add(content);
	content.setString(getSlot(ItemSlot::GLOVES));
	add(content);
	content.setString("Main-hand");
	add(content);
	content.setString(getSlot(ItemSlot::MAIN_HAND));
	add(content);
	content.setString("Off-hand");
	add(content);
	content.setString(getSlot(ItemSlot::OFFHAND));
	add(content);

	for (int i = 2; i < messages.size(); i += 2) {
		std::cout << content.getPosition().x << " " << content.getPosition().y << std::endl;
		messages[i].setPosition(screenPos.x + 20, messages[i - 2].getPosition().y + charSize*1.2f);
		messages[i + 1].setPosition(screenPos.x + width - 100, messages[i - 2].getPosition().y + charSize*1.2f);
	}
}