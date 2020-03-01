//
//  UnionFind1.h
//  UnionFind
//
//  Created by 陈贝茜 on 2019/8/20.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef UnionFind1_h
#define UnionFind1_h

#include <cassert>
#include <iostream>

using namespace std;

namespace UF1
{
    class UnionFind
    {
    private:
        int* id;
        int size;
        
    public:
        UnionFind(int size)
        {
            this->size = size;
            id = new int[size];
            for(int i = 0; i < size; i++)
                id[i] = i;
        }
        
        ~UnionFind()
        {
            delete[] id;
        }
        
        int find(int x)
        {
            assert( x >= 0 && x < size);
            return id[x];
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
            for(int i = 0; i <size; i++)
            {
                if(id[i] == xR) id[i] = yR;
            }
        }
        
    };
}

#endif /* UnionFind1_h */
