--lua script
player = {
	name = "default",
	class = "Mage",
	level = 1,
	exp = 0,
	init = 0,
	hp = 20,
	maxHP = 20,
	mp = 20,
	maxMP = 20,
	damage = 2,
	armor = 0,
	friendly = 1,
	hpGrowth = 2,
	mpGrowth = 4,
	dmgGrowth = 1,
	equipment = {
		using = {
			head = 0,
			body = 0,
			legs = 0,
			feet = 0,
			shoulders = 0,
			gloves = 0,
			mainhand = 0,
			offhand = 0,
		},
		backpack = {
		},
	},
	Abilities = {
		"Fire bolt",
	},
	Resistance = {
		cold = 0,
		fire = 0,
		electricity = 0,
		water = 0,
	},
}