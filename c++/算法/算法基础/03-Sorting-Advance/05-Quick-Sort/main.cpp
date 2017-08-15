#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"

using namespace std;
// 每个partition具有三个游标，分别是代表选取元素的l，小于v的最右边位置j，当前遍历元素i
// 单独解释j作用：每次发现一个小于v的元素，++j，遍历完所有元素，此时j即表示有多少个元素比v小
// 举例：j初始为l，i初始为l+1，当arr[1] < v，arr[1]本身做交换，而此时只有j=l+1起作用
//
// 对arr[l...r]部分进行partition操作
// 返回p,使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r){

    // 先考察第一个元素
    T v = arr[l];

    // arr[l+1...j] < v ; arr[j+1...i) > v，为什么后面是开区间，因为i这个位置是当前考察的元素
    // 初始时，上述两个数组区间都为空
    int j = l;
    // 从l+1开始遍历，将比a[j]小的数移动到左边
    for( int i = l + 1 ; i <= r ; i ++ )
        if( arr[i] < v ){
            swap( arr[++j] , arr[i] ); // 将第一个大于v的元素与正在考察的元素进行交换
        }

    swap( arr[l], arr[j] );

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r){

    if( l >= r )
        return;

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1 );
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){

    __quickSort(arr, 0, n-1);
}


int main() {

    int n = 1000000;

    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}
