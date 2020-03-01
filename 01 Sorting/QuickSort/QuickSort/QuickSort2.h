//
//  QuickSort2.h
//  QuickSort
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

// 第2版quickSort，加入了insertion以及随机选择首部
#include "InsertionSort.h"
#ifndef QuickSort2_h
#define QuickSort2_h

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition2(T arr[], int l, int r)
{
    int p = l;//指向小于等于v的部分的右边第一个元素，所以如果最后还是i==left，就说明根本没有小于等于v的部分
    int test = l+1;//探测用的index
    int randomIndex = rand() % (r-l+1) + l;//Byb!
    swap(arr[l], arr[randomIndex]);
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
void __quickSort2(T arr[], int l, int r)
{
    if( r-l <= 10)//所以不需要有 if( l >= r)的判断了，因为r-l <= 10就包括了l >= r的判断。
    {
        new_insertionSort(arr, l, r);
        return;//不能少了这一句啊亲！
    }
    
    int pIndex = __partition2(arr, l, r);
    __quickSort2(arr, l, pIndex-1);
    __quickSort2(arr, pIndex+1, r);
    
}

template<typename T>
void quickSort2(T arr[], int len)
{
    __quickSort2(arr, 0, len-1);
}

#endif /* QuickSort2_h */
