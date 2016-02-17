--lua script
ability = {
	name = "Fire bolt",
	description = "Small but deadly fire missle",
	useString = "burned",
	damage = 4,
	manaConsumprion = 4,
	quantity = 1,
	usable = 0,
	Requirements = {
		class = { 
			"Mage",
			"Warrior",
		},
		level = 1,
	},
}