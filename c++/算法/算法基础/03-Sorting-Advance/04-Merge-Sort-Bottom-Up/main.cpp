#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"


using namespace std;

// 缺点：比递归稍微慢一点
// 优点：没有数组通过索引直接获取的特性，因此可以实现链表排序
template <typename T>
void mergeSortBU(T arr[], int n){
// 第一层循环是对进行Merge的元素个数进行遍历，1 2 4 8 16……
//    for( int sz = 1; sz <= n ; sz += sz )
//        第二层循环代表每次归并，从0开始，以两个sz为一个归并区间
//        for( int i = 0 ; i < n ; i += sz+sz )
//            // 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
//            __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );

    // Merge Sort Bottom Up 优化
    for( int i = 0 ; i < n ; i += 16 )
        insertionSort(arr,i,min(i+15,n-1));

    for( int sz = 16; sz <= n ; sz += sz )
        for( int i = 0 ; i < n - sz ; i += sz+sz )
            if( arr[i+sz-1] > arr[i+sz] )
                __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );
}


int main() {

    int n = 1000000;

    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);

    delete(arr1);
    delete(arr2);

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);

    delete(arr1);
    delete(arr2);

    return 0;
}
