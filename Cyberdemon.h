#pragma once

#include <iostream>
#include <cstdlib>
#include "Creature.h"
#include "Demon.h"

using namespace std;

class Cyberdemon : public Demon
{
public:
	Cyberdemon();
	Cyberdemon(int newStrength, int newHitpoints);
	int getDamage();
	string getSpecies();
};