#include "Creature.h"
#include "CreatureException.h"



Creature::Creature()
{
	name = "N/A";
	health = MIN_HEALTH;
	strength = MIN_STRENGTH;
}

Creature::Creature(const Creature& rhs)
{
	name = rhs.name;
	health = rhs.health;
	strength = rhs.strength;
}

Creature::Creature(int n_health, int n_strength, string n_name)
{
	name = n_name;
	health = n_health;
	strength = n_strength;
}

Creature::~Creature()
{
	name = "N/A";
	health = MIN_HEALTH;
	strength = MIN_STRENGTH;
}

void Creature::setCreature(std::string n_name, int n_health, int n_strength)
{
	try
	{
		if (n_name.length() < MIN_NAME)
			throw CreatureException(NAME_ERR);

		if (n_health < MIN_HEALTH)
			throw CreatureException(HEALTH_ERR);

		if (n_strength < MIN_STRENGTH)
			throw CreatureException(STRENGTH_ERR);

		name = n_name;
		health = n_health;
		strength = n_strength;
	}
	catch (CreatureException& ex)
	{
		cout << "Error: " << ex.what() << " Creature was not created." << endl;
	}
	catch (...)
	{
		cout << "Error: Unknown Error." << endl;
	}
}

int Creature::getHealth() const
{
	return health;
}

int Creature::getStrength() const
{
	return strength;
}

string Creature::getName() const
{
	return name;
}

int Creature::getDamage() const
{
	return (rand() % strength) + 1;
}

string Creature::to_String(int numWords) const
{
	int width = max(numWords, 10);
	stringstream ss;
	ss << left << setw(width) << getName() << right << setw(width) << health << setw(width + 4) << strength;
	return ss.str();
}

void Creature::setHealth(int newHealth)
{
	if (newHealth < MIN_HEALTH)
	{
		health = MIN_HEALTH;
	}
	else
	{
		health = newHealth;
	}
}

ostream& operator<<(std::ostream& out, const Creature& creature)
{
	string creatureString = creature.to_String(0);
	out << creatureString;
	return out;
}