
//
//  MaxHeap.h
//  MaxHeap_cpp
//
//  Created by 陈贝茜 on 2019/7/24.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef MaxHeap_h
#define MaxHeap_h

#include <algorithm>
#include <cassert>

using namespace std;

using std::cout;
using std::cin;
using std::endl;

template <typename E>
class MaxHeap
{
private:
    E* data;
    int size;
    int capacity;
    
public:
    MaxHeap(int cap)
    {
        capacity = cap;
        data = new E[capacity];
        size = 0;
    }
    
    MaxHeap()
    {
        capacity = 10;
        data = new E[capacity];
        size = 0;
    }
    
    //    MaxHeap(E* arr, int len)
    //    {
    //        capacity = len;
    //        data = new E[capacity];
    //        for(int i = 0; i < len; i++)
    //        {
    //            data[i] = arr[i];
    //        }
    //        size = capacity;
    //        for(int i = parent(size-1); i >= 0; i--)
    //            siftDown(i);
    //    }
    //
    MaxHeap(E arr[], int n){
        data = new E[n];
        capacity = n;
        
        for( int i = 0 ; i < n ; i ++ )
            data[i] = arr[i];
        size = n;
        
        for( int i = parent(size-1) ; i >= 0 ; i -- )
            siftDown(i);
    }
    
    
    ~MaxHeap()
    {
        delete [] data;
    }
    
    int getSize()
    {
        return size;
    }
    
    bool isEmpty()
    {
        return size == 0;
    }
    
    
    void add(E e)
    {
        data[size] = e;
        siftUp(size);
        size++;
        if(size == capacity)
        {
            resize(capacity * 2);
        }
    }
    
    E extractMax()
    {
        E ret = data[0];
        data[0] = data[size-1];
        size--;
        siftDown(0);
        return ret;
    }
    
    E getFront()
    {
        return data[0];
    }
    
private:
    int parent(int index)
    {
        return (index-1)/2;
    }
    
    int leftChild(int index)
    {
        return index*2+1;
    }
    
    int rightChild(int index)
    {
        return index*2+2;
    }
    
    void siftUp(int index)
    {
        int oldIndex = index;
        int sw = index;
        while(index != 0)
        {
            if(data[parent(index) > data[index]])
                break;
            sw = parent(index);
            index = parent(index);
        }
        swap(data[sw], data[oldIndex]);
    }
    
    void resize(int newCap)
    {
        E* newData = new E[newCap];
        for(int i = 0; i < size-1; i++)
        {
            newData[i] = data[i];
        }
        data = newData;
    }
    
    void siftDown(int index)
    {
        int oldIndex = index;
        int sw = oldIndex;
        
        while(leftChild(index) < size)
        {
            int l = leftChild(index);
            if(l+1 < size && data[l] < data[l+1])
                l++;
            
            if(data[l] < data[index])
                break;
            
            sw = l;
            index = l;
        }
        swap(data[oldIndex], data[sw]);
    }
    
    
};

#endif /* MaxHeap_h */
