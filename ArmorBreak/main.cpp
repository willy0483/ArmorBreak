#include <iostream>


int main()
{

	struct Character
	{
		std::string name;
		int hp{};
		int atk{};
		int def{};

		void printStats()
		{
			std::cout << "------------------\n";
			std::cout << "Name : " << name << '\n';
			std::cout << "Hp   : " << hp   << '\n';
			std::cout << "atk  : " << atk  << '\n';
			std::cout << "def  : " << def  << '\n';
			std::cout << "------------------\n";

		}

	};


	Character player;
	player.name = "William";
	player.atk = 10;
	player.hp = 100;
	player.def = 15;

	Character enemy;
	enemy.name = "Troll";
	enemy.atk = 5;
	enemy.hp = 150;
	enemy.def = 30;

	player.printStats();
	enemy.printStats();



	return 0;
}