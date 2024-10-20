#include "Elves.h"



Elves::Elves()
{

}

Elves::Elves(int n_health, int n_strength, string n_name)
{
	name = n_name;
	health = n_health;
	strength = n_strength;
}

Elves::~Elves()
{

}

int Elves::getDamage()
{
	int damage = Creature::getDamage();
	if ((rand() % E_CHANCE) == 0)
	{
		damage *= E_DAMAGE;
	}

	return damage;
}

string Elves::getType() const
{
	return "Elves";
}

string Elves::getName() const
{
	return Creature::getName() + " the Elf";
}