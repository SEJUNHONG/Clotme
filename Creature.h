#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Creature
{
private:
	//int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
	int strength; // 가할 수 있는 손상의 양
	int hitpoints; // 버틸 수 있는 손상의 양

public:
	Creature(); // human, 10 strength, 10 hit points로 초기화한다.
	Creature(int newStrength, int newHit); // 종족을 new type, strength, hit points로 초기화한다. 
	// 또한 type, strength, hit points에 대해 적절한 accessor와 mutator 함수를 추가한다.
	virtual string getSpecies(); // 종족의 종류를 반환
	virtual int getDamage(); // 한 라운드의 전투에서 가해지는 종족들의 손상 값을 반환한다.
	int getStrength();
	int getHitpoints();
	void setStrength(int newStrength);
	void setHitpoints(int newHitpoints);
};