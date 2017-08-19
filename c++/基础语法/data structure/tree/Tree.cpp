#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree(int size, int *pRoot)
{
    m_iSize = size;
    m_pTree = new int[size];
    for (int i = 0; i < size; ++i) {
        m_pTree[i] = 0;
    }
    m_pTree[0] = *pRoot;
}

Tree::~Tree()
{
    delete[] m_pTree;
    m_pTree = NULL;
}

int *Tree::searchNode(int nodeIndex)
{
    if(nodeIndex < 0 || nodeIndex >= m_iSize)
    {
        return NULL;
    }
    if(m_pTree[nodeIndex] == 0)
    {
        return NULL;
    }
    return &m_pTree[nodeIndex];
}

bool Tree::addNode(int nodeIndex, int direction, int *pNode)
{
    if(nodeIndex < 0 || nodeIndex >= m_iSize)
    {
        return false;
    }
    if(m_pTree[nodeIndex] == 0)
    {
        return false;
    }

    // 插入左节点
    if(direction == 0)
    {
        if(nodeIndex * 2 + 1 >= m_iSize)
        {
            return false;
        }
        if(m_pTree[nodeIndex * 2 + 1] != 0) // 判断此位置是否已存在节点
        {
            return false;
        }
        m_pTree[nodeIndex * 2 + 1] = *pNode;
    }

    if(direction == 1)
    {
        if(nodeIndex * 2 + 2 >= m_iSize)
        {
            return false;
        }
        if(m_pTree[nodeIndex * 2 + 2] != 0) // 判断此位置是否已存在节点
        {
            return false;
        }
        m_pTree[nodeIndex * 2 + 2] = *pNode;
    }
    return true;
}

bool Tree::deleteNode(int nodeIndex, int *pNode)
{
    if(nodeIndex < 0 || nodeIndex >= m_iSize)
    {
        return false;
    }
    if(m_pTree[nodeIndex] == 0)
    {
        return false;
    }

    *pNode = m_pTree[nodeIndex];
    m_pTree[nodeIndex] = 0;
    return true;
}

void Tree::treeTraverse()
{
    for (int i = 0; i < m_iSize; ++i) {
        cout << m_pTree[i] << " ";
    }
}