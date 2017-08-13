#include <iostream>
#include "Person.h"
using namespace std;

Person::Person():m_strName("PersonName")
{
	cout << "Person()" << endl;
}

Person::~Person()
{
	cout << "~Person()" << endl;
}

void Person::eat()
{
	m_strName = "Tony";
	m_iAge = 10;
	cout << "Person -- eat()" << endl;
}

void Person::play()
{
	cout << m_strName << endl;
}