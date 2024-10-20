#include "Helper.h"



enum Menu { Print = 1, Play, Exit };



int main()
{
	srand(time(0));

	int numArmy = armySize();
	Army army1(numArmy);
	Army army2(numArmy);
	mainMenu(army1, army2);
}



int armySize()
{
	int size;
	bool validNum = false;

	while (!validNum)
	{
		cout << "Enter a number to make an army: ";
		cin >> size;

		if (size <= 0)
		{
			invalidInput();
		}
		else
		{
			validNum = true;
		}
	}

	return size;
}

void mainMenu(Army& Army1, Army& Army2)
{
	int menuOption = 0;

	while (menuOption != Exit)
	{
		printMainMenu(menuOption);

		switch (menuOption)
		{
		case Print:
			print(Army1, 1);
			print(Army2, 2);
			break;
		case Play:
			battleArmy(Army1, Army2);
			print(Army1, 1);
			print(Army2, 2);
			printBattleResult(Army1, Army2);
			break;
		case Exit:
			cout << "Programm is ending." << endl;
			break;
		default:
			invalidInput();
			break;
		}
	}
}

void printMainMenu(int& userInput)
{
	cout << "\n\n********** Main Menu **********\n"
		"[" << Print << "] Print\n"
		"[" << Play << "] Play\n"
		"[" << Exit << "] Exit\n"
		"Select from the menu above: ";

	cin >> userInput;
}

void print(Army& userArmy, int numOfArmy)
{
	cout << "\nArmy" << numOfArmy;
	userArmy.printArmy();
}

void invalidInput()
{
	cout << INPUT_ERR << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printBattleResult(Army& Army1, Army& Army2)
{
	cout << "\nArmy 1 has total " << Army1.getTotalHealth() << " health.";
	cout << "\nArmy 2 has total " << Army2.getTotalHealth() << " health.";

	if (Army1.getTotalHealth() > Army2.getTotalHealth())
	{
		cout << "\nArmy 1 won the battle." << endl;
	}
	else if (Army1.getTotalHealth() < Army2.getTotalHealth())
	{
		cout << "\nArmy 2 won the battle." << endl;
	}
	else
	{
		cout << "\nThis battle is a draw." << endl;
	}
}

void battleArmy(const Army& army1, const Army& army2)
{
	for (int i = 0; i < army1.getActCreatures(); i++)
	{
		cout << setfill('-') << setw(77) << "" << endl
			<< setfill(' ');

		battleCreatures(army1.getCreature(i), army2.getCreature(i));

		cout << setfill('-') << setw(77) << "" << endl
			<< setfill(' ');
	}
}

void battleCreatures(Creature* attacker, Creature* defender)
{
	bool turn = (rand() % 2 == 0);

	while (attacker->getHealth() > MIN_HEALTH && defender->getHealth() > MIN_HEALTH)
	{
		if (turn)
		{
			int damage = attacker->getDamage();
			if ((defender->getHealth() - damage) <= MIN_HEALTH)
			{
				defender->setHealth(MIN_HEALTH);
			}
			else
			{
				defender->setHealth(defender->getHealth() - damage);
			}
			cout << attacker->getName() << "[Army1] attacked " << defender->getName() << "[Army2] for " << damage << " damage." << endl;
			cout << defender->getName() << "[Army2] has " << defender->getHealth() << " health remaining." << endl;
		}
		else
		{
			int damage = defender->getDamage();
			if ((attacker->getHealth() - damage) <= MIN_HEALTH)
			{
				attacker->setHealth(MIN_HEALTH);
			}
			else
			{
				attacker->setHealth(attacker->getHealth() - damage);
			}
			cout << defender->getName() << "[Army2] attacked " << attacker->getName() << "[Army1] for " << damage << " damage." << endl;
			cout << attacker->getName() << "[Army1] has " << attacker->getHealth() << " health remaining." << endl;
		}

		turn = !turn;
	}

	if (attacker->getHealth() <= 0)
	{
		cout << endl << defender->getName() << " wins!" << endl;
	}
	else
	{
		cout << endl << attacker->getName() << " wins!" << endl;
	}
}