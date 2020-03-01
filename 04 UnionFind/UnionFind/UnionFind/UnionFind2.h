//
//  UnionFind2.h
//  UnionFind
//
//  Created by 陈贝茜 on 2019/8/20.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef UnionFind2_h
#define UnionFind2_h

#include <cassert>
#include <iostream>

using namespace std;

namespace UF2
{
    class UnionFind
    {
    private:
        int* parent;
        int size;
        
    public:
        UnionFind(int size)
        {
            this->size = size;
            parent = new int[size];
            for(int i = 0 ; i < size ; i++)
            {
                parent[i] = i;
            }
        }
        
        ~UnionFind()
        {
            delete[] parent;
        }
        
        int find(int x)
        {
            assert(x >=0 && x < size);
            while(x != parent[x])
                x = parent[x];
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
            parent[xR] = yR;
        }
    };
}



#endif /* UnionFind2_h */
