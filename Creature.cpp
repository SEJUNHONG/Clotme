#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Creature.h"
using namespace std;

Creature::Creature()
{
	strength = 10;
	hitpoints = 10;
}

Creature::Creature(int newStrength, int newHit)
{
	strength = newStrength;
	hitpoints = newHit;
}

string Creature::getSpecies()
{
	/*
	switch (type)
	{
	case 0: return "Human";
	case 1: return "Cyberdemon";
	case 2: return "Balrog";
	case 3: return "Elf";
	}*/

	return "Creature";
}

int Creature::getDamage()
{
	int damage;  // 모든 종족이 가하는 손상은 strength 내의 임의의 수이다.

	damage = (rand() % strength) + 1;

	/*
	cout << getSpecies() << "attacks for" << damage << " points!" << endl;

	if ((type == 2) || (type == 1)) // Demon은 5%의 기회로 50의 손상을 가할 수 있다. 
	{
		if ((rand() % 100) < 5)
		{
			damage = damage + 50;
			cout << "Demonic attack inflicts 50" << damage << " additional damage points!" << endl;
		}
	}

	if (type == 3) // Elves는 10%의 기회로 2배의 마법 손상을 가할 수 있다. 
	{
		if ((rand() % 10) == 0)
		{
			cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
			damage = damage * 2;
		}
	}

	if (type == 2) // Balrogs는 빠르므로 2번 공격한다.
	{
		int damage2 = (rand() % strength) + 1;
		cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
		damage = damage + damage2;
	}
	*/
	return damage;

}

int Creature::getStrength()
{
	return strength;
}

int Creature::getHitpoints()
{
	return hitpoints;
}

void Creature::setStrength(int newStrength)
{
	strength = newStrength;
}

void Creature::setHitpoints(int newHitpoints)
{
	hitpoints = newHitpoints;
}