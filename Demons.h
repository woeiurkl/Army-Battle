#ifndef DEMONS_H
#define DEMONS_H

#include "Creature.h"

using namespace std;



const int D_CHANCE = 12;
const int D_DAMAGE = 45;



class Demons : public Creature
{
public:
	Demons();

	Demons(int n_health, int n_strength, string n_name);

	virtual ~Demons();

	int getDamage() const override;

	string getType() const override;

	string getName() const override;
};



#endif