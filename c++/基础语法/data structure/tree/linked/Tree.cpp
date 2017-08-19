#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree(int size, int *pRoot)
{
    m_pRoot = new Node();

}

Tree::~Tree()
{
    delete[] m_pTree;
    m_pTree = NULL;
}

Node *Tree::searchNode(int nodeIndex)
{
    return m_pRoot->searchNode(nodeIndex);
}

bool Tree::addNode(int nodeIndex, int direction, Node *pNode)
{
    Node *temp = searchNode(direction);
    if(NULL == temp)
    {
        return false;
    }

    // 将pNode赋值
    Node *node = new Node;
    node->index = pNode->index;
    node->data = pNode->data;
    node->pParent = temp;

    // 判断挂在在左边或右边
    if(direction == 0)
    {
        temp->pLChild = node;
    }

    if(direction == 1)
    {
        temp->pRChild = node;
    }
    return true;
}

bool Tree::deleteNode(int nodeIndex, int *pNode)
{

    return true;
}

void Tree::treeTraverse()
{

}