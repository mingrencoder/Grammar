#include "Circle.h"
#include <iostream>
using namespace std;


Circle::Circle(double r)
{
	cout << "Circle" << endl;
	m_dR = r;
	m_oCenter = new Coordinate(3, 5);
}

Circle::~Circle()
{
	cout << "~Circle" << endl;
	delete m_oCenter;
	m_oCenter = NULL;
}

double Circle::calcArea()
{
	cout << "Circle-->calcArea" << endl;
	return 3.14 * m_dR * m_dR;
}