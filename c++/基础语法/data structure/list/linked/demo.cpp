#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "List.cpp"
#include "Node.cpp"

using namespace std;

/********************************************/
/*
线性表 ———— 单链表

	3 5 2 3 1 9 4
*/
/********************************************/

int main()
{
	Node node1;
	node1.data = 3;

	Node node2;
	node2.data = 4;

	Node node3;
	node3.data = 5;

	Node node4;
	node4.data = 6;

	Node node5;
	node5.data = 7;

	Node temp;
	List *list = new List();

	// list->insertElemFromHead(&node1);
	// list->insertElemFromHead(&node2);
	// list->insertElemFromHead(&node3);
	// list->insertElemFromHead(&node4);

	list->insertElemFromTail(&node1);
	list->insertElemFromTail(&node2);
	list->insertElemFromTail(&node3);
	list->insertElemFromTail(&node4);
	list->insertElem(2, &node5);
	list->deleteElem(3, &temp);
	list->listTraverse();

	list->getElem(1, &temp);
	cout << "取出的值：" << temp.data << endl;

	list->priorElem(&node2, &temp);
	cout << "nodd2取出的前驱：" << temp.data << endl;

	list->nextElem(&node2, &temp);
	cout << "node2取出的后继：" << temp.data << endl;

	delete list;
	list = NULL;
	return 0;
}