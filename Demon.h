#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Demon.h"
#include "Creature.h"

using namespace std;

class Demon : public Creature
{
public:
	Demon() ;
	Demon(int newStrength, int newHitpoints);
	virtual int getDamage();
	virtual string getSpecies();
};