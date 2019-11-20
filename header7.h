#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Organism 
{
private:
	int cap=0;
	int cnt=0 ;
	int acnt = 0;
	int dcnt1 = 0, dcnt2 = 0;

public: 
	virtual void print() { cout << " "; };
	char kind() { return ' '; };
	virtual void move(int i, int j, Organism * cell[]) { return; };
	virtual int get_cap() { return cap; };
	virtual void add_cap() {  };
	virtual void reset_cap() {  };
	virtual void count() { cnt++; };
	virtual int get_count() { return cnt; };
	virtual int get_acnt() { return acnt; };
	virtual void reset_acnt() {  };
	virtual void breed(int i, int j, Organism*cell[]) { return;  };
	virtual void Acnt() {};
	//virtual void Antcnt() { antcnt++; };
	//virtual int get_antcnt() { return antcnt; };
	virtual void Dcnt1() {  };
	virtual int get_dcnt1() { return dcnt1; };
	virtual void reset_dcnt1() {  };
	//virtual void Doocnt() { doocnt++; };
	//virtual int get_doocnt() { return doocnt; };
	virtual void starve(int i, int j, Organism*cell[]) { return; };
	virtual void Dcnt2() { dcnt2++; };
	virtual int get_dcnt2() { return dcnt2; };
	virtual void reset_dcnt2() { };
	//virtual void mAntcnt() { antcnt--; };
	//virtual void mDoocnt() { doocnt--; };
};

class Ant : public Organism
{
private:
	int cap=0;
	int acnt = 0;

public:
	void print();
	void move(int i, int j, Organism* cell[]);
	char kind() { return 'O'; };
	int get_cap() { return cap; };
	void reset_cap() { cap = 0; };
	void add_cap() { cap++; };
	void Acnt() { acnt++; };
	int get_acnt() { return acnt; };
	void reset_acnt() { acnt = 0; };
	void breed(int i, int j, Organism*cell[]);
	//void Antcnt() { antcnt++; };
	//void mAntcnt() { antcnt--; };
	//int get_antcnt() { return antcnt; };

};

class Doodlebug : public Organism
{
private:
	int cap = 0;
	int dcnt1 = 0, dcnt2 = 0;
	int cnt = 0;

public:
	void print();
	char kind() { return 'X'; };
	void move(int i, int j, Organism * cell[]);
	int get_cap() { return cap; };
	void reset_cap() { cap = 0; };
	void add_cap() { cap++; };
	int get_count() { return cnt; };
	void count() { cnt++; };
	void Dcnt1() { dcnt1++; };
	int get_dcnt1() { return dcnt1; };
	void reset_dcnt1() { dcnt1 = 0; };
	void breed(int i, int j, Organism*cell[]);
	//void Doocnt() { doocnt++; };
	//int get_doocnt() { return doocnt; }
	void starve(int i, int j, Organism*cell[]);
	void Dcnt2() { dcnt2++; };
	int get_dcnt2() { return dcnt2; };
	void reset_dcnt2() { dcnt2 = 0; };
	//void mDoocnt() { doocnt--; };

};