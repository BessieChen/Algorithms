//
//  main.cpp
//  InsertionSort
//
//  Created by 陈贝茜 on 2019/6/27.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#include <iostream>
#include "SelectionSort.h"
#include "SortTestHelper.h"
#include "InsertionSort.h"

int main(int argc, const char * argv[]) {
    int n = 10000;
    
    // 测试1 一般测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);
    
    delete[] arr1;
    delete[] arr2;
    
    cout<<endl;
    
    
    // 测试2 有序性更强的测试
    cout<<"Test for more ordered random array, size = "<<n<<", random range [0, 3]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,3);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);
    
    delete[] arr1;
    delete[] arr2;
    
    cout<<endl;
    
    
    // 测试3 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateAlmostSorted(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);
    
    delete[] arr1;
    delete[] arr2;
    
    return 0;

}

//
//Test for random array, size = 10000, random range [0, 10000]
//Insertion Sort : 0.058919s
//Selection Sort : 0.081742s
//
//Test for more ordered random array, size = 10000, random range [0, 3]
//Insertion Sort : 0.042171s
//Selection Sort : 0.081031s
//
//Test for nearly ordered array, size = 10000, swap time = 100
//Insertion Sort : 0.001706s
//Selection Sort : 0.081883s
//Program ended with exit code: 0
