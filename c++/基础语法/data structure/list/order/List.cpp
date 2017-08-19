#include "List.h"
#include <iostream>
using namespace std;

List::List(int size)
{
	m_iSize = size;
	m_pList = new int[size];
	clearList();
}

void List::clearList()
{
	m_iLength = 0;
}

bool List::listEmpty()
{
	return m_iLength == 0 ? true : false;
}

int List::listLength()
{
	return m_iLength;
}

bool List::getElem(int i, int *e)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	} 
	*e = m_pList[i];
	return true;
}

int List::locateElem(int *e)
{
	for(int i=0; i<m_iLength; i++)
	{
		if(m_pList[i] == *e)
		{
			return i;
		}
	}
	return -1;
}


bool List::priorElem(int *currentElem, int *preElem)
{
	int temp = locateElem(currentElem);
	if(temp == -1 || temp == 0)
	{
		return false;
	}
	*preElem = m_pList[--temp];
	return true;
}

bool List::nextElem(int *currentElem, int *nextElem)
{
	int temp = locateElem(currentElem);
	if(temp == -1 || temp == m_iLength)
	{
		return false;
	}
	*nextElem = m_pList[++temp];
	return true;
}

void List::listTraverse()
{
	for (int i = 0; i < m_iLength; i++)
	{
		cout << m_pList[i] << endl;
	}
}

bool List::insertElem(int i, int *e)
{
	if(i < 0 || i > m_iLength)
	{
		return false;
	}
	// 先移动，再插入
	for (int k = m_iLength-1; k >= i; k--)
	{
		m_pList[k+1] = m_pList[k];	//不断往后赋值
	}

	m_pList[i] = *e;

	m_iLength++;
	return true;
}

bool List::delteElem(int i, int *e)
{
	// 先删除，再移动
	m_pList[i] = *e;

	if(i < 0 || i >= m_iLength)
	{
		return false;
	}

	for (int k = i + 1; k < m_iLength; k++)
	{
		m_pList[k-1] = m_pList[k];	//不断向前赋值
	}

	m_iLength--;
	return true;
}
