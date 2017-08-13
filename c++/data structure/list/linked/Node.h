#ifndef NODE_H
#define NODE_H

class Node
{
public:
	int data; // 代表数据域
	Node *next; // 代表指针域
	void printNode();
};

#endif