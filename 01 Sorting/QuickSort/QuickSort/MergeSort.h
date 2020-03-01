//
//  MergeSort.h
//  MergeSort
//
//  Created by 陈贝茜 on 2019/6/30.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

//这个是第1版的merge sort
#ifndef MergeSort_h
#define MergeSort_h

template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
    T *replicate = new T[r-l+1];
    //T replicate[r-l+1];
    
    for(int i = 0; i < r-l+1; i++)
    {
        replicate[i] = arr[l+i];
    }
    
    //说明：
    //arr的第left个元素 --> 相当于replicate的第0个元素,称为replicateLeft
    //arr的第mid+1个元素  --> 相当于replicate的第(mid+1)-left个元素，称为replicateMid
    //所以我设replicate的左部分探测器为int i，开始于0
    //设右部分探测器为int j，开始于(mid+1)-left
    //我设int k，添加到arr的第k个元素上的意思。
    int replicateLeft = l-l;//即0
    int replicateMid = mid+1-l;//右部分第一个u元素
    int replicateRight = r-l;
    int i = replicateLeft;
    int j = replicateMid;
    int k = l;
    while(k<=r)
    {
            if(i == replicateMid)//当i指向的新元素是replicateMid，那就是replicate左部分已经空了，然后右部分依次赋值就好了。
        {
            while(j <= replicateRight)
            {
                arr[k++] = replicate[j++];
            }
        }
        else if(j == replicateRight+1)//当j指向的新元素是replicateRight，那就是replicate右部分已经空了，然后左部分依次赋值就好了。
        {
            while(i <= replicateMid - 1)
            {
                arr[k++] = replicate[i++];
            }
        }
        else if(replicate[i] <= replicate[j])//此为正常情况：即左部分某元素 <= 右部分某元素
        {
            arr[k++] = replicate[i++];//赋值完后，k和i都要向右移一位
        }
        else//(replicate[i] > replicate[j])//此为不正常情况：即左部分某元素 > 右部分某元素
        {
            arr[k++] = replicate[j++];//赋值完后，k和j都要向右移一位
        }
    }
    delete []replicate;
}

template<typename T>
void __mergeSort(T arr[], int l, int r)
{
    if(l == r)
    {
        return;
    }
    
    int mid = l+(r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __merge(arr, l, mid, r);
}

template<typename  T>
void mergeSort(T arr[], int len)
{
    __mergeSort(arr, 0, len-1);
}





//
//using namespace std;
//
//
//// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
//template<typename  T>
//void __merge(T arr[], int l, int mid, int r){
//
//    //* VS不支持动态长度数组, 即不能使用 T aux[r-l+1]的方式申请aux的空间
//    //* 使用VS的同学, 请使用new的方式申请aux空间
//    //* 使用new申请空间, 不要忘了在__merge函数的最后, delete掉申请的空间:)
//    T aux[r-l+1];
//    //T *aux = new T[r-l+1];
//
//    for( int i = l ; i <= r; i ++ )
//        aux[i-l] = arr[i];
//
//    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
//    int i = l, j = mid+1;
//    for( int k = l ; k <= r; k ++ ){
//
//        if( i > mid ){  // 如果左半部分元素已经全部处理完毕
//            arr[k] = aux[j-l]; j ++;
//        }
//        else if( j > r ){  // 如果右半部分元素已经全部处理完毕
//            arr[k] = aux[i-l]; i ++;
//        }
//        else if( aux[i-l] < aux[j-l] ) {  // 左半部分所指元素 < 右半部分所指元素
//            arr[k] = aux[i-l]; i ++;
//        }
//        else{  // 左半部分所指元素 >= 右半部分所指元素
//            arr[k] = aux[j-l]; j ++;
//        }
//    }
//
//    //delete[] aux;
//}
//
//// 递归使用归并排序,对arr[l...r]的范围进行排序
//template<typename T>
//void __mergeSort(T arr[], int l, int r){
//
//    if( l >= r )
//        return;
//
//    int mid = (l+r)/2;
//    __mergeSort(arr, l, mid);
//    __mergeSort(arr, mid+1, r);
//    __merge(arr, l, mid, r);
//}
//
//template<typename T>
//void mergeSort(T arr[], int n){
//
//    __mergeSort( arr , 0 , n-1 );
//}
#endif /* MergeSort_h */
