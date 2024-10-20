#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;



const std::string UNKNOWN_ERR = "Unknown Error";
const std::string NAME_ERR = "Creature Name is less than the name length requirement characters.";
const std::string HEALTH_ERR = "Health cannot be negative.";
const std::string STRENGTH_ERR = "Strength cannot be negative.";
const int MIN_NAME = 3;
const int MIN_HEALTH = 0;
const int MIN_STRENGTH = 0;



class Creature
{
protected:
	int health, strength;
	string name;

public:
	Creature();

	Creature(const Creature& rhs);

	Creature(int n_health, int n_strength, string n_name);

	virtual ~Creature();



	void setCreature(std::string n_name, int n_health, int n_strength);

	int getHealth() const;

	int getStrength() const;

	virtual string getName() const;

	virtual int getDamage() const;

	string to_String(int numWords) const;

	void setHealth(int newHealth);



	friend ostream& operator<<(std::ostream& out, const Creature& creature);
	virtual string getType() const = 0;
};



#endif