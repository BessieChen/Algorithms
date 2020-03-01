//
//  QuickSort5.h
//  QuickSort
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

//第5版，三路排序
#include "InsertionSort.h"

#ifndef QuickSort5_h
#define QuickSort5_h

template<typename T>
void __quickSort5(T arr[], int l, int r)
{
    if( r - l <= 16 ){
        new_insertionSort(arr,l,r);
        return;
    }
    
    swap( arr[l] , arr[rand()%(r-l+1)+l] );
    T v = arr[l];
    
    //等于v部分：
    int test = l+1; // arr[i+1,...test-1] == v
    
    //小于v部分：
    int i = l; // arr[l+1,...,i] < v
    
    //大于v部分：
    int j = r+1;// arr[j,...,r] > v
    
    while(test < j)//当test == j的时候已经是全部检测完了。
    {
        if(arr[test] > v)
        {
            j--;
            swap(arr[test],arr[j]);
        }
        else if(arr[test] < v)
        {
            i++;
            swap(arr[test], arr[i]);
            test++;
        }
        else//arr[test] == v
        {
            test++;
        }
    }
    swap(arr[l], arr[i]);//如今：i-1是小于v的部分的最后一个元素， i 是等于v部分的第一个元素, test-1是等于v部分的最后一个元素，j 是大于v部分的第一个元素。
    
    __quickSort5(arr, l, i-1);
    __quickSort5(arr, j, r);
}

template<typename T>
void quickSort5(T arr[], int len)
{
    __quickSort5(arr, 0, len-1);
}

#endif /* QuickSort5_h */
