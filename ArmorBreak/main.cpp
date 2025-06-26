#include <iostream>



int calculateDamage(int atk, int def);

int main()
{

	struct Character
	{
		std::string name;
		int hp {}; // Health
		int atk{}; // Attack
		int def{}; // Defense

		//
		// Prints all character stats to console
		//
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
			// Calculates and applies damage based on incoming attack power
			// Damage is reduced by this character's defense			
			//
			int totalDamage = calculateDamage(incomingAtk, def);
	
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


//
// Calculates damage based on attack and defense values
// Uses a diminishing returns formula where higher defense reduces damage proportionally
//
int calculateDamage(int atk, int def)
{
	//
	// Prevent negative or zero attack from dealing damage
	//
	if (atk <= 0) return 0;

	//
	// Convert values to float before division to get proper floating-point result
	//
	float multiplier = static_cast<float>(atk) / (atk + def);

	//
	// Round the result when converting back to int
	//
	int damage = static_cast<int>(atk * multiplier + 0.5f);

	return damage;
}
