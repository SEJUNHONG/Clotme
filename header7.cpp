#include <iostream>
#include <cstdlib>
#include <cstring>

#include "header.h"
using namespace std;


void Ant:: print()
{
	cout << "O";
}

void Ant::move(int i ,int j, Organism * cell[])
{
	int point = 0;
	point = rand() % 4;
	Organism * t1;
	Organism * t2;
	if (point == 0)  // ╩С
	{ 
		if (cell[20 * i + j]->get_cap()==0 && cell[20 * (i - 1) + j] ->kind() == ' ' && i != 0)
		{
			t1 = cell[20 * (i - 1) + j];
			t2 = cell[20 * i + j];
			cell[20 * (i - 1) + j] = t2;
			cell[20 * i + j] = t1;
			cell[20 * (i - 1) + j]->add_cap();
			cell[20 * (i - 1) + j]->Acnt();
		}
	}
	else if (point == 1) // го
	{
		if (cell[20 * i + j]->get_cap() == 0 && cell[20 * (i + 1) + j]->kind() == ' ' && i != 19)
		{
			t1 = cell[20 * (i + 1) + j];
			t2 = cell[20 * i + j];
			cell[20 * (i + 1) + j] = t2;
			cell[20 * i + j] = t1;
			cell[20 * (i + 1) + j]->add_cap();
			cell[20 * (i + 1) + j]->Acnt();
		}
	}
	else if (point == 2) // аб
	{
		if (cell[20 * i + j]->get_cap() == 0 && cell[20 * i + j - 1]->kind() == ' ' && j != 0)
		{
			t1 = cell[20 * i + j - 1];
			t2 = cell[20 * i + j];
			cell[20 * i + j - 1] = t2;
			cell[20 * i + j] = t1;
			cell[20 * i + j - 1]->add_cap();
			cell[20 * i + j - 1]->Acnt();
		}
	}
	else if (point == 3) // ©Л
	{
		if (cell[20 * i + j]->get_cap() == 0 && cell[20 * i + j + 1]->kind() == ' ' && j != 19)
		{
			t1 = cell[20 * i + j+1];
			t2 = cell[20 * i + j];
			cell[20 * i + j+1] = t2;
			cell[20 * i + j] = t1;
			cell[20*i+j+1]->add_cap();
			cell[20 * i + j+1]->Acnt();
		}
	}
}

void Ant::breed(int i, int j, Organism*cell[])
{
	if (cell[20*i+j]->get_acnt() == 3)
	{
		if (cell[20 * (i + 1) + j]->kind() == ' ' && i!=19)
		{
			cell[20 * (i + 1) + j] = new Ant();
		}
		if (cell[20 * (i - 1) + j]->kind() == ' ' && i!=0)
		{
			cell[20 * (i - 1) + j] = new Ant();
		}
		if (cell[20 * i + 1 + j]->kind() == ' ' && j!=19)
		{
			cell[20 * i + 1 + j] = new Ant();
		}
		if (cell[20 * i - 1 + j]->kind() == ' '&&j!=0)
		{
			cell[20 * i - 1 + j] = new Ant();
		}
		cell[20 * i + j]->reset_acnt();
	}
}

void Doodlebug::print()
{
	cout << "X";
}

