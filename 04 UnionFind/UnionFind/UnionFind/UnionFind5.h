//
//  UnionFind5.h
//  UnionFind
//
//  Created by 陈贝茜 on 2019/8/20.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef UnionFind5_h
#define UnionFind5_h

#include <iostream>
#include <cassert>

using namespace std;

namespace UF5
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
            
            //method 1:
//            while(x != parent[x])
//            {
//                parent[x] = parent[parent[x]];
//                x = parent[x];
//            }
//            return x;
            
            //method 2:
            if(x != parent[x]) parent[x] = find(parent[x]); //注意：这里的是递归，又去调用本函数find().所以切记不能写成：if(x != parent[x]) parent[x] = find(x);
                //因为这样写是废话！
            return parent[x];
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
        
        void show(){
            for( int i = 0 ; i < size ; i ++ )
                cout<<i<<" : "<<parent[i]<<endl;
        }
    };
}

#endif /* UnionFind5_h */
