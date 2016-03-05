#pragma once

enum class Graphic {
	//Menu enums (save load etc.)
	MENU_GUI,
	MENU_GUI_BACK,
	MENU_STORY_GUI,
	MENU_START_GAME_GUI,
	MENU_QUIT_GUI,
	MENU_LOAD_GAME_GUI,

	//Player creation
	CREATE_Actor,
	CREATE_WRITE_OPTION,
	CREATE_CLASS_OPTION,

	//Battle enums (attack, special, spell etc.)
	BATTLE_GUI,
	BATTLE_VICTORY_GUI,
	BATTLE_GAME_OVER_GUI,

	//Inventory enums (weapon, armor etc.)
	INVENTORY_GUI,
	INVENTORY_EQUIPMENT,
	INVENTORY_BACKPACK,
	INVENTORY_SPELLS,
	INVENTORY_SPECIAL_ABILITIES,
};