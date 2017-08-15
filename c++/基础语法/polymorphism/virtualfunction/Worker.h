#ifndef WORKER_H
#define WORKER_H

#include "Person.h"
class Worker : public Person
{
public:
	Worker(string name, int age);
private:
	int m_iAge;
};

#endif