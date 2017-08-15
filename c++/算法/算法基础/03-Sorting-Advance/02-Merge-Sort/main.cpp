#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"

using namespace std;

// 本质是递归
// 归并排序缺点：在归并时需要开辟辅助内存空间。设立三个索引位置
//     ↓
// 1 2 - - - - - -
// 2 3 6 8 1 4 5 7
//   ↑       ↑
// 上述即两个已经排好序的数组，每一次比较两个数组头部元素谁更小，就放入新开辟的数组区间中，复杂度为O(n)
//
// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void __merge(T arr[], int l, int mid, int r){

    // 经测试,传递aux数组的性能效果并不好
    // 复制arr的值到aux数组中
    T aux[r-l+1];
    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];

    // 设置两个区间的索引分别为i和j
    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid )   { arr[k] = aux[j-l]; j ++;} // 如果左半部分元素已经全部处理完毕
        else if( j > r ){ arr[k] = aux[i-l]; i ++;}
        else if( aux[i-l] <= aux[j-l] ){ arr[k] = aux[i-l]; i ++;}
        else                          { arr[k] = aux[j-l]; j ++;}
    }
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r){

    if( l >= r )
        return;

    int mid = (l+r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n){
    // 前面加两个下划线 私有者的写法
    __mergeSort( arr , 0 , n-1 );   // n-1 闭区间
}


int main() {

    int n = 50000;

    // 测试1 一般性测试
    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);

    delete(arr1);
    delete(arr2);

    return 0;
}
