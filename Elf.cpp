#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Elf.h"

using namespace std;

Elf::Elf()
{
	setStrength(10);
	setHitpoints(10);
}

Elf::Elf(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints)
{

}

int Elf::getDamage()
{
	int damage = Creature::getDamage();
	cout << "Elf attacks for " << damage << " points!" << endl;

	if ((rand() % 10) == 0)
	{
		cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
		damage = damage * 2;
	}
	return damage;
}

string Elf::getSpecies()
{
	return "Elf";
}