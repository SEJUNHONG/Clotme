#pragma once
#include <iostream>
#include <cstdlib>
#include "Demon.h"
#include "Creature.h"

using namespace std;

Demon::Demon()
{
	setStrength(10);
	setHitpoints(10);
}

Demon::Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints)
{

}

int Demon::getDamage()
{
	int damage = Creature::getDamage();
	cout  <<getSpecies()<<" attacks for " << damage << " points!" << endl;
	
	if ((rand() % 100) < 5)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 additional damage points!" << endl;
	}
	return damage;
}

string Demon::getSpecies()
{
	return "Demon";
}