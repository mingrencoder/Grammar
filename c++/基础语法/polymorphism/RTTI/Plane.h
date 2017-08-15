#ifndef PLANE_H
#define PLANE_H

#include "Flyable.h"
class Plane : public Flyable
{
public:
	void carry();	
	virtual void takeoff();
	virtual void land();
};

#endif