#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#include "Creature.h"
#include "Human.h"
#include "Cyberdemon.h"
#include "Balrogs.h"
#include "Elf.h"

using namespace std;

void battleArena(Creature &Creature1, Creature &Creature2);

int main()
{
	Human h(50, 50);
	Elf e(50, 50);
	Cyberdemon c(50, 1000);
	Balrog b(50, 1000);

	battleArena(c, b);

	system ("pause");
	return 0;
}

void battleArena(Creature &Creature1, Creature &Creature2)
{
	int Creature1_HP = 1000, Creature2_HP = 1000, Creature1_Damage = 0, Creature2_Damage = 0;

	while ((Creature1_HP > 0) && (Creature2_HP > 0)) {

		Creature1_Damage = Creature1.getDamage();
		Creature2_Damage = Creature2.getDamage();

		cout << "Damage inflicted by " << Creature1.getSpecies() << ": " << Creature1_Damage << endl;
		cout << "Damage inflicted by " << Creature2.getSpecies() << ": " << Creature2_Damage << endl;
		cout << "\n"<<endl;

		Creature1_HP = Creature1_HP - Creature2_Damage;
		if (Creature1_HP <= 0)
			Creature1_HP = 0;
		cout << Creature1.getSpecies() <<" HP : " << Creature1_HP << endl;

		Creature2_HP = Creature2_HP - Creature1_Damage;
		if (Creature2_HP <= 0)
			Creature2_HP = 0;
		cout << Creature2.getSpecies() << " HP : " << Creature2_HP << endl;

		Creature1.setHitpoints(Creature1_HP);
		Creature2.setHitpoints(Creature2_HP);
		cout << endl;
	}

	if ((Creature1_HP <= 0) && (Creature2_HP > 0)) {

		cout << "winner : " << Creature2.getSpecies() <<endl;
	}

	if ((Creature1_HP > 0) && (Creature2_HP <= 0)) {

		cout << "winner : " << Creature1.getSpecies() << endl;

	}
	cout << endl;

}
