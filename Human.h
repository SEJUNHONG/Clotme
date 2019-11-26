#pragma once
#include <iostream>
#include <cstdlib>
#include "Creature.h"

using namespace std;

class Human : public Creature
{
public:
	Human();
	Human(int newStrength, int newHitpoints);
	int getDamage();
	string getSpecies();
};