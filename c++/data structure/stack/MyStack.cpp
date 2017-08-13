#include "MyStack.h"
#include <iostream>

using namespace std;

MyStack::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new char[size];
	clearStack();
}

MyStack::~MyStack()
{
	delete[] m_pBuffer;
	m_pBuffer = NULL;
}

bool MyStack::stackEmpty()
{
	return m_iTop == 0 ? true : false;
}

bool MyStack::stackFull()
{
	return m_iTop == m_iSize ? true : false;
}

void MyStack::clearStack()
{
	m_iTop = 0;
}

int MyStack::stackLength()
{
	return m_iTop;
}

bool MyStack::push(char elem)
{
	if(stackFull()){
		return false;
	}
	m_pBuffer[m_iTop] = elem;
	m_iTop++;		//指向的是下一个要入栈的位置
	return true;
}

bool MyStack::pop(char &elem)
{
	if(stackEmpty()){
		return false;
	}
	m_iTop--;
	elem = m_pBuffer[m_iTop];
	return true;
}

void MyStack::stackTraverse(bool isFromBottom)
{
	if(isFromBottom){
		for(int i=0; i<m_iTop; i++)
		{
			cout << m_pBuffer[i] << ",";
		}
	}
	else
	{
		// 从栈顶到栈底做遍历
		for(int i=m_iTop-1; i>=0; i--)
		{
			cout << m_pBuffer[i] << ",";
		}
	}

}