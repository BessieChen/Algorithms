//
//  main.cpp
//  ShellSort
//
//  Created by 陈贝茜 on 2019/6/29.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//


#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"

using namespace std;

int main() {
    
    int n = 20000;
    
    // 测试1 一般测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    int *arr5 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Shell Sort", ShellSort, arr4, n);
    SortTestHelper::testSort("Shell Sort slow", ShellSort_slow, arr5, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    
    cout<<endl;
    
    
    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    
    arr1 = SortTestHelper::generateAlmostSorted(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Shell Sort", ShellSort, arr4, n);
    SortTestHelper::testSort("Shell Sort slow:", ShellSort_slow, arr5, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    
    return 0;
}


//Test for random array, size = 20000, random range [0, 20000]
//Selection Sort : 0.333387s
//Insertion Sort : 0.22041s
//Bubble Sort : 1.38132s
//Shell Sort : 0.003253s
//Shell Sort slow : 0.547218s
//
//Test for nearly ordered array, size = 20000, swap time = 100
//Selection Sort : 0.328241s
//Insertion Sort : 0.003469s
//Bubble Sort : 0.403095s
//Shell Sort : 0.001888s
//Shell Sort slow: : 0.536528s
//Program ended with exit code: 0
