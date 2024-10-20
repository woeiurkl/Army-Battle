#include "Demons.h"



Demons::Demons()
{

}

Demons::Demons(int n_health, int n_strength, string n_name)
{
	name = n_name;
	health = n_health;
	strength = n_strength;
}

Demons::~Demons()
{

}

int Demons::getDamage() const
{
	return Creature::getDamage() + (((rand() % 100) < D_CHANCE) ? D_DAMAGE : 0);
}

string Demons::getType() const
{
	return "Demons";
}

std::string Demons::getName() const
{
	return Creature::getName() + " the Demon";
}