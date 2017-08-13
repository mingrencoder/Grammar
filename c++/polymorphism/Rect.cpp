#include "Rect.h"
#include <iostream>
using namespace std;


Rect::Rect(int width, int height)
{
	m_dWidth = width;
	m_dHeight = height;
	cout << "Rect" << endl;
}

Rect::~Rect()
{
	cout << "~Rect" << endl;
}

double Rect::calcArea()
{
	cout << "Rect-->calcArea" << endl;
	return m_dWidth * m_dHeight;
}