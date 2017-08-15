#include <iostream>
#include "Soldier.h"
using namespace std;

Soldier::Soldier()
{
	m_strName = "SoldierName";
	cout << "Soldier()" << endl;
}

Soldier::~Soldier()
{
	cout << "~Soldier()" << endl;
}

void Soldier::fight()
{
	cout << "Soldier -- fight()" << endl;
}

void Soldier::eat()
{
	cout << "Soldier -- eat()" << endl;
}