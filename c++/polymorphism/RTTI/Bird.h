// #ifndef BIRD.H
// #define BIRD.H

#include "Flyable.h"
class Bird : public Flyable
{
public:
	void froaging();	
	virtual void takeoff();
	virtual void land();
};

// #endif