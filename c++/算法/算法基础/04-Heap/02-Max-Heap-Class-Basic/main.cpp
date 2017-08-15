#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

/*
经典堆的数据结构：(最大堆)
1、二叉树：任何结点都不大于其父节点
2、完全二叉树

计算方法
parent (i) = i/2
left child (i) = 2*i
right child (i) = 2*i+1
 */

template<typename Item>
class MaxHeap{

private:
    Item *data;
    int count;

public:

    MaxHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
    }

    ~MaxHeap(){
        delete[] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }
};


int main() {

    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout<<maxheap.size()<<endl;

    return 0;
}
