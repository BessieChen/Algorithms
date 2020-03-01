//
//  ShellSort.h
//  ShellSort
//
//  Created by 陈贝茜 on 2019/6/29.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef ShellSort_h
#define ShellSort_h

void ShellSort(int arr[], int len)
{
    int h = 1;
    while(h < len/3)
    {
        h = h*3+1; // thus h would be 1, 4, 13, 40, 121, 364, 1093...
    }
    
    while(h >= 1)
    {
        for(int i = h; i < len; i++)
        {
            int record = arr[i];
            int j;
            for(j = i; j-h >=0 && record<arr[j-h]; j-=h )
            {
                arr[j] = arr[j-h];
            }
            arr[j] = record;
        }
        h /= 3;
    }
}


//slow
void ShellSort_slow(int arr[], int len)
{
    int h = 1;
    while(h < len/3)
    {
        h = h*3+1; // thus h would be 1, 4, 13, 40, 121, 364, 1093...
    }
    
    while(h >= 1)
    {
        for(int i = h; i < len; i++)
        {
            for(int j = i; j-h >=0; j-=h )
            {
                if(arr[j] < arr[j-h])
                {
                    swap(arr[j], arr[j-h]);
                }
            }
        }
        h /= 3;
    }
}

#endif /* ShellSort_h */
