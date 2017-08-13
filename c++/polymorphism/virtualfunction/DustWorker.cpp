#include <iostream>
using namespace std;
#include "DustWorker.h"

DustWorker::DustWorker(string name, int age):Worker(name, age)
{
	cout << "DustWorker" << endl;
}

void DustWorker::work()
{
	cout << m_strName << ": " << "DustWorker:work" << endl;
}