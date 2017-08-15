#include "List.h"
#include <iostream>
using namespace std;

List::List()
{
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;	// 虽然已经有一个节点，但这个节点不算在链表当中
}

/*
首先找到头节点，之后不断找到next节点
 */
void List::clearList()
{
	Node *currentNode = m_pList->next;
	while(currentNode != NULL)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;	// 最后再置为NULL
	m_iLength = 0;
}

List::~List()
{
	clearList();
	delete m_pList;
	m_pList = NULL;
}

bool List::listEmpty()
{
	return m_iLength == 0 ? true : false;
}

int List::listLength()
{
	return m_iLength;
}

/*
在m_pList和m_pList->next之间插入一个节点newNode，并使newNode的数据域值
与传入的pNode数据域值相等
 */
bool List::insertElemFromHead(Node *pNode)
{
	Node *temp = m_pList->next;
	Node *newNode = new Node;	// 这里不能用栈内存，不然函数执行完后就会被回收
	if(newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;

	m_iLength++;

	return true;
}

bool List::insertElemFromTail(Node *pNode)
{
	Node *currentNode = m_pList;
	while(currentNode->next!= NULL)
	{
		currentNode = currentNode->next;
	}
	Node *newNode = new Node;
	if(newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = NULL; // 别忘了最后一个节点需要指向NULL
	currentNode->next = newNode;

	m_iLength++;
	return true;
}

/*
在任意位置插入一个节点
 */
bool List::insertElem(int i, Node *pNode)
{
	if(i < 0 || i > m_iLength)
	{
		return false;
	}

	Node *currentNode = m_pList;
	for(int k=0; k<i; k++) // 往后找i次
	{
		/*
			这里是第i个位置的上一个节点
			例如 i=1; 这里得到的currentNode就是i=0的节点
			而插入一个新节点newNode，就是插入在i=0节点之后
		 */
		currentNode = currentNode->next;
	}

	Node *newNode = new Node();
	if(NULL == newNode)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;

	m_iLength++;
	return true;
}

bool List::deleteElem(int i, Node *pNode)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}

	Node *currentNode = m_pList;
	Node *priorNode = NULL;	// 第i个位置的上一个Node
	for(int k=0; k<=i; k++)
	{
		priorNode = currentNode;
		currentNode = currentNode->next;
	}

	priorNode->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;

	m_iLength--;
	return true;
}



bool List::getElem(int i, Node *pNode)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	} 

	/*
	找到第i个节点
	 */
	Node *currentNode = m_pList;
	Node *priorNode = NULL;	// 第i个位置的上一个Node
	for(int k=0; k<=i; k++)
	{
		priorNode = currentNode;
		currentNode = currentNode->next;
	}
	// 赋值
	pNode->data = currentNode->data;
	return true;
}

/*
 去找到与传入pNode的数据值相等的Node
 */
int List::locateElem(Node *pNode)
{
	Node *currentNode = m_pList->next;
	int count = 0;
	while(currentNode != NULL)
	{
		if(currentNode->data == pNode->data)
		{
			return count;
		}
		count ++;
	}
	return -1;
}

/*
这个方法和上面locateElem相似，但是这里另外定义了一个tempNode作为pCurrentNode的上一个Node
当currentNode->data == pCurrentNode->data时，将tempNode的值赋给preNode
 */
bool List::priorElem(Node *pCurrentNode, Node *preNode)
{
	Node *currentNode = m_pList;
	Node *tempNode = NULL;
	while(currentNode->next != NULL)
	{
		tempNode = currentNode;
		currentNode = currentNode->next;
		if(currentNode->data == pCurrentNode->data)
		{
			// 判断tempNode是不是就是头结点本身
			if(tempNode == m_pList)
			{
				return false;
			}
			preNode->data = tempNode->data;
			return true;
		}
	}
	return false;
}

bool List::nextElem(Node *pCurrentNode, Node *nextNode)
{
	Node *currentNode = m_pList->next;
	while(currentNode != NULL)
	{
		if(currentNode->data == pCurrentNode->data)
		{			// 判断当前节点不是最后一个
			if(currentNode->next == NULL)
			{
				return false;
			}
			nextNode->data = currentNode->next->data;
			return true;
		}
		currentNode = currentNode->next;
	}
	return false;
}

void List::listTraverse()
{
	Node *currentNode = m_pList;
   while(currentNode->next != NULL)
   {
     currentNode = currentNode->next;
     currentNode->printNode();
   }
}