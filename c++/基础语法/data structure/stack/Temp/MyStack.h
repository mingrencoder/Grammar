#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include "Coordinate.h"

using namespace std;


template <typename T>
class MyStack
{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(T elem);
	bool pop(T &elem);
	void stackTraverse(bool isFromBottom);

private:
	T *m_pBuffer;	//栈空间指针
	int m_iSize;		//栈容量
	int m_iTop;			//栈顶，栈中元素个数
};


template <typename T>
MyStack<T>::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new T[size];
	m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack()
{
	delete[] m_pBuffer;
	m_pBuffer = NULL;
}

template <typename T>
bool MyStack<T>::stackEmpty()
{
	return m_iTop == 0 ? true : false;
}

template <typename T>
bool MyStack<T>::stackFull()
{
	return m_iTop == m_iSize ? true : false;
}

template <typename T>
void MyStack<T>::clearStack()
{
	m_iTop = 0;
}

template <typename T>
int MyStack<T>::stackLength()
{
	return m_iTop;
}

template <typename T>
bool MyStack<T>::push(T elem)
{
	if(stackFull()){
		return false;
	}
	m_pBuffer[m_iTop] = elem;
	m_iTop++;		//指向的是下一个要入栈的位置
	return true;
}

template <typename T>
bool MyStack<T>::pop(T &elem)
{
	if(stackEmpty()){
		return false;
	}
	m_iTop--;
	elem = m_pBuffer[m_iTop];
	return true;
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromBottom)
{
	if(isFromBottom){
		for(int i=0; i<m_iTop; i++)
		{
			cout << m_pBuffer[i];
		}
	}
	else
	{
		// 从栈顶到栈底做遍历
		for(int i=m_iTop-1; i>=0; i--)
		{
			cout << m_pBuffer[i] ;
		}
	}

}

#endif