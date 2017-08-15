#include <iostream>
#include "stdlib.h"
#include "MyStack.cpp"

using namespace std;

/********************************************/
/*
栈类
*/
/********************************************/

int main(void)
{
	MyStack *m = new MyStack(5);
	if(m->stackEmpty())
	{
		cout << "栈为空" << endl;
	}

	m->push('A');
	m->push('B');

	cout << m->stackLength() << endl;
	m->clearStack();

	m->push('C');
	m->push('D');
	m->push('E');
	char a = 'T';
	m->pop(a);
	cout << "将栈顶元素赋值给了a：" << a << endl;

	m->push('F');

	if(m->stackFull())
	{
		cout << "栈为满" << endl;
	}
	m->stackTraverse(true);

	return 0;
}