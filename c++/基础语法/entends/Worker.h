// #include "Person.h"

class Worker:protected Person
{
public:
	Worker();
	void work();
	void printInfo();
protected:
	int m_iSalary;
};