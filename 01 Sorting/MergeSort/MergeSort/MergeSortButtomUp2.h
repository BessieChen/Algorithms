//
//  MergeSortButtomUp2.h
//  MergeSort
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

//这个是第5版的merge sort：自底向上排列 + insertion优化 + 仅当arr[mid] > arr[mid+1]时候才merge
#include "InsertionSort.h"
#ifndef MergeSortButtomUp2_h
#define MergeSortButtomUp2_h

template<typename T>
void __mergeBU2(T arr[], T replicate[], int l, int mid, int r)
{
    for(int i = l; i <= r; i++)
    {
        replicate[i] = arr[i];
    }
    
    int i = l;
    int j = mid+1;
    int k = l;
    
    while(k <= r)
    {
        if(i == mid+1)
        {
            while(j <= r)
            {
                arr[k++] = replicate[j++];
            }
        }
        else if( j == r+1)
        {
            while(i <= mid)
            {
                arr[k++] = replicate[i++];
            }
        }
        else if(replicate[i] <= replicate[j] && i <= mid && j <= r)
        {
            arr[k++] = replicate[i++];
        }
        else if(replicate[i] > replicate[j] && i <= mid && j <= r)
        {
            arr[k++] = replicate[j++];
        }
    }
}


template<typename T>
void mergeSortBU2(T arr[], int len)
{
    T *replicate = new T[len];
    int beginSize = 16;
    for(int i = 0; i < len; i += beginSize)
    {
        new_insertionSort(arr, i, min(i+beginSize-1, len-1));
    }
    for(int size = beginSize; size <= len; size *= 2)
    {
        for(int j = 0; j+size <= len-1; j += 2*size)// j+size >= len-1这个条件是要保证__mergeBU的右部分至少有一个元素。注意！是j += 2倍的size！！！！而且注意！不是从int j = size开始！！！是int j = 0！！！
        {
            if(arr[j+size-1] > arr[j+size])
            {
                __mergeBU2(arr, replicate, j, j+size-1, min(j+2*size-1, len-1));
            }
        }
    }
    delete []replicate;
}

#endif /* MergeSortButtomUp2_h */
