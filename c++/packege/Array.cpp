#include <iostream>
#include "Array.h"
using namespace std;


Array::Array(int len)
{
	this->len = len;
	cout << "Array" << endl;
}

Array::~Array()
{
	cout << "~Array" << endl;
}

void Array::setLen(int len)
{
	this->len = len;
}

int Array::getLen()
{
	return this->len;
}

Array& Array::getThis()
{
	return *this;
}

Array* Array::getThisPointer()
{
	return this;
}