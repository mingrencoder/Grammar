#include "MyQueue.h"
#include <iostream>

using namespace std;

MyQueue::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;
	m_pQueue = new int[queueCapacity];
	clearQueue();
}

MyQueue::~MyQueue()
{
	delete[] m_pQueue;
	m_pQueue = NULL;
}

void MyQueue::clearQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}

bool MyQueue::queueEmpty() const
{
	// if(m_iQueueLen == 0)
	// {
	// 	return true;
	// }
	// else
	// {
	// 	return false;
	// }
	return m_iQueueLen == 0 ? true : false;
}

bool MyQueue::queueFull() const
{
	return m_iQueueLen == m_iQueueCapacity ? true : false;
}

int MyQueue::queueLength() const
{
	return m_iQueueLen;
}

bool MyQueue::enQueue(int element)
{
	if(queueFull())
	{
		return false;
	}
	m_pQueue[m_iTail] = element;
	m_iTail = ++m_iTail % m_iQueueCapacity;				// 为防止尾部下表超过数组界限，这里采取区域操作
	m_iQueueLen++;
	return true;
}

bool MyQueue::deQueue(int &element)
{
	if(queueEmpty())
	{
		return false;
	}
	element = m_pQueue[m_iHead];	//当前的头所指向位置的元素复制给当前传入进来的参数
	m_iHead = ++m_iHead % m_iQueueCapacity;
	m_iQueueLen--;
	return true;
}

void MyQueue::queueTraverse()
{
	cout << "---" << endl;
	for(int i=m_iHead; i<m_iQueueLen+m_iHead; i++)
	{
		cout << m_pQueue[i%m_iQueueCapacity] << endl;
	}
	cout <<  "---" << endl;

}