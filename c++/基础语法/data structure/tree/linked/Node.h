//
// Created by 纪凯 on 2017/6/15.
//

#ifndef TEST_NODE_H
#define TEST_NODE_H


class Node
{
public:
    Node();
    searchNode(int nodeIndex);
    int index;
    int data;
    Node *pLChild;
    Node *pRChild;
    Node *pParent;


};


#endif //TEST_NODE_H
