//
// Created by 纪凯 on 2017/6/15.
//

#include "Node.h"

Node::Node()
{
    index = 0;
    data = 0;
    pLChild = NULL;
    pRChild = NULL;
    pParent = NULL;
}

/*
 * 做递归
 */
Node::searchNode(int nodeIndex)
{
    if(this->index = nodeIndex)
    {
        return this;
    }

    if(NULL != this->pLChild)
    {
        if(this->pLChild == nodeIndex)
        {
            return this->pLChild;
        }
    }

    if(NULL != this->pRChild)
    {
        if(this->pRChild == nodeIndex)
        {
            return this->pRChild;
        }
    }
}