#ifndef HELPER_H
#define HELPER_H

using namespace std;

#include <iostream>
#include <ctime>
#include <limits>

#include "Creature.h"
#include "Demons.h"
#include "SuperDemons.h"
#include "Elves.h"
#include "Army.h"

const string INPUT_ERR = "You entered an invalid number. Please try again.\n";
const int numArmy = 2;

int armySize();
void mainMenu(Army& Army1, Army& Army2);
void printMainMenu(int& userInput);
void print(Army& userArmy, int numOfArmy);
void invalidInput();
void printBattleResult(Army& Army1, Army& Army2);
void battleArmy(const Army& army1, const Army& army2);
void battleCreatures(Creature* attacker, Creature* defender);

#endif