#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Human.h"

using namespace std;


Human::Human()
{
	setStrength(10);
	setHitpoints(10);
}

Human::Human(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints)
{

}

int Human::getDamage()
{
	int damage = Creature::getDamage();
	cout << "Human attacks for " << damage << " points!" << endl;
	
	return damage;
}

string Human::getSpecies()
{
	return "Human";
}