//
//  main.cpp
//  SelectionSort
//
//  Created by 陈贝茜 on 2019/6/24.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"
using namespace std;


int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(a, 10);
    for(int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    // 测试模板函数，传入浮点数数组
    float b[4] = {4.4,3.3,2.2,1.1};
    selectionSort_general(b,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<b[i]<<" ";
    cout<<endl;
    
    // 测试模板函数，传入字符串数组
    char c[4] = {'D','C','B','A'};
    string e[4] = {"D","C","B","A"};
    selectionSort_general(c,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<c[i]<<" ";
    cout<<endl;
    
    Student d[4] = { {"D",90} , {"C",100} , {"B",95} , {"A",95} };
    selectionSort_general(d,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<d[i];
    cout<<endl;
    
    int N = 10000;
    int *arr = SortTestHelper::generateRandomArray(N, 0, N);
//    selectionSort_general(arr, N);
//    SortTestHelper::printArray(arr, N);
    SortTestHelper::testSort("Selection Sort", selectionSort_general, arr, N);
    delete[] arr;
    system("pause");
}

