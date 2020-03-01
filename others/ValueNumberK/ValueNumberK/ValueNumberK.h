//
//  ValueNumberK.h
//  ValueNumberK
//
//  Created by 陈贝茜 on 2019/7/2.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef ValueNumberK_h
#define ValueNumberK_h

template<typename T>
int __partition(T arr[], int l, int r)//适合无重复元素的简单的快排
{
    int randomIndex = rand() % (r-l+1) + l;
    swap(arr[l], arr[randomIndex]);
    
    T v = arr[l];
    int i = l;
    int test = l+1;
    
    while(test <= r)
    {
        if(arr[test] < v)
        {
            swap(arr[++i], arr[test++]);
        }
        else
        {
            test++;
        }
    }
    swap(arr[i],arr[l]);
    return i;
}

template<typename T>
T __selection(T arr[], int l, int r, int k)//这里的k指的是arr的k位置，而不是以left开头的k位置。并且这个k是 l <= k, k <= r;
{
    //首先要思考终止条件：
    if(l == r)//如果此时l == r，那么l也等于k，同样r也等于k
    {
        return arr[l];
    }
    
    int p = __partition(arr, l, r);
    
    if(p == k)
    {
        return arr[p];
    }
    else if(p < k)
    {
        return __selection(arr, p+1, r, k);
    }
    else//(k < p)
    {
        return __selection(arr, l, p-1, k);//这里一定记得写return，而不是像之前习惯的，不写return，之前的递归函数是void类型，这里的是T类型。
        //你曾经思考过，有没有可能p本来就等于left，也就是partition之后p其实就是最左边的，然后同时k小于p，我回答你，不可能，因为从上一步的selection来的时候
        //就已经保证了k是大于等于本次的left的，所以如果本次的p就是等于left，k就不可能小于p，要么等于p，要么大于p
    }
}

template<typename T>
T selection(T arr[], int len, int k)
{
    return __selection(arr, 0, len-1, k);
}

template<typename T>
T selection_IndexStartsFrom1(T arr[], int len, int k)
{
    return selection(arr, len, k-1);
}


#endif /* ValueNumberK_h */
