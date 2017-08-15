/************************************/
/* 二叉树（数组表示）

	要求：完成树的基本操作
	1、树的创建与销毁
	2、树种节点的搜索
	3、树种节点的添加与删除
	4、树中节点的遍历

	bool createTree(Node, *p_iRoot);							// 创建树
	void destoryTree(Tree *pTree);								// 销毁树
	Node *searchNode(int nodeIndex);							// 根据索引搜索节点
	bool addNode(int nodeIndex, int direction, Node *pNode);	// 添加节点
	bool deleteNode(int nodeIndex, Node *pNode);				// 删除节点
	void treeTraverse();										// 遍历


	关于数组与树之间的算法转化：

	int tree[n] 3 5 8 2 6 9 7 	父亲节点下标 * 2 + 1  该节点左
								
								父亲节点下标 * 2 + 2  该节点右
			3(0)

		5(1)	 8(2)

	2(3) 6(4)  9(5)  7(6)

 */
/************************************/



