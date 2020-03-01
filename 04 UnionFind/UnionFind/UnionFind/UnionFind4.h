//
//  UnionFind4.h
//  UnionFind
//
//  Created by 陈贝茜 on 2019/8/20.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef UnionFind4_h
#define UnionFind4_h

#include <iostream>
#include <cassert>

using namespace std;

namespace UF4
{
    class UnionFind
    {
    private:
        int* parent;
        int size;
        int* height;
        
    public:
        UnionFind(int size)
        {
            this->size = size;
            parent = new int[size];
            height = new int[size];
            for(int i = 0; i < size; i++)
            {
                parent[i] = i;
                height[i] = 1;
            }
        }
        
        ~UnionFind()
        {
            delete[] parent;
            delete[] height;
        }
        
        int find(int x)
        {
            assert(x >= 0 && x < size);
            while(x != parent[x]) x = parent[x];
            return x;
        }
        
        bool isConnected(int x, int y)
        {
            return find(x) == find(y);
        }
        
        void unionElements(int x, int y)
        {
            int xR = find(x);
            int yR = find(y);
            if(xR == yR) return;
            if(height[xR] < height[yR])
            {
                parent[xR] = yR;
            }
            else if(height[yR] < height[xR])
            {
                parent[yR] = xR;
            }
            else
            {
                parent[yR] = xR;
                height[xR]++;
            }
        }
    };
}
#endif /* UnionFind4_h */
