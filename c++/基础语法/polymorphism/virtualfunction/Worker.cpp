#include <iostream>
#include "Worker.h"
using namespace std;

Worker::Worker(string name, int age):Person(name), m_iAge(age)
{
	cout << "Worker" << endl;
}
