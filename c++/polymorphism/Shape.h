// 宏定义：为了避免重复包含
#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	Shape();
	virtual ~Shape();
	virtual double calcArea();
};

#endif