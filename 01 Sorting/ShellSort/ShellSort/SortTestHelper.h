//
//  SortTestHelper.h
//  SelectionSort
//
//  Created by 陈贝茜 on 2019/6/27.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef SortTestHelper_h
#define SortTestHelper_h

#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;

namespace SortTestHelper {
    
    // 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
    int *generateRandomArray(int n, int rangL, int rangR)
    {
        assert(rangL < rangR);
        int *arr = new int[n];
        srand(static_cast<unsigned int>(time(NULL)));
        for(int i = 0; i < n; i++)
        {
            arr[i] = rand() % (rangR - rangL + 1) + rangL;//如何实现左闭右闭
        }
        return arr;
    }
    
    int *generateAlmostSorted(int n, int swapNumber)
    {
        int *arr = new int[n];
        srand(static_cast<unsigned int>(time(NULL)));
        for(int i = 0; i < n; i++)
        {
            arr[i] = i;
        }
        for(int i = 0; i < swapNumber; i++)
        {
            int posA = rand() % n;
            int posB = rand() % n;
            swap(arr[posA], arr[posB]);
        }
        return arr;
    }
    
    // 打印arr数组的所有内容
    template <typename T>
    void printArray(T arr[], int length)
    {
        for(int i = 0; i < length; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    bool isSorted(int arr[], int len)
    {
        for(int i = 1; i < len; i++)
        {
            if(arr[i] < arr[i-1])
            {
                return false;
            }
        }
        return true;
    }
    
    template <typename T>
    void testSort(const string &testName, void (*sort)(T[], int), T arr[], int len)
    {
        clock_t startTime = clock();
        sort(arr, len);
        clock_t endTime = clock();
        assert(isSorted(arr, len));
        double time = (endTime - startTime);
        time /= CLOCKS_PER_SEC;
        cout<<testName<<" : "<<time<<"s"<<endl;
    }
    
    
    int *copyIntArray(int arr[], int len)
    {
        int *copyRet = new int[len];
        //method 1:
//        for(int i = 0; i < len; i++)
//        {
//            copyRet[i] = arr[i];
//        }
        
        //method 2:
        copy(arr, arr+len, copyRet);//注意，我之前是命名返回值是copy，然后报错了，因为cpp不知道你参数表的copy是一个函数还是你声明的int *
        return copyRet;
    }
    
}
#endif /* SortTestHelper_h */
