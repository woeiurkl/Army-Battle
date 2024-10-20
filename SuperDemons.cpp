#include "SuperDemons.h"



SuperDemons::SuperDemons()
{

}

SuperDemons::SuperDemons(int n_health, int n_strength, string n_name)
{
	name = n_name;
	health = n_health;
	strength = n_strength;
}

SuperDemons::~SuperDemons()
{

}

int SuperDemons::getDamage()
{

	return Demons::getDamage() + Demons::getDamage();
}

string SuperDemons::getType() const
{
	return "SuperDemons";
}

string SuperDemons::getName() const
{
	return Creature::getName() + " the SuperDemon";
}