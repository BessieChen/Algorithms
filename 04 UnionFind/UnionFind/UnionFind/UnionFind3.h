//
//  UnionFind3.h
//  UnionFind
//
//  Created by 陈贝茜 on 2019/8/20.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef UnionFind3_h
#define UnionFind3_h

#include <iostream>
#include <cassert>

using namespace std;

namespace UF3
{
    class UnionFind
    {
    private:
        int* parent;
        int size;
        int* groupSize;
        
    public:
        UnionFind(int size)
        {
            this->size = size;
            parent = new int[size];
            groupSize = new int[size];
            for(int i = 0; i < size; i++)
            {
                parent[i] = i;
                groupSize[i] = 1;
            }
        }
        
        ~UnionFind()
        {
            delete[] parent;
            delete[] groupSize;
        }
        
        int find(int x)//所以parent[x]还只是x的父亲，还不是x的老大。
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
            if(groupSize[xR] >= groupSize[yR])
            {
                parent[yR] = xR;
                groupSize[xR] += groupSize[yR];
            }
            else
            {
                parent[xR] = yR;
                groupSize[yR] += groupSize[xR];
            }
        }
        
    };
}

#endif /* UnionFind3_h */
