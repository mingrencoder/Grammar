#ifndef LIST_H
#define LIST_H

class List
{
public:
	List(int size);
	void clearList();
	bool listEmpty();
	int listLength();
	bool getElem(int i, int *e);
	int locateElem(int *e);
	bool priorElem(int *currentElem, int *preElem);
	bool nextElem(int *currentElem, int *nextElem);
	bool insertElem(int i, int *e);
	bool delteElem(int i, int *e);
	void listTraverse();
	
private:
	int *m_pList;
	int m_iSize;
	int m_iLength; //当前储存的元素个数
};

#endif