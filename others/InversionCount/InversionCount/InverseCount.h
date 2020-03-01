//
//  InverseCount.h
//  InversionCount
//
//  Created by 陈贝茜 on 2019/7/2.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef InverseCount_h
#define InverseCount_h

// 计算逆序数对的结果以long long返回
// 对于一个大小为N的数组, 其最大的逆序数对个数为 N*(N-1)/2, 非常容易产生整型溢出
template<typename T>
long long __merge(T arr[], T replicate[], int l, int mid, int r)
{
    long long count = 0;
    for(int i = l; i <= r; i++)
    {
        replicate[i] = arr[i];
    }
    
    //method 1: while loop:
    int k = l;//这个k是用来更新arr的
    int i = l;//用来索引replicate左半部分
    int j = mid+1;//用来索引replicate右半部分
    while(k <= r)
    {
        //我们需要比较replciate[i]，replicate[j]的大小，但是，首先需要保证i,j的合法性即，i小于等于mid，j大于等于mid+1
        //如果合法，就比较replciate[i]，replicate[j]的大小，不合法就需要将另一侧直接依次赋值给arr
        if( i == mid+1)
        {
            while(j <= r)//锤子，这里不是while(j >= mid+1)啊！
            {
                arr[k++] = replicate[j++];//锤子，这里不是quickSort的双路和三路，所以不是j--啊！
            }
        }
        else if( j == r+1)
        {
            while( i <= mid)
            {
                arr[k++] = replicate[i++];
            }
        }
        else if(replicate[i] <= replicate[j])// 因为这里需要计算逆序对，所以左侧小于右侧，左侧等于右侧，都是不会影响到逆序对的。
        {
            arr[k++] = replicate[i++];
        }
        else if(replicate[i] > replicate[j])//这里影响逆序对的是，左侧的第i个元素到mid都是能添加逆序对个数的。
        {
            arr[k++] = replicate[j++];
            count += (long long)mid-i+1;
        }
    }
    
    return count;
    
}


template<typename T>
long long __inverseCount(T arr[], T replicate[], int l, int r)
{
    if(l == r)
    {
        return 0;
    }
    int mid = l + (r-l)/2;
    
    long long a = __inverseCount(arr, replicate, l, mid);
    long long b = __inverseCount(arr, replicate, mid+1, r);
    return a + b + __merge(arr, replicate, l, mid, r);
}


template<typename T>
long long inverseCount(T arr[], int len)
{
    T *replicate = new T[len];
    long long ret = __inverseCount(arr, replicate, 0, len-1);
    delete []replicate;
    return ret;
}
#endif /* InverseCount_h */



// merge函数求出在arr[l...mid]和arr[mid+1...r]有序的基础上, arr[l...r]的逆序数对个数
//long long __merge( int arr[], int l, int mid, int r){
//
//    int *aux = new int[r-l+1];
//    for( int i = l ; i <= r ; i ++ )
//        aux[i-l] = arr[i];
//
//    // 初始化逆序数对个数 res = 0
//    long long res = 0;
//    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
//    int j = l, k = mid + 1;
//    for( int i = l ; i <= r ; i ++ ){
//        if( j > mid ){ // 如果左半部分元素已经全部处理完毕
//            arr[i] = aux[k-l];
//            k ++;
//        }
//        else if( k > r ){ // 如果右半部分元素已经全部处理完毕
//            arr[i] = aux[j-l];
//            j ++;
//        }
//        else if( aux[j-l] <= aux[k-l] ){ // 左半部分所指元素 <= 右半部分所指元素
//            arr[i] = aux[j-l];
//            j ++;
//        }
//        else{ // 右半部分所指元素 < 左半部分所指元素
//            arr[i] = aux[k-l];
//            k ++;
//            // 此时, 因为右半部分k所指的元素小
//            // 这个元素和左半部分的所有未处理的元素都构成了逆序数对
//            // 左半部分此时未处理的元素个数为 mid - j + 1
//            res += (long long)(mid - j + 1);
//        }
//    }
//
//    delete[] aux;
//
//    return res;
//}
//
//// 求arr[l..r]范围的逆序数对个数
//// 思考: 归并排序的优化可否用于求逆序数对的算法? :)
//long long __inversionCount(int arr[], int l, int r){
//
//    if( l >= r )
//        return 0;
//
//    int mid = l + (r-l)/2;
//
//    // 求出 arr[l...mid] 范围的逆序数
//    long long res1 = __inversionCount( arr, l, mid);
//    // 求出 arr[mid+1...r] 范围的逆序数
//    long long res2 = __inversionCount( arr, mid+1, r);
//
//    return res1 + res2 + __merge( arr, l, mid, r);
//}
//
//// 递归求arr的逆序数对个数
//long long inversionCount(int arr[], int n){
//
//    return __inversionCount(arr, 0, n-1);
//}
