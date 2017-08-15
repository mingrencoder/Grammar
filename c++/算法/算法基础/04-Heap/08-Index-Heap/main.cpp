#include <iostream>
#include <cassert>
#include "SortTestHelper.h"

#define Priority int

using namespace std;

/*
 i      0  1  2  3  4  5  6  7  8  9  10
indexes   10  9  7  8  5  6  3  1  4  2
data      15  17 19 33 22 16 28 30 41 62

通过数组的i来找到indexes与data，indexes以堆的形式存放，最大值为data[indexes[1]]
 */
template<typename Item>
class IndexMaxHeap{

private:
    Item *data;
    int *indexes;

    int count;
    int capacity;

    void shiftUp( int k ){

        while( k > 1 && data[indexes[k/2]] < data[indexes[k]] ){
            swap( indexes[k/2] , indexes[k] );
            k /= 2;
        }
    }

    void shiftDown( int k ){

        while( 2*k <= count ){
            int j = 2*k;
            if( j + 1 <= count && data[indexes[j+1]] > data[indexes[j]] ) // indexes[j+1]即为data[]的索引
                j += 1;

            if( data[indexes[k]] >= data[indexes[j]] )
                break;

            swap( indexes[k] , indexes[j] );
            k = j;
        }
    }

public:
    IndexMaxHeap(int capacity){

        data = new Item[capacity+1];
        indexes = new int[capacity+1];

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap(){
        delete[] data;
        delete[] indexes;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    // 传入的i对用户而言,是从0索引的
    void insert(int i, Item item){
        assert( count + 1 <= capacity );
        assert( i + 1 >= 1 && i + 1 <= capacity );

        i += 1;
        data[i] = item;
        indexes[count+1] = i;
        count++;

        // 只对count进行shiftUp操作
        shiftUp(count);
    }

    Item extractMax(){
        assert( count > 0 );

        Item ret = data[indexes[1]];
        // 关键步骤：这里将最后一个元素与第一个元素交换，保持树形结构，再对该元素执行shiftDown操作
        swap( indexes[1] , indexes[count] );
        count--;
        shiftDown(1);
        return ret;
    }

    // 这里返回的最大值的索引
    int extractMaxIndex(){
        assert( count > 0 );

        int ret = indexes[1] - 1; // 从1开始的索引转化为从0开始的索引
        swap( indexes[1] , indexes[count] );
        count--;
        shiftDown(1);
        return ret;
    }

    Item getMax(){
        assert( count > 0 );
        return data[indexes[1]];
    }

    int getMaxIndex(){
        assert( count > 0 );
        return indexes[1]-1;
    }

    Item getItem( int i ){
        return data[i+1];
    }

    // 将索引为i的内容修改为newItem
    void change( int i , Item newItem ){
        //1、处理data
        i += 1;
        data[i] = newItem;

        //2、处理indexes
        //
        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
        // 时间复杂度O(n)  (n+logn)
        for( int j = 1 ; j <= count ; j ++ )
            if( indexes[j] == i ){
                // 使newItem代表的indexes[j]所在的堆，满足堆的条件
                shiftUp(j);
                shiftDown(j);
                return;
            }
    }

    // test reverse index
    bool testReverseIndex(){

        int *copyIndexes = new int[count+1];

        for( int i = 0 ; i <= count ; i ++ ){
            copyIndexes[i] = indexes[i];
        }

        copyIndexes[0] = 0;
        std::sort(copyIndexes, copyIndexes + count + 1);

        bool res = true;
        for( int i = 1 ; i <= count ; i ++ )
            if( copyIndexes[i-1] + 1 != copyIndexes[i] )
                res = res || false;

        delete[] copyIndexes;

        if( !res ){
            cout<<"Error 1"<<endl;
            return res;
        }

        return true;
    }
};

template<typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n){

    IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        indexMaxHeap.insert( i , arr[i] );
    assert( indexMaxHeap.testReverseIndex() );

    for( int i = n-1 ; i >= 0 ; i -- )
        arr[i] = indexMaxHeap.extractMax();
}

int main() {

    int n = 1000000;

    Priority* arr = new Priority[n];
    srand(time(NULL));
    for( int i = 0 ; i < n ; i ++ )
        arr[i] = rand()%n;
    SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap, arr, n);
    delete[] arr;

    return 0;
}
