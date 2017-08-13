#include <iostream>
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
	cout << "构造函数Coordinate()  " <<  m_iX << ","<< m_iY << endl;
}
Coordinate::~Coordinate()
{
	cout << "析构函数~Coordinate()  " <<  m_iX << ","<< m_iY << endl;
}

void Coordinate::setX(int x)
{
	m_iX = x;
}

int Coordinate::getX() const
{
	return m_iX;
}
void Coordinate::setY(int y)
{
	m_iY = y;
}
int Coordinate::getY() const
{
	return m_iY;
}

void Coordinate::printInfo() const
{
	cout << "常成员函数不能改变数据的值" << endl;
}
