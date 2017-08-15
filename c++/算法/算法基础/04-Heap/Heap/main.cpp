#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "IndexMaxHeap.h"
#include "IndexMinHeap.h"
#include "SortTestHelper.h"

using namespace std;

/*
思考1：在N个元素中选出前M个元素
使用优先队列，保持一个容量为M的最大(小)堆，然后进行逐个插入，时间复杂度为NlogM

思考2：多路归并排序
在归并排序中，如果将数组分为大于两个的数组时，就可以将每个子数组的最小值放入一个最小堆中，不断推出最小值
数组可以分为d路归并排序，d的值大小？？ 假设将d=n，则归并排序就演化为堆排序了

思考3：d叉堆

优化细节:
1、swap
2、堆的数组从0开始索引
3、capacity的限制，动态调整数组大小
 */
template<typename T>
void heapSortUsingMaxHeap(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        maxheap.insert(arr[i]);

    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = maxheap.extractMax();

}

template<typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n){

    IndexMaxHeap<T> indexMaxheap = IndexMaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        indexMaxheap.insert(i, arr[i]);

    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = indexMaxheap.extractMax();

}

template<typename T>
void heapSortUsingMinHeap(T arr[], int n){

    MinHeap<T> minheap = MinHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        minheap.insert(arr[i]);

    for( int i = 0 ; i < n ; i++ )
        arr[i] = minheap.extractMin();

}

template<typename T>
void heapSortUsingIndexMinHeap(T arr[], int n){

    IndexMinHeap<T> indexMinheap = IndexMinHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        indexMinheap.insert(i, arr[i]);

    for( int i = 0 ; i < n ; i++ )
        arr[i] = indexMinheap.extractMin();

}

int main() {

    int n = 1000000;

    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Heap Sort Using Max Heap", heapSortUsingMaxHeap, arr1, n);
    SortTestHelper::testSort("Heap Sort Using Index Max Heap", heapSortUsingIndexMaxHeap, arr2, n);
    SortTestHelper::testSort("Heap Sort Using Min Heap", heapSortUsingMinHeap, arr3, n);
    SortTestHelper::testSort("Heap Sort Using Index Min Heap", heapSortUsingIndexMinHeap, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}
