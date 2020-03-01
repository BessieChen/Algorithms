//
//  QuickSortCompare.h
//  QuickSort
//
//  Created by 陈贝茜 on 2019/7/1.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "QuickSort2.h"
#include "QuickSort3.h"
#include "QuickSort4.h"
#include "QuickSort5.h"
#include "QuickSort6.h"
#include "ShellSort.h"

using namespace std;

#ifndef QuickSortCompare_h
#define QuickSortCompare_h

// 比较 Shell Sort 和 Merge Sort 和 三种 Quick Sort 的性能效率
// 使用更科学的比较方式, 每次比较都运行多次测试用例, 取平均值
// 可以看出, Shell Sort虽然慢于高级的排序方式, 但仍然是非常有竞争力的一种排序算法
// 其所花费的时间完全在可以容忍的范围内, 远不像O(n^2)的排序算法, 在数据量较大的时候无法忍受
// 同时, Shell Sort实现简单, 只使用循环的方式解决排序问题, 不需要实现递归, 不占用系统占空间, 也不依赖随机数
// 所以, 如果算法实现所使用的环境不利于实现复杂的排序算法, 或者在项目工程的测试阶段, 完全可以暂时使用Shell Sort来进行排序任务:)
void test() {
    
    // 测试T个测试用例, 每个测试用例的数组大小为n
    int T = 100;
    int n = 1000000;
    
    // 比较 Shell Sort 和 Merge Sort 和 三种 Quick Sort 的性能效率
    double time1 = 0.0, time2 = 0.0, time3 = 0.0, time4 = 0.0, time5 = 0.0;
    for( int i = 0 ; i < T ; i ++ ) {
        int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
        int *arr2 = SortTestHelper::copyIntArray(arr1, n);
        int *arr3 = SortTestHelper::copyIntArray(arr1, n);
        int *arr4 = SortTestHelper::copyIntArray(arr1, n);
        int *arr5 = SortTestHelper::copyIntArray(arr1, n);
        
        time1 += SortTestHelper::testSort(shellSort, arr1, n);
        time2 += SortTestHelper::testSort(mergeSort, arr2, n);
        time3 += SortTestHelper::testSort(quickSort, arr3, n);
        time4 += SortTestHelper::testSort(quickSort4, arr4, n);
        time5 += SortTestHelper::testSort(quickSort5, arr5, n);
        
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        delete[] arr5;
    }
    
    cout << endl;
    cout << "Sorting "<<n<<" elements "<<T<<" times. Calculate the average run time."<<endl;
    cout << "Shell Sort Average Run Time: " << time1/T << " s"<<endl;
    cout << "Merge Sort Average Run Time: " << time2/T << " s"<<endl;
    cout << "Quick Sort Average Run Time: " << time3/T << " s"<<endl;
    cout << "Quick Sort 2 Ways Average Run Time: " << time4/T << " s"<<endl;
    cout << "Quick Sort 3 Ways Average Run Time: " << time5/T << " s"<<endl;
}
#endif /* QuickSortCompare_h */
