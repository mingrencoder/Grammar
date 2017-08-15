#include <iostream>
#include "stdlib.h"
#include "MyStack.h"
#include "Coordinate.cpp"

using namespace std;

/********************************************/
/*
栈类 类模板
*/
/********************************************/

int main(void)
{
	MyStack<Coordinate> *m = new MyStack<Coordinate>(5);
	m->push(Coordinate(1,2));
	m->push(Coordinate(3,4));


	MyStack<char> *m1 = new MyStack<char>(5);
	m1->push('A');
	m1->push('B');
	m1->push('C');

	cout << m->stackLength() << endl;

	m->stackTraverse(true);

	cout << "-------" << endl;
	cout << m1->stackLength() << endl;
	m1->stackTraverse(true);

	return 0;
}