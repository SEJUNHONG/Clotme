#pragma once
#include <iostream>
#include <cstdlib>
#include "Creature.h"
#include "Demon.h"

using namespace std;

class Balrog : public Demon
{
public:
	Balrog();
	Balrog(int newStrength, int newHitpoints);
	int getDamage();
	string getSpecies();

};