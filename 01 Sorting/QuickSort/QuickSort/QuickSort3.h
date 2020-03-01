//
//  QuickSort3.h
//  QuickSort
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

//第3版，双路排序，未优化
#ifndef QuickSort3_h
#define QuickSort3_h

template<typename T>
int __partition3(T arr[], int l, int r)
{
    T v = arr[l];
    int i = l+1;
    int j = r;
    
    while(i <= j) //1. 走到这一步，说明此时的i和j都是等待检测的位置。 2.i==j也是y需要进入while的，因为我们要看看最后这个即==i又==j的值，到底属于哪个部队。
    {
        while(j >= l+1 && arr[j] > v)
        {
            j--;
        }
        //此时跳出while loop的j代表着不属于右侧部队。
        
        while(i <= r && arr[i] < v)
        {
            i++;
        }
        //此时跳出while loop的i代表着不属于左侧部队。
        if(i <= j)
        {
            swap(arr[i], arr[j]);//之所以
            //交换完之后，i和j所在的元素，就是位于正确位置的元素了。因为我们line19，也就是最外面的大while loop的while(i <= j)
            //需要i和j表示等待检测的位置，所以我们要更新i和j
            i++;
            j--;
        }
        else{
            break;
        }
    }
    //methd 1:
//    swap(arr[l], arr[i-1]);
//    return i-1;
    
    //emthod 2:
    swap(arr[l], arr[j]);//你可以看的出来，我们从上面的while loop出来的时候，就i-1才是最后一个合格的元素，j也是最后一个合格的元素，所以是和i-1或者j交换。为什么不是j+1？
    return j;
}

template<typename T>
void __quickSort3(T arr[], int l, int r)
{
    if(l >= r)
    {
        return;
    }
    
    int p = __partition3(arr, l, r);
    __quickSort3(arr, l, p-1);
    __quickSort3(arr, p+1, r);
}

template<typename T>
void quickSort3(T arr[], int len)
{
    __quickSort3(arr, 0, len-1);
}
#endif /* QuickSort3_h */
