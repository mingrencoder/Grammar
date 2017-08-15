#include <iostream>
#include "stdlib.h"
#include "MyQueue.cpp"

using namespace std;

/********************************************/
/*
实现环形队列
*/
/********************************************/

int main(void)
{
	MyQueue m(4);
	m.enQueue(10);
	m.enQueue(20);
	m.enQueue(30);
	m.enQueue(40);
	cout << m.queueFull() << endl; // 1代表已满
	int e = 2;
	m.deQueue(e);
	// cout << e << endl;
	// m.deQueue(e);
	// cout << e << endl;
	m.enQueue(50);
	m.queueTraverse();
	
	return 0;
}