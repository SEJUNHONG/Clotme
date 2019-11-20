#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include "header.h"
using namespace std;

int main(void)
{
	Organism * cell[400];

	int i = 0, j = 0;
	int m = 0, n = 0;
	int ent = 0;
	int point;
	int antcnt = 0, doocnt = 0;
	
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cell[20 * i + j] = new Organism;
		}
	}

	for (int a = 0; a < 100; a++)
	{
		m = rand() % 20;
		n = rand() % 20;
		if (cell[20 * m + n]==NULL)
		{
			cell[20 * m + n] = new Ant;
			antcnt++;
		}
		else
		{
			m = rand() % 20;
			n = rand() % 20;
			cell[20 * m + n] = new Ant;
			antcnt++;
		}
	}
	m = 0;
	n = 0;
	for (int d = 0; d < 5; d++)
	{
		m = rand() % 20;
		n = rand() % 20;
		if (cell[20 * m + n] == NULL)
		{
			cell[20 * m + n] = new Doodlebug;
			doocnt++;
		}
		else
		{
			m = rand() % 20;
			n = rand() % 20;
			cell[20 * m + n] = new Doodlebug;
			doocnt++;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cell[20 * i + j]->print();
			cout << " l ";
		}
		cout << "\n";
	}
	//cout << "현재 개미의 개수: " << antcnt << endl;
	//cout << "현재 개미귀신의 개수: " << doocnt << endl;
	
	while (antcnt+doocnt!=400)
	{
		cout << "\n";
		
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				cell[20 * i + j]->move(i ,j,cell);
			}
		}

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				cell[20 * i + j]->breed(i, j, cell);
			}
		}

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				cell[20 * i + j]->starve(i, j, cell);
			}
		}

		
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				cell[20 * i + j]->print();
				cell[20 * i + j]->reset_cap();
				cout << " l ";
			}
			cout << "\n";
		}

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (cell[20 * i + j]->kind() == 'O')
					antcnt++;
				if (cell[20 * i + j]->kind() == 'X')
					doocnt++;
			}
		}
		//cout << "현재 개미의 개수: " << antcnt << endl;
		//cout << "현재 개미귀신의 개수: " << doocnt << endl;
		//cout << "잡아먹힌 개미의 수 : " << cell[20 * i + j]->get_count() << endl;

		cin >> ent;
	}

	return 0;
}