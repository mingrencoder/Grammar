#ifndef DUSTWORKER_H
#define DUSTWORKER_H

#include "Worker.h"
class DustWorker : public Worker
{
public:
	DustWorker(string name, int age);
	virtual void work();
};

#endif