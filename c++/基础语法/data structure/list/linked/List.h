#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List
{
public:
	List();
	~List();	// 将所有节点释放
	void clearList();	// 保留第一个节点
	bool listEmpty();
	int listLength();
	bool insertElemFromHead(Node *pNode);
	bool insertElemFromTail(Node *pNode);
	bool insertElem(int i, Node *pNode);
	bool deleteElem(int i, Node *pNode);
	
	bool getElem(int i, Node *pNode);
	int locateElem(Node *pNode);
	bool priorElem(Node *pCurrentNode, Node *preNode);
	bool nextElem(Node *pCurrentNode, Node *nextNode);
	void listTraverse();

private:
	Node *m_pList;
	int m_iLength;
};


#endif