#pragma once
#include <iostream>
#include <cstdlib>
#include "Creature.h"

using namespace std;

class Elf : public Creature
{
public:
	Elf();
	Elf(int newStrength, int newHitpoints);
	int getDamage();
	string getSpecies();
};