#ifndef ARMY_H
#define ARMY_H

#include "Creature.h"
#include "Demons.h"
#include "SuperDemons.h"
#include "Elves.h"

using namespace std;



const int RANGE_MIN_HEALTH = 20;
const int RANGE_MAX_HEALTH = 80;
const int RANGE_MIN_STRENGTH = 40;
const int RANGE_MAX_STRENGTH = 120;
const int NUM_TYPE_CREATURES = 3;



class Army
{
private:
	int actCreatures = 0;
	Creature** ppCreatures = nullptr;

public:
	Army();

	explicit Army(const int size);

	Army(const Army& rhs);

	~Army();



	void printArmy();

	void cleanArmy(const int size);

	void allocateArmy(const int size);

	string printType_Damage(const int index) const;

	string setName(const int numCreature);

	int setHealth();

	int setStrength();

	int getNumArmy() const;

	int longestName() const;

	int getTotalHealth();

	int getActCreatures() const;

	Creature* getCreature(int index) const;
};



#endif