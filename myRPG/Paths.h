//Paths to all files in one place

class Paths{
public:
	Paths();
	~Paths();

	static const std::string weapon;
	static const std::string armor;
	static const std::string abilities;
	static const std::string saveGames;
};

const std::string Paths::weapon = "";
const std::string Paths::armor = "";
const std::string Paths::abilities = "";
const std::string Paths::saveGames = "./SavedGames/";