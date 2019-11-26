#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Balrogs.h"

using namespace std;

Balrog::Balrog()
{
	setStrength(10);
	setHitpoints(10);
}

Balrog::Balrog(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints)
{

}

string Balrog::getSpecies()
{
	return "Balrog";
}

int Balrog::getDamage()
{
	int damage;
	int damage2;
	Demon Balrog(getStrength(), getHitpoints());

	//int damage = Demon::getDamage();

	damage = Balrog.getDamage();
	damage2 = (rand() % getStrength()) + 1;

	cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!\n";

	damage = damage + damage2;
	return damage;
}