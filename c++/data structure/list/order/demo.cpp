#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "List.cpp"

using namespace std;

/********************************************/
/*
线性表 ———— 顺序表

	3 5 2 3 1 9 4
	前驱，后继

	bool initList(List *list)		创建线性表
	void destroyList(List *list)	销毁线性表
	void clearList(List *list)		清空线性表
	bool listEmpty(List *list)		判断空
	int listLength(List *list)		当前长度
	bool getElem(List *list, int i, Elem *e) 			获取指定元素
	int locateElem(List *list, Elem *e) 				寻找第一个满足e的数据元素的位序
	bool priorElem(List *list, Elem *currentElem, Elem *preElem)		获取指定元素的前驱
	bool nextElem(List *list, Elem currentElem, Elem *nextElem)		获取指定元素的后继
	bool insertElem(List *list, int i, Elem *e)		在第i个位置插入元素
	bool delteElem(List *list, int i, Elem *e)		删除第i个位置的元素
	void listTraverse(List *list)	遍历
*/
/********************************************/

int main()
{
	// 3 5 7 2 9 1 8
	int e1 = 3;
	int e2 = 5;
	int e3 = 7;
	int e4 = 2;
	int e5 = 9;
	int e6 = 1;
	int e7 = 8;
	int temp = 10;
	List *list = new List(10);

	cout << "length:" << list->listLength() << endl;
	//插入元素
	list->insertElem(0, &e1);
	list->insertElem(1, &e2);
	list->insertElem(2, &e3);
	list->insertElem(3, &e4);

	cout << "length:" << list->listLength() << endl;

	list->insertElem(4, &e5);
	list->insertElem(5, &e6);
	list->insertElem(6, &e7);

	// 删除元素
	list->delteElem(1, &temp);

	// 获得元素
	list->getElem(1, &temp);
	cout << "temp:" << temp << endl;

	// 定位元素
	temp = 2;
	cout << "元素位置：" << list->locateElem(&temp) << endl;

	// 前驱后继
	list->priorElem(&e5, &temp);
	cout << e5 << "前驱元素的值：" << temp << endl;
	list->nextElem(&e5, &temp);
	cout << e5 << "后继元素的值：" << temp << endl;

	// 清空元素
	if(!(list->listEmpty()))
	{
		cout << "不为空" << endl;
		list->listTraverse();
	}

	list->clearList();

	if(list->listEmpty())
	{
		cout << "为空" << endl;
	}

	delete list;
	return 0;
}