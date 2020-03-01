//
//  InsertionSort.h
//  InsertionSort
//
//  Created by 陈贝茜 on 2019/6/27.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef InsertionSort_h
#define InsertionSort_h

#include <iostream>

template <typename T>
void insertionSort(T arr[], int len)
{
    for(int i = 1; i < len; i++)
    {
        //method 1:
//        for(int j = i; j >= 1; j--)
//        {
//            if(arr[j] < arr[j-1])
//            {
//                swap(arr[j], arr[j-1]);
//            }
//            else
//            {
//                break;
//            }
//        }
        
        //method 2:
//        for(int j = i; j >= 1 && arr[j] < arr[j-1]; j--)
//        {
//            swap(arr[j], arr[j-1]);
//        }
        
        //method 3:优化后的算法，即不用每次遇见比自己大的就swap，而是遇见第一个比自己小的才交换值。
        T record = arr[i];
        int j;
        for(j = i; j > 0 && arr[j-1]>record; j--)//注意不是 j > 0 && arr[j-1]>arr[j]
        {
            arr[j] = arr[j-1];
        }
        arr[j] = record;
    }
}
        
#endif /* InsertionSort_h */
