#ifndef ELVES_H
#define ELVES_H

#include "Creature.h"

using namespace std;



const int E_CHANCE = 10;
const int E_DAMAGE = 2;



class Elves : public Creature
{
public:
	Elves();

	Elves(int n_health, int n_strength, string n_name);

	virtual ~Elves();

	int getDamage();

	string getType() const override;

	string getName() const override;
};



#endif 