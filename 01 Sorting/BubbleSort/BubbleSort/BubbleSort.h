//
//  BubbleSort.h
//  BubbleSort
//
//  Created by 陈贝茜 on 2019/6/28.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h

//method 1: do while
void bubbleSort(int arr[], int len)
{
    bool flag;
    do {
        flag = false;
        for(int j = 0; j <= len-2; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        len--;
    } while (flag);
}

//method 2: optimized
void bubbleSort2(int arr[], int len)
{
    int newN;
    do {
        newN = 0;
        for(int j = 0; j <= len-2; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                newN = j+1;
            }
        }
        len = newN;
    } while (newN>0);
}


template<typename T>
void bubbleSort_teacher( T arr[] , int n){

    bool swapped;

    do{
        swapped = false;
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i-1] > arr[i] ){
                swap( arr[i-1] , arr[i] );
                swapped = true;

            }

        // 优化, 每一趟Bubble Sort都将最大的元素放在了最后的位置
        // 所以下一次排序, 最后的元素可以不再考虑
        n --;

    }while(swapped);
}

// 我们的第二版bubbleSort,使用newn进行优化
template<typename T>
void bubbleSort_teacher2( T arr[] , int n){
    
    int newn; // 使用newn进行优化
    
    do{
        newn = 0;
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i-1] > arr[i] ){
                swap( arr[i-1] , arr[i] );
                
                // 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
                newn = i;
            }
        n = newn;
    }while(newn > 0);
}


//slow
void bubbleSort_right_slow1(int arr[], int len)
{
    for(int i = len; i >= 2; i--)
    {
        for(int j = 0; j <= i - 2; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


//slow
void bubbleSort_right_slow2(int arr[], int len)
{
    for(int i = len; i >= 2; i--)
    {
        int large = arr[0];
        int j;
        for( j = 0; j <= i - 2; j++)
        {
            if(large > arr[j+1])
            {
                arr[j] = arr[j+1];
            }
            else
            {
                large = arr[j+1];
            }
        }
        arr[j] = large;
    }
}

#endif /* BubbleSort_h */
