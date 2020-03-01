//
//  main.cpp
//  InversionCount
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#include <iostream>
#include "TestHelper.h"
#include "InverseCount.h"
using namespace std;

int main() {
    
    int n = 1000000;
    
    // 测试1: 测试随机数组
    cout<<"Test Inversion Count for Random Array, n = "<<n<<" :"<<endl;
    int* arr = TestHelper::generateRandomArray(n, 0, n);
    cout<<inverseCount(arr, n)<<endl<<endl;
    delete[] arr;
    
    // 测试2: 测试完全有序的数组
    // 结果应该为0
    cout<<"Test Inversion Count for Ordered Array, n = "<<n<<" :"<<endl;
    arr = TestHelper::generateOrderedArray(n);
    cout<<inverseCount(arr, n)<<endl<<endl;
    delete[] arr;
    
    // 测试3: 测试完全逆序的数组
    // 结果应改为 N*(N-1)/2
    cout<<"Test Inversion Count for Inversed Array, n = "<<n<<" :"<<endl;
    arr = TestHelper::generateInversedArray(n);
    cout<<inverseCount(arr, n)<<endl;
    delete[] arr;
    
    return 0;
}
