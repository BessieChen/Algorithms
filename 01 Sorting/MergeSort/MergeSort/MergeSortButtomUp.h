//
//  MergeSortButtomUp.h
//  MergeSort
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

//这个是第4版的merge sort：之前都是自顶向下，现在自底向上排列
#ifndef MergeSortButtomUp_h
#define MergeSortButtomUp_h

template<typename T>
void __mergeBU(T arr[], T replicate[], int l, int mid, int r)
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
void mergeSortBU(T arr[], int len)
{
    T *replicate = new T[len];
    for(int size = 1; size <= len; size *= 2)
    {
        for(int j = 0; j+size <= len-1; j += 2*size)// j+size >= len-1这个条件是要保证__mergeBU的右部分至少有一个元素。注意！是j += 2倍的size！！！！而且注意！不是从int j = size开始！！！是int j = 0！！！
        {
            __mergeBU(arr, replicate, j, j+size-1, min(j+2*size-1, len-1));
        }
    }
    delete []replicate;
}
#endif /* MergeSortButtomUp_h */
