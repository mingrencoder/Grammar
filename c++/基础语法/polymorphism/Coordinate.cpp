#include <iostream>
#include <iostream>
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate(double x, double y)
{
	m_iX = x;
	m_iY = y;
	cout << "Coordinate" << endl;
}
Coordinate::~Coordinate()
{
	cout << "~Coordinate" << endl;
}