//
// Created by liuyubobobo on 8/15/16.
//

#ifndef INC_05_HEAPIFY_HEAP_H
#define INC_05_HEAPIFY_HEAP_H

#include <algorithm>
#include <cassert>

using namespace std;

/*
Heapify:
步骤：
1、将数组化为完全二叉树形式，此时所有叶子结点本身就是最大堆(每个堆只有一个元素)
2、元素个数/2：为非叶子结点的最后一个结点的索引
3、从最后一个非叶子结点(count/2)开始执行shiftDown，依次执行到arr[1]
 */
template<typename Item>
class MaxHeap{

private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k){
        while( k > 1 && data[k/2] < data[k] ){
            swap( data[k/2], data[k] );
            k /= 2;
        }
    }

    void shiftDown(int k){
        while( 2*k <= count ){
            int j = 2*k;
            if( j+1 <= count && data[j+1] > data[j] ) j ++;
            if( data[k] >= data[j] ) break;
            swap( data[k] , data[j] );
            k = j;
        }
    }

public:

    MaxHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    // Heapify
    MaxHeap(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;

        for( int i = 0 ; i < n ; i ++ ) // 索引转化
            data[i+1] = arr[i];
        count = n;

        for( int i = count/2 ; i >= 1 ; i -- )
            shiftDown(i);
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

    void insert(Item item){
        assert( count + 1 <= capacity );
        data[count+1] = item;
        shiftUp(count+1);
        count ++;
    }

    Item extractMax(){
        assert( count > 0 );
        Item ret = data[1];
        swap( data[1] , data[count] );
        count --;
        shiftDown(1);
        return ret;
    }

    Item getMax(){
        assert( count > 0 );
        return data[1];
    }
};

#endif //INC_05_HEAPIFY_HEAP_H
