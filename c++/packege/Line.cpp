#include <iostream>
#include "Line.h"
using namespace std;

Line::Line(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4):m_coorA(x1, y1), m_coorB(x2, y2)
{
	cout << "⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇"<< endl;
	//实例化对象，所以下面需要进行手动销毁
	m_pCoorA = new Coordinate(x3, y3);
	m_pCoorB = new Coordinate(x4, y4);
	cout << "构造函数Line()" << endl;
	cout << "⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆" << endl;
}

Line::~Line()
{
	delete m_pCoorA;
	m_pCoorA = NULL;
	delete m_pCoorB;
	m_pCoorB = NULL;
	cout << "析构函数~Line()" << endl;
}

void Line::setA(int x, int y)
{
	// m_coorA.setX(x);
	// m_coorA.setY(y);
}

void Line::setB(int x, int y)
{
	m_coorB.setX(x);
	m_coorB.setY(y);
}

void Line::printInfo()
{
	cout << "⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇"<< endl;
	cout << "printInfo" << endl;
	cout << "(" << m_coorA.getX() << "," <<  m_coorA.getY() << ")" << endl;
	cout << "(" << m_coorB.getX() << "," <<  m_coorB.getY() << ")" << endl;
	cout << "⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆" << endl;
}

void Line::printInfo() const
{
	cout << "⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇"<< endl;
	cout << "const printInfo" << endl;
	cout << "(" << m_coorA.getX() << "," <<  m_coorA.getY() << ")" << endl;
	cout << "(" << m_coorB.getX() << "," <<  m_coorB.getY() << ")" << endl;
	cout << "⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆" << endl;
}

void Line::printPointerInfo()
{
	cout << "⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇"<< endl;
	cout << "(" << m_pCoorA->getX() << "," <<  m_pCoorA->getY() << ")" << endl;
	cout << "(" << m_pCoorB->getX() << "," <<  m_pCoorB->getY() << ")" << endl;
	cout << "⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆" << endl;
}