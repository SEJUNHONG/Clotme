#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Creature
{
private:
	//int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
	int strength; // ���� �� �ִ� �ջ��� ��
	int hitpoints; // ��ƿ �� �ִ� �ջ��� ��

public:
	Creature(); // human, 10 strength, 10 hit points�� �ʱ�ȭ�Ѵ�.
	Creature(int newStrength, int newHit); // ������ new type, strength, hit points�� �ʱ�ȭ�Ѵ�. 
	// ���� type, strength, hit points�� ���� ������ accessor�� mutator �Լ��� �߰��Ѵ�.
	virtual string getSpecies(); // ������ ������ ��ȯ
	virtual int getDamage(); // �� ������ �������� �������� �������� �ջ� ���� ��ȯ�Ѵ�.
	int getStrength();
	int getHitpoints();
	void setStrength(int newStrength);
	void setHitpoints(int newHitpoints);
};