//
//  SelectionSort.h
//  SelectionSort
//
//  Created by 陈贝茜 on 2019/6/27.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef SelectionSort_h
#define SelectionSort_h

#include <iostream>

using namespace std;

void selectionSort(int arr[], int len)
{
    int lowest;
    //寻找[i, len)区间里的最小值：
    for(int i = 0; i < len; i++)
    {
        lowest = i;
        for(int j = i + 1; j < len; j++)//最好不要是for(int j = lowest + 1; j < n; j++), 因为我们后面lowest要随时记录打怪的最低值
        {
            if(arr[j] < arr[lowest])//打怪成功
            {
                lowest = j;
            }
        }
        swap(arr[lowest], arr[i]);//此轮打怪的获胜者坐到最前面。
    }
}

template <typename T>// 这个typename一定要定义到模板函数的上方。
void selectionSort_general(T arr[], int len)//模板函数
{
    int lowest;
    //寻找[i, len)区间里的最小值：
    for(int i = 0; i < len; i++)
    {
        lowest = i;
        for(int j = i + 1; j < len; j++)//最好不要是for(int j = lowest + 1; j < n; j++), 因为我们后面lowest要随时记录打怪的最低值
        {
            if(arr[j] < arr[lowest])//打怪成功
            {
                lowest = j;
            }
        }
        swap(arr[lowest], arr[i]);//此轮打怪的获胜者坐到最前面。
    }
}



#endif /* SelectionSort_h */
