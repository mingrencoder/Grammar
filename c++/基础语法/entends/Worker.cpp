#include <iostream>
#include "Worker.h"
using namespace std;

Worker::Worker()
{
	cout << "Worker()" << endl;
}

void Worker::work()
{
	// m_strName = "James";
	// m_iAge = 18;
	cout << "Workder -- work()" << endl;
}

void Worker::printInfo()
{
	// cout << "m_strName=" << m_strName << "  m_iAge=" << m_iAge << "  m_iSalary=" << m_iSalary << endl;
}