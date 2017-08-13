#include <iostream>
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

void Coordinate::printInfo()
{
	cout << "(" << m_iX << "," << m_iY << ")" << endl;
}

ostream &operator<<(ostream &out, Coordinate &coor)
{
	out << "(" << coor.m_iX << "," << coor.m_iY << ")" << endl;
	return out;
}