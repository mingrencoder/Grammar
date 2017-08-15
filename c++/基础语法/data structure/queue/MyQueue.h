/********************************************/
/*
实现环形队列
*/
/********************************************/

class MyQueue
{
public:
	MyQueue(int queueCapacity); //InitQueue(&Q)创建队列
	virtual	~MyQueue();			//销毁队列
	void clearQueue();			//清空队列
	bool queueEmpty() const;	//判空
	bool queueFull() const;		//判满
	int queueLength() const;	//队列长度
	bool enQueue(int element);	//新元素入队
	bool deQueue(int &element);	//首元素出队
	void queueTraverse();		//遍历
private:
	int *m_pQueue;				//队列数组指针
	int m_iQueueLen;			//队列元素个数
	int m_iQueueCapacity;		//队列数组容量
	int m_iHead;				//队头下表
	int m_iTail;
};