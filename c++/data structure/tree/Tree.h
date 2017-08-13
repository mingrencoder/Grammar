#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree
{
public:
	Tree(int size);												// 创建树				
	~Tree();													// 销毁树
	Node *searchNode(int nodeIndex);							// 根据索引搜索节点
	bool addNode(int nodeIndex, int direction, Node *pNode);	// 添加节点
	bool deleteNode(int nodeIndex, Node *pNode);				// 删除节点
	void treeTraverse();										// 遍历
	
};

#endif