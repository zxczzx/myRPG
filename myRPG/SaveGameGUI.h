#pragma once
#include "GUI.h"
#include "Filesystem.h"

class SaveGameGUI : public GUI
{
private:
	void saveGame(World& world, std::shared_ptr<Filesystem> filesystem, std::string name);

public:
	SaveGameGUI();
	~SaveGameGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

