--lua script
player = {
	name = "Orc",
	class = "Warrior",
	level = 1,
	exp = 5,
	init = 0,
	hp = 5,
	maxHP = 5,
	mp = 0,
	maxMP = 0,
	damage = 1,
	armor = 0,
	friendly = 0,
	hpGrowth = 0,
	mpGrowth = 0,
	dmgGrowth = 0,
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
			{
				item = "Coin",
				count = 2,
			},
		},
	},
	Abilities = {
	},
	Resistance = {
		cold = 0,
		fire = 0,
		electricity = 0,
		water = 0,
	},
}