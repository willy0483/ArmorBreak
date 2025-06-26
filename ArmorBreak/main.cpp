#include <iostream>


int main()
{

	struct Character
	{
		std::string name;
		int hp {}; // Health
		int atk{}; // Attack
		int def{}; // Defense

		void printStats()
		{
			std::cout << "------------------\n";
			std::cout << "Name : " << name << '\n';
			std::cout << "Hp   : " << hp   << '\n';
			std::cout << "atk  : " << atk  << '\n';
			std::cout << "def  : " << def  << '\n';
			std::cout << "------------------\n";

		}

		//
		// Character takes damage from attack and takes it from health 
		//
		void takeDamage(int incomingAtk)
		{
			//
			// Convert values to float before division to get proper floating-point result
			//
			float damageMultiplier = static_cast<float>(incomingAtk) / (incomingAtk + def);

			//
			// Round the result when converting back to int
			//
			int totalDamage = static_cast<int>(incomingAtk * damageMultiplier + 0.5f);

			//
			// Subtract hp from total damage
			//
			hp -= totalDamage;

			std::cout << name << " took " << totalDamage << " damage!\n";
		}

	};


	//
	// Create Player
	//
	Character player;
	player.name = "William";
	player.atk  = 10;
	player.hp   = 100;
	player.def  = 15;

	//
	// Create Enemy
	//
	Character enemy;
	enemy.name  = "Troll";
	enemy.atk   = 5;
	enemy.hp    = 150;
	enemy.def   = 30;

	//
	// Enemy takes damage from player
	//
	enemy.takeDamage(player.atk);

	player.printStats();
	enemy.printStats();



	return 0;
}