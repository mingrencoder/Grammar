#ifndef RECT_H
#define RECT_H

#include "Shape.h"
class Rect : public Shape
{
public:
	Rect(int m_dWidth, int m_dHeight);
	virtual ~Rect();
	virtual double calcArea();
protected:
	double m_dWidth;
	double m_dHeight;
};

#endif