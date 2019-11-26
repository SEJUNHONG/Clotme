#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Cyberdemon.h"

using namespace std;

Cyberdemon::Cyberdemon()
{
	setStrength(10);
	setHitpoints(10);
}

Cyberdemon::Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints)
{
	
}

string Cyberdemon::getSpecies()
{
	return "Cyberdemon";
}

int Cyberdemon::getDamage()
{
	int damage = Demon::getDamage();

	return damage;
}