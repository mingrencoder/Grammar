#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree
{
public:
	Tree(int size, int *pRoot);								// 创建树
	~Tree();												// 销毁树
	Node *searchNode(int nodeIndex);						// 根据索引搜索节点
	bool addNode(int nodeIndex, int direction, Node *pNode);	// 添加节点
	bool deleteNode(int nodeIndex, int *pNode);				// 删除节点
    void preOrder();										// 前序遍历
	void inOrder();											// 中序遍历
	void postOrder();										// 后序遍历

// 注意这里与数组Tree的区别是这里没有长度限制
private:
	Node *m_pRoot;
};

#endif