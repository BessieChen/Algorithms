//
//  ValueNumberK2Way.h
//  ValueNumberK
//
//  Created by 陈贝茜 on 2019/7/3.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef ValueNumberK2Way_h
#define ValueNumberK2Way_h

template<typename T>
int __partition2Way(T arr[], int l, int r)
{
    int randomIndex = rand() % (r-l+1) + l;
    swap(arr[l], arr[randomIndex]);
    
    T v = arr[l];
    int i = l+1;
    int j = r;
    
    while(i<=j)
    {
        while(j >= l+1 && arr[j] > v)
        {
            j--;
        }
        
        while(i <= r && arr[i] < v)
        {
            i++;
        }
        
        if(i <= j)
        {
            swap(arr[i], arr[j]);
        }
        else
        {
            break;
        }
        i++;
        j--;
    }
    swap(arr[l],arr[i-1]);
    
    if(i-j==1)
    {
        return j;
    }
    else//i-j==2
    {
        return j+1;
    }
}


template<typename T>
T __selection2Way(T arr[], int l, int r, int k)//这里的k指的是arr的k位置，而不是以left开头的k位置。并且这个k是 l <= k, k <= r;
{
    //首先要思考终止条件：
    if(l == r)//如果此时l == r，那么l也等于k，同样r也等于k
    {
        return arr[l];
    }
    
    int p = __partition2Way(arr, l, r);
    if(p == k)
    {
        return arr[p];
    }
    else if(p < k)
    {
        return __selection2Way(arr, p+1, r, k);
    }
    else//(k < p)
    {
        return __selection2Way(arr, l, p-1, k);//这里一定记得写return，而不是像之前习惯的，不写return，之前的递归函数是void类型，这里的是T类型。
        //你曾经思考过，有没有可能p本来就等于left，也就是partition之后p其实就是最左边的，然后同时k小于p，我回答你，不可能，因为从上一步的selection来的时候
        //就已经保证了k是大于等于本次的left的，所以如果本次的p就是等于left，k就不可能小于p，要么等于p，要么大于p
    }
}

template<typename T>
T selection2Way(T arr[], int len, int k)
{
    return __selection2Way(arr, 0, len-1, k);
}

template<typename T>
T selection2Way_IndexStartsFrom1(T arr[], int len, int k)
{
    return selection2Way(arr, len, k-1);
}


#endif /* ValueNumberK2Way_h */