void Doodlebug::move(int i, int j, Organism * cell[])
{
	int point = 0;
	point = rand() % 4;
	Organism * t1;
	Organism * t2;

	if (cell[20 * i + j]->get_cap() == 0 && cell[20 * (i - 1) + j] ->kind() == 'O')
	{
		t1 = cell[20 * (i - 1) + j];
		t2 = cell[20 * i + j];
		cell[20 * (i - 1) + j] = new Doodlebug;
		cell[20 * i + j] = new Organism;
		cell[20 * (i - 1) + j]->add_cap();
		cell[20 * (i - 1) + j]->count();
		cell[20 * (i - 1) + j]->Dcnt1();
		cell[20 * (i - 1) + j]->reset_dcnt2();
	}
	else if (cell[20 * i + j]->get_cap() == 0 && cell[20 * (i + 1) + j] ->kind() == 'O')
	{
		t1 = cell[20 * (i + 1) + j];
		t2 = cell[20 * i + j];
		cell[20 * (i + 1) + j] = new Doodlebug;
		cell[20 * i + j] = new Organism;
		cell[20 * (i + 1) + j]->add_cap();
		cell[20 * (i + 1) + j]->count();
		cell[20 * (i + 1) + j]->Dcnt1();
		cell[20 * (i + 1) + j]->reset_dcnt2();
	}
	else if (cell[20 * i + j]->get_cap() == 0 && cell[20 * i + j - 1] ->kind() == 'O')
	{
		t1 = cell[20 * i + j - 1];
		t2 = cell[20 * i + j];
		cell[20 * i + j - 1] = new Doodlebug;
		cell[20 * i + j] = new Organism;
		cell[20 * i + j - 1]->add_cap();
		cell[20 * i + j - 1]->count();
		cell[20 * i - 1 + j]->Dcnt1();
		cell[20 * i - 1 + j]->reset_dcnt2();
	}
	else if (cell[20 * i + j]->get_cap() == 0 && cell[20 * i + j + 1] ->kind() == 'O')
	{
		t1 = cell[20 * i + j + 1];
		t2 = cell[20 * i + j];
		cell[20 * i + j + 1] = new Doodlebug;
		cell[20 * i + j] = new Organism;
		cell[20 * i + j + 1]->add_cap();
		cell[20 * i + 1 + j]->count();
		cell[20 * i + 1 + j]->Dcnt1();
		cell[20 * i + 1 + j]->reset_dcnt2();
	}
	else
	{
		if (point == 0)  // ╩С
		{
			if (cell[20 * i + j]->get_cap() == 0 && cell[20 * (i - 1) + j] ->kind() != 'X' && i != 0)
			{
				t1 = cell[20 * (i - 1) + j];
				t2 = cell[20 * i + j];
				cell[20 * (i - 1) + j] = t2;
				cell[20 * i + j] = t1;
				cell[20 * (i - 1) + j]->add_cap();
				cell[20 * (i - 1) + j]->Dcnt1();
				cell[20 * (i - 1) + j]->Dcnt2();
			}
		}
		else if (point == 1) // го
		{
			if (cell[20 * i + j]->get_cap() == 0 && cell[20 * (i + 1) + j] ->kind() != 'X' && i != 19)
			{
				t1 = cell[20 * (i + 1) + j];
				t2 = cell[20 * i + j];
				cell[20 * (i + 1) + j] = t2;
				cell[20 * i + j] = t1;
				cell[20 * (i + 1) + j]->add_cap();
				cell[20 * (i + 1) + j]->Dcnt1();
				cell[20 * (i + 1) + j]->Dcnt2();
			}
		}
		else if (point == 2) // аб
		{
			if (cell[20 * i + j]->get_cap() == 0 && cell[20 * i + j - 1] ->kind() != 'X' && j != 0)
			{
				t1 = cell[20 * i + j - 1];
				t2 = cell[20 * i + j];
				cell[20 * i + j - 1] = t2;
				cell[20 * i + j] = t1;
				cell[20 * i + j - 1]->add_cap();
				cell[20 * i - 1 + j]->Dcnt1();
				cell[20 * i - 1 + j]->Dcnt2();
			}
		}
		else if (point == 3) // ©Л
		{
			if (cell[20 * i + j]->get_cap() == 0 && cell[20 * i + j + 1] ->kind() != 'X' && j != 19)
			{
				t1 = cell[20 * i + j + 1];
				t2 = cell[20 * i + j];
				cell[20 * i + j + 1] = t2;
				cell[20 * i + j] = t1;
				cell[20 * i + j + 1]->add_cap();
				cell[20 * i + 1 + j]->Dcnt1();
				cell[20 * i + 1 + j]->Dcnt2();
			}
		}
	}
}

void Doodlebug::breed(int i, int j, Organism*cell[])
{
	if (cell[20 * i + j]->get_dcnt1() == 8)
	{
		if (cell[20 * (i + 1) + j]->kind() == ' ' && i!=19)
		{
			cell[20 * (i + 1) + j] = new Doodlebug();
		}
		if (cell[20 * (i - 1) + j]->kind() == ' ' && i!=0)
		{
			cell[20 * (i - 1) + j] = new Doodlebug();
		}
		if (cell[20 * i + 1 + j]->kind() == ' '&&j!=19)
		{
			cell[20 * i + 1 + j] = new Doodlebug();
		}
		if (cell[20 * i - 1 + j]->kind() == ' '&&j!=0)
		{
			cell[20 * i - 1 + j] = new Doodlebug();
		}
		cell[20 * i + j]->reset_dcnt1();
	}
}

void Doodlebug::starve(int i, int j, Organism*cell[])
{
	if (cell[20*i+j]->get_dcnt2() == 10)
	{
		if (cell[20*i+j]->get_count() == 0)
		{
			cell[20 * i + j] = new Organism();
		}
	}
}