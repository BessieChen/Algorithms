//
//  ValueNumberK3Way.h
//  ValueNumberK
//
//  Created by 陈贝茜 on 2019/7/3.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef ValueNumberK3Way_h
#define ValueNumberK3Way_h
template<typename T>
int __partition3Way(T arr[], int l, int r, int &equalStart)
{
    int randomIndex = rand() % (r-l+1) + l;
    swap(arr[l], arr[randomIndex]);
    
    T v = arr[l];
    int i = l;
    int j = r+1;
    int test = l+1;
    
    while(test < j)//当test == j的时候已经是全部检测完了。 我之前错写成了test <= j, 这就会导致错误，因为假如说
        //test到了最后一个没有检测的元素，也就是此时test == j-1，如果执行了line 36，j--，这时test不动
        //所以当while再次进入while loop，如果条件是test <= j,那么我们还会执行line 36的东西，此时j再次j--，所以返回的值就不对了。
    {
        if(arr[test] < v)
        {
            swap(arr[++i], arr[test++]);
        }
        else if(arr[test] == v)
        {
            test++;
        }
        else//v < arr[test]
        {
            swap(arr[--j],arr[test]);
        }
    }
    swap(arr[l], arr[i]);
    equalStart = i;
    assert(equalStart == j-1);
    
    return j-1;
    
}

template<typename T>
T __selection3Way(T arr[], int l, int r, int k)//这里的k指的是arr的k位置，而不是以left开头的k位置。并且这个k是 l <= k, k <= r;
{
    //首先要思考终止条件：
    if(l == r)//如果此时l == r，那么l也等于k，同样r也等于k
    {
        return arr[l];
    }
    int equalStart;
    int equalEnd = __partition3Way(arr, l, r, equalStart);
    if(equalEnd == k)
    {
        return arr[equalEnd];
    }
    else if(equalEnd < k)
    {
        return __selection3Way(arr, equalEnd+1, r, k);//这里一定记得写return，而不是像之前习惯的，不写return，之前的递归函数是void类型，这里的是T类型。
    }
    else//(k < p)
    {
        return __selection3Way(arr, l, equalStart-1, k);
        //你曾经思考过，有没有可能p本来就等于left，也就是partition之后p其实就是最左边的，然后同时k小于p，我回答你，不可能，因为从上一步的selection来的时候
        //就已经保证了k是大于等于本次的left的，所以如果本次的p就是等于left，k就不可能小于p，要么等于p，要么大于p
    }
}
template<typename T>
T selection3Way(T arr[], int len, int k)
{
    return __selection3Way(arr, 0, len-1, k);
}

template<typename T>
T selection3Way_IndexStartsFrom1(T arr[], int len, int k)
{
    return selection3Way(arr, len, k-1);
}


#endif /* ValueNumberK3Way_h */
