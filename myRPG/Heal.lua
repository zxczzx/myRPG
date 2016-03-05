--lua script
ability = {
	name = "Health potion",
	description = "Heal for 10 hp",
	useString = "healed",
	damage = -10,
	manaConsumprion = 0,
	quantity = 1,
	usable = 0,
	Requirements = {
		class = { 
			"Mage",
			"Warrior",
		},
		level = 0,
	},
}