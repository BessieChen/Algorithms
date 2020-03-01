//
//  main.cpp
//  MergeSort
//
//  Created by 陈贝茜 on 2019/6/30.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//
#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "MergeSort2.h"
#include "MergeSort3.h"
#include "MergeSortButtomUp.h"
#include "MergeSortButtomUp2.h"
#include "MergeSortCompare.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // Merge Sort是我们学习的第一个O(nlogn)复杂度的算法
    // 可以在1秒之内轻松处理100万数量级的数据
    // 注意：不要轻易尝试使用SelectionSort, InsertionSort或者BubbleSort处理100万级的数据
    // 否则，你就见识了O(n^2)的算法和O(nlogn)算法的本质差异：）
    int n = 50000;
    
    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);
    int* arr5 = SortTestHelper::copyIntArray(arr1, n);
    int* arr6 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);
    SortTestHelper::testSort("Merge Sort 2",     mergeSort2,     arr3, n);
    SortTestHelper::testSort("Merge Sort 3",     mergeSort3,     arr4, n);
    SortTestHelper::testSort("Merge Sort BU",     mergeSortBU,     arr5, n);
    SortTestHelper::testSort("Merge Sort BU2",     mergeSortBU2,     arr6, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    
    cout<<endl;
    
    
    // 测试2 测试近乎有序的数组
    // 对于近乎有序的数组, 数组越有序, InsertionSort的时间性能越趋近于O(n)
    // 所以可以尝试, 当swapTimes比较大时, MergeSort更快
    // 但是当swapTimes小到一定程度, InsertionSort变得比MergeSort快
    int swapTimes = 10;
    assert( swapTimes >= 0 );
    
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateAlmostSorted(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);
    SortTestHelper::testSort("Merge Sort 2",     mergeSort2,     arr3, n);
    SortTestHelper::testSort("Merge Sort 3",     mergeSort3,     arr4, n);
    SortTestHelper::testSort("Merge Sort BU",     mergeSortBU,     arr5, n);
    SortTestHelper::testSort("Merge Sort BU2",     mergeSortBU2,     arr6, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    
    test();
    
    return 0;
}

//
//Test for random array, size = 50000, random range [0, 50000]
//Insertion Sort : 1.39615s
//Merge Sort : 0.012051s
//Merge Sort 2 : 0.007819s
//Merge Sort 3 : 0.006656s
//Merge Sort BU : 0.007854s
//Merge Sort BU2 : 0.00653s
//
//Test for nearly ordered array, size = 50000, swap time = 10
//Insertion Sort : 0.000873s
//Merge Sort : 0.008026s
//Merge Sort 2 : 0.004137s
//Merge Sort 3 : 0.001239s
//Merge Sort BU : 0.004146s
//Merge Sort BU2 : 0.00137s
//
//Without Any Optimization:
//Merge Sort    Average Run Time: 0.25708 s
//Merge Sort BU Average Run Time: 0.185994 s
//
//With Optimization:
//Merge Sort    Average Run Time: 0.165721 s
//Merge Sort BU Average Run Time: 0.164413 s
//Program ended with exit code: 0
