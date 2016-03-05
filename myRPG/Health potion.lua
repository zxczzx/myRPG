--lua script
item = {
	name = "Health potion",
	description = "Red mixture that makes you fly. Heals for 10 hp",
	quantity = 1,
	attackValue = 0,
	armorValue = 0,
	usable = 1,
	maxDurability = 1,
	durability = 1,
	itemSlot = "POTIONS",
	Abilities = {
		"Heal",
	},
	Resistance = {
		cold = 0,
		fire = 0,
		electricity = 0,
		water = 0,
	},
	Requirements = {
		class = { 
			"Mage",
			"Warrior",
		},
		level = 2,
	},
}
