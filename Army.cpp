#include "Army.h"



Army::Army()
{
	allocateArmy(0);
}

Army::Army(const int size)
{
	allocateArmy(size);
	for (int i = 0; i < actCreatures; i++)
	{
		ppCreatures[i]->setCreature(setName(i + 1), setHealth(), setStrength());
	}
}

Army::Army(const Army& rhs)
{
	actCreatures = rhs.actCreatures;
	allocateArmy(actCreatures);
	for (int i = 0; i < actCreatures; i++)
	{
		ppCreatures[i]->setCreature(rhs.ppCreatures[i]->getName(), rhs.ppCreatures[i]->getHealth(), rhs.ppCreatures[i]->getStrength());
	}
}

Army::~Army()
{
	cleanArmy(actCreatures);
}

void Army::printArmy()
{
	int width = max(longestName(), 10);

	cout << "\n" << left << setw(width) << "Name"
		<< right << setw(width) << "Health"
		<< setw(width + 4) << "Strength"
		<< left << "    " << setw(width - 11) << "Type" << endl;


	cout << setfill('-') << setw(4 * width) << "" << endl
		<< setfill(' ');

	for (int i = 0; i < actCreatures; i++)
	{
		cout << ppCreatures[i]->to_String(longestName())
			<< "    " << printType_Damage(i) << endl;
	}
}

void Army::cleanArmy(const int size)
{
	if (ppCreatures != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			if (ppCreatures[i] != nullptr)
			{
				delete ppCreatures[i];
			}
		}
		delete ppCreatures;
		ppCreatures = nullptr;
		actCreatures = 0;
	}
}

void Army::allocateArmy(const int size)
{
	try
	{
		ppCreatures = new Creature * [size] { nullptr };
		for (int i = 0; i < size; i++)
		{
			int creatureType = rand() % NUM_TYPE_CREATURES;

			switch (creatureType)
			{
			case 0:
				ppCreatures[i] = new Demons();
				break;
			case 1:
				ppCreatures[i] = new SuperDemons();
				break;
			case 2:
				ppCreatures[i] = new Elves();
				break;
			}
		}
		actCreatures = size;
	}
	catch (bad_alloc)
	{
		cleanArmy(size);
		cout << "Failed to create the army. Army was not created." << endl;
	}
}

string Army::printType_Damage(const int index) const
{
	stringstream ss;
	ss << left << setw(11) << ppCreatures[index]->getType();
	return ss.str();
}

string Army::setName(const int numCreatures)
{
	return "Creature" + to_string(numCreatures);
}

int Army::setHealth()
{
	return (rand() % (RANGE_MAX_HEALTH - RANGE_MIN_HEALTH + 1)) + RANGE_MIN_HEALTH;
}

int Army::setStrength()
{
	return (rand() % (RANGE_MAX_STRENGTH - RANGE_MIN_STRENGTH + 1)) + RANGE_MIN_STRENGTH;
}

int Army::getNumArmy() const
{
	return actCreatures;
}

int Army::longestName() const
{
	int longest = ppCreatures[0]->getName().length();

	for (int i = 1; i < actCreatures; i++)
	{
		int nameLength = ppCreatures[i]->getName().length();
		if (nameLength > longest)
			longest = nameLength;
	}

	return longest;
}

int Army::getTotalHealth()
{
	int total = 0;

	for (int i = 0; i < actCreatures; i++)
	{
		total += ppCreatures[i]->getHealth();
	}

	return total;
}

int Army::getActCreatures() const
{
	return actCreatures;
}

Creature* Army::getCreature(int index) const
{
	if (index >= 0 && index < actCreatures)
		return ppCreatures[index];
	else
		return nullptr;
}