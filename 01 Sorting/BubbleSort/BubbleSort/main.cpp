//
//  main.cpp
//  BubbleSort
//
//  Created by 陈贝茜 on 2019/6/28.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#include <iostream>
#include "SelectionSort.h"
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "BubbleSort.h"

int main() {
    
    int n = 20000;
    
    // 测试1 一般测试
    cout<<"Test for random array, size = "<<n<<", randome range [0, "<<n<<"]"<<endl;
    
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort 2", bubbleSort2, arr4, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    
    cout<<endl;
    
    
    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    
    cout<<"Test for nNearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    
    arr1 = SortTestHelper::generateAlmostSorted(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort 2", bubbleSort2, arr4, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    
    cout<<endl;
    
    
    // 测试3 测试完全有序的数组
    // 对于完全有序的数组，冒泡排序法也将成为O(n)级别的算法
    swapTimes = 0;
    n = 10000000;    // 由于插入排序法和冒泡排序法在完全有序的情况下都将成为O(n)算法
    // 所以我们的测试数据规模变大，为1000,0000
    cout<<"Test for ordered array, size = " << n << endl;
    
    arr1 = SortTestHelper::generateAlmostSorted(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    
    // 在这种情况下，不再测试选择排序算法
    //SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort 2", bubbleSort2, arr4, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    
    
    return 0;
}

//Test for random array, size = 20000, randome range [0, 20000]
//Selection Sort : 0.340101s
//Insertion Sort : 0.217224s
//Bubble Sort : 1.35468s
//Bubble Sort 2 : 1.34504s
//
//Test for nNearly ordered array, size = 20000, swap time = 100
//Selection Sort : 0.332328s
//Insertion Sort : 0.002734s
//Bubble Sort : 0.397269s
//Bubble Sort 2 : 0.392245s
//
//Test for ordered array, size = 10000000
//Insertion Sort : 0.032445s
//Bubble Sort : 0.020024s
//Bubble Sort 2 : 0.019995s
