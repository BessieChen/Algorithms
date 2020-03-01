//
//  MergeSort3.h
//  MergeSort
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

//这个是第3版的merge sort:做了优化，小数组用insertion sort，并仅当arr[mid] > arr[mid+1]时候才merge
#ifndef MergeSort3_h
#define MergeSort3_h
#include "InsertionSort.h"

template<typename T>
void __merge3(T arr[], T replicate[], int l, int mid, int r)
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
        else if(j == r+1)
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
void __mergeSort3(T arr[], T replicate[], int l, int r)
{
    if(r - l <= 16)
    {
        new_insertionSort(arr, l, r);
        return;
    }
    else
    {
        int mid = l+(r-l)/2;
        __mergeSort3(arr, replicate, l, mid);
        __mergeSort3(arr, replicate, mid + 1, r);
        if(arr[mid] > arr[mid+1])
        {
            __merge3(arr, replicate, l, mid, r);
        }
    }

}

template<typename  T>
void mergeSort3(T arr[], int len)
{
    T *replicate = new T[len];
    __mergeSort3(arr, replicate, 0, len-1);
    delete []replicate;
}


//using namespace std;
//
//template<typename T>
//void __merge3(T arr[], T replicate[], int l, int mid, int r)
//{
//    for(int i = l; i <= r; i++)
//    {
//        replicate[i] = arr[i];
//    }
//    int i = l;
//    int j = mid+1;
//    int k = l;
//    while(k <= r)
//    {
//        if(i == mid+1)
//        {
//            while(j <= r)
//            {
//                arr[k++] = replicate[j++];
//            }
//        }
//        else if(j == r+1)
//        {
//            while(i <= mid)
//            {
//                arr[k++] = replicate[i++];
//            }
//        }
//        else if(replicate[i] <= replicate[j] && i <= mid && j <= r)
//        {
//            arr[k++] = replicate[i++];
//        }
//        else if(replicate[i] > replicate[j] && i <= mid && j <= r)
//        {
//            arr[k++] = replicate[j++];
//        }
//    }
//}
//
//// 使用优化的归并排序算法, 对arr[l...r]的范围进行排序
//template<typename T>
//void __mergeSort3(T arr[], int l, int r){
//
//    // 优化2: 对于小规模数组, 使用插入排序
//    if( r - l <= 15 ){
//        insertionSort(arr, l, r);
//        return;
//    }
//
//    int mid = (l+r)/2;
//    __mergeSort3(arr, l, mid);
//    __mergeSort3(arr, mid+1, r);
//
//    // 优化1: 对于arr[mid] <= arr[mid+1]的情况,不进行merge
//    // 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
//    if( arr[mid] > arr[mid+1] )
//        __merge3(arr, l, mid, r);
//}
//
//template<typename T>
//void mergeSort3(T arr[], int n){
//
//    __mergeSort3( arr , 0 , n-1 );
//}
//


#endif /* MergeSort3_h */
