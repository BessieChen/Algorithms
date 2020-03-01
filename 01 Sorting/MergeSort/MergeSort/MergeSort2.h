//
//  MergeSort2.h
//  MergeSort
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

//这个是第2版的merge sort：将replicate数组的声明设在了最外面。
#ifndef MergeSort2_h
#define MergeSort2_h
template<typename T>
void __merge2(T arr[], T replicate[], int l, int mid, int r)
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
void __mergeSort2(T arr[], T replicate[], int l, int r)
{
    if(l == r)
    {
        return;
    }
    int mid = l+(r-l)/2;
    __mergeSort2(arr, replicate, l, mid);
    __mergeSort2(arr, replicate, mid + 1, r);
    __merge2(arr, replicate, l, mid, r);
}

template<typename  T>
void mergeSort2(T arr[], int len)
{
    T *replicate = new T[len];
    __mergeSort2(arr, replicate, 0, len-1);
    delete []replicate;
}

#endif /* MergeSort2_h */


//Test for random array, size = 50000, random range [0, 50000]
//Insertion Sort : 1.34523s
//Merge Sort : 0.014479s
//Merge Sort 2 : 0.008923s
//
//Test for nearly ordered array, size = 50000, swap time = 10
//Insertion Sort : 0.001373s
//Merge Sort : 0.009073s
//Merge Sort 2 : 0.004193s
//Program ended with exit code: 0
