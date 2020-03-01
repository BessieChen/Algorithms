//
//  main.cpp
//  QuickSort
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "QuickSort2.h"
#include "QuickSort3.h"
#include "QuickSort4.h"
#include "QuickSort5.h"
#include "QuickSort6.h"
#include "ShellSort.h"
#include "QuickSortCompare.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int n = 100000;
    //int n = 1000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);
    int* arr3 = SortTestHelper::copyIntArray(arr1,n);
    int* arr4 = SortTestHelper::copyIntArray(arr1,n);
    int* arr5 = SortTestHelper::copyIntArray(arr1,n);
    int* arr6 = SortTestHelper::copyIntArray(arr1,n);


    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort optimized", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort two way", quickSort3, arr2, n);
    SortTestHelper::testSort("Quick Sort two way optimized", quickSort4, arr2, n);
    SortTestHelper::testSort("Quick Sort three way", quickSort5, arr2, n);
    SortTestHelper::testSort("Quick Sort three way optimized", quickSort6, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    // 但是对于近乎有序的数组, 我们的快速排序算法退化成了O(n^2)级别的算法
    // 对于近乎有序的数组, 快排退化成了O(n^2)的算法
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateAlmostSorted(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);//过慢
    SortTestHelper::testSort("Quick Sort optimized", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort two way", quickSort3, arr2, n);//过慢
    SortTestHelper::testSort("Quick Sort two way optimized", quickSort4, arr2, n);
    SortTestHelper::testSort("Quick Sort three way", quickSort5, arr2, n);//慢
    SortTestHelper::testSort("Quick Sort three way optimized", quickSort6, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    cout<<endl;

    // 测试3 测试存在包含大量相同元素的数组
    // 但此时, 对于含有大量相同元素的数组, 我们的快速排序算法再次退化成了O(n^2)级别的算法
    // 快排退化成了O(n^2)的算法
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);//过慢
    SortTestHelper::testSort("Quick Sort optimized", quickSort2, arr2, n);//过慢，因为分割极不平衡
    SortTestHelper::testSort("Quick Sort two way", quickSort3, arr2, n);
    SortTestHelper::testSort("Quick Sort two way optimized", quickSort4, arr2, n);
    SortTestHelper::testSort("Quick Sort three way", quickSort5, arr2, n);
    SortTestHelper::testSort("Quick Sort three way optimized", quickSort6, arr3, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    cout<<endl;
    test();
    
    return 0;
}

//Test for random array, size = 100000, random range [0, 100000]
//Merge Sort : 0.024748s
//Quick Sort : 0.015658s
//Quick Sort optimized : 0.008848s
//Quick Sort two way : 7.82067s
//Quick Sort two way optimized : 0.004625s
//Quick Sort three way : 0.013879s
//Quick Sort three way optimized : 0.018011s
//
//Test for nearly ordered array, size = 100000, swap time = 100
//Merge Sort : 0.016791s
//Quick Sort : 0.291671s
//Quick Sort optimized : 0.00884s
//Quick Sort two way : 8.45519s
//Quick Sort two way optimized : 0.004001s
//Quick Sort three way : 0.013485s
//Quick Sort three way optimized : 0.013977s
//
//Test for random array, size = 100000, random range [0,10]
//Merge Sort : 0.020384s
//Quick Sort : 2.86024s
//Quick Sort optimized : 2.85705s
//Quick Sort two way : 0.017776s
//Quick Sort two way optimized : 0.005121s
//Quick Sort three way : 0.001924s
//Quick Sort three way optimized : 0.003509s
//
//Sorting 1000000 elements 100 times. Calculate the average run time.
//Shell Sort Average Run Time: 0.301912 s
//Merge Sort Average Run Time: 0.256292 s
//Quick Sort Average Run Time: 0.180217 s
//Quick Sort 2 Ways Average Run Time: 0.147238 s
//Quick Sort 3 Ways Average Run Time: 0.227733 s
//Program ended with exit code: 0
