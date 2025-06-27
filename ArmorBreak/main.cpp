#include <iostream>



int calculateDamage(int atk, int def);
int getPlayerChoice();

int main()
{

	struct Character
	{
		std::string name;
		int hp			 = 0;	  // Health
		int atk			 = 0;	  // Attack
		int def			 = 0;	  // Defense
		bool isDefending = false; // Defending

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
		void takeDamage(int incomingAtk, bool defending)
		{

			//
			// Calculates and applies damage based on incoming attack power
			// Damage is reduced by this character's defense			
			//
			int totalDamage = calculateDamage(incomingAtk, def);


			if (defending)
			{
				totalDamage /= 2; // cut damage in half
				std::cout << name << " defended the attack!\n";
			}

	
			//
			// Subtract hp from total damage
			//
			hp -= totalDamage;

			if (hp < 0) hp = 0;

			std::cout << name << " took " << totalDamage << " damage!\n";
			std::cout << name << "'s remaining HP: " << hp << "\n";
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
	enemy.atk   = 15;
	enemy.hp    = 150;
	enemy.def   = 30;



	//
	// What turn is the game on
	//
	int turn = 1;




	//
	// Game loop while player or enemy has more then 0 health
	//
	while (player.hp > 0 && enemy.hp > 0)
	{

		std::cout << "\n==============================\n";
		std::cout << " Turn " << turn << "\n";
		std::cout << "==============================\n\n";


	
		//
		// Reset isDefending ervery turn
		//
		player.isDefending = false;

		//
		// Get player choice
		//
		int playerChoice{getPlayerChoice()};
		if (playerChoice == 1)
		{
			enemy.takeDamage(player.atk,enemy.isDefending);
		}
		else
		{
			player.isDefending = true;
		}


		// stop loop if health is less or 0 
		if (enemy.hp <= 0) break;
		// print stats after an attack
		enemy.printStats();

		player.takeDamage(enemy.atk,player.isDefending);
		if (player.hp <= 0) break;
		player.printStats();


		//
		// Add plus one to turn
		//
		++turn;

	}


	//
	// Prints who is the winner to console
	//
	std::cout << "\n==============================\n";
	std::cout << " Battle Result\n";
	std::cout << "==============================\n";

	if (player.hp <= 0)
	{
		std::cout << player.name << " has fallen.\n";
		std::cout << enemy.name << " wins with " << enemy.hp << " HP left!\n";
	}
	else
	{
		std::cout << enemy.name << " has fallen.\n";
		std::cout << player.name << " wins with " << player.hp << " HP left!\n";
	}


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


//
// Get players choice to attack or defend and take less damage
//
int getPlayerChoice()
{
	//
	// ask player to make a choice
	//
	int choice{};
	std::cout << "Choose your action:\n";
	std::cout << "1. Attack\n";
	std::cout << "2. Defend\n";
	std::cout << "> ";

	std::cin >> choice;
	while (choice != 1 && choice !=2)
	{
		std::cin.clear(); // clear error flag
		std::cin.ignore(1000, '\n'); // discard input
		std::cout << "Invalid input. Choose 1 or 2: ";
		std::cin >> choice;
	}

	return choice;
}