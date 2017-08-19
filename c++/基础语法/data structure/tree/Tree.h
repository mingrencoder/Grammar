#ifndef TREE_H
#define TREE_H

class Tree
{
public:
	Tree(int size, int *pRoot);											// 创建树
	~Tree();												// 销毁树
	int *searchNode(int nodeIndex);							// 根据索引搜索节点
	bool addNode(int nodeIndex, int direction, int *pNode);	// 添加节点
	bool deleteNode(int nodeIndex, int *pNode);				// 删除节点
	void treeTraverse();									// 遍历

private:
	int *m_pTree;
	int m_iSize;
};

#endif