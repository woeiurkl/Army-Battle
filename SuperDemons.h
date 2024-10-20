#ifndef SUPERDEMONS_H
#define SUPERDEMONS_H

#include "Creature.h"
#include "Demons.h"

using namespace std;

class SuperDemons : public Demons
{
public:
	SuperDemons();

	SuperDemons(int n_health, int n_strength, string n_name);

	~SuperDemons();

	int getDamage();

	string getType() const override;

	string getName() const override;
};



#endif