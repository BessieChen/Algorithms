//
//  QuickSort.h
//  QuickSort
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//
// 第1版 quickSort
#include <iostream>
#include <algorithm>

#ifndef QuickSort_h
#define QuickSort_h

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r)
{
    int p = l;//指向小于等于v的部分的右边第一个元素，所以如果最后还是i==left，就说明根本没有小于等于v的部分
    int test = l+1;//探测用的index
    T v = arr[l];
    
    while(test <= r)
    {
        if(arr[test] <= v)
        {
            p++;
            swap(arr[p],arr[test]);//注意的：1.已经要记得这个swap，而不是直接p++;直接是p++而没有swap的情况是那种p==test的情况。
        }
        test++;
    }
    swap(arr[l], arr[p]);//注意不是swap(arr[0], arr[p]);
    return p;
}

// 对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort(T arr[], int l, int r)
{
    if(l >= r)//不能是if(l == r)，这样可能永远都不会终止。
    {
        return;
    }
    int pIndex = __partition(arr, l, r);
    __quickSort(arr, l, pIndex-1);
    __quickSort(arr, pIndex+1, r);

}

template<typename T>
void quickSort(T arr[], int len)
{
    __quickSort(arr, 0, len-1);
}

#endif /* QuickSort_h */
