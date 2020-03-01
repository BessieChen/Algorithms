//
//  Component.h
//  Graph_Rewrite
//
//  Created by 陈贝茜 on 2019/8/21.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef Component_h
#define Component_h

/*
 2019.8.21
 需要注意的几件事：
 1.你发现DenseGraph和SparseGraph里面都需要设置adjIterator，这是因为它们的实现方法不一样，所以要分别设计。
   但是它们的名字相同都是adjIterator，方便我们之后Component的模板类调用。
 2.但是这里Component我们设计了一个Graph模板类，这是因为，求Component需要遍历某个节点的方法，所以用adjIterator
 3.注意，我们的求Component是在构造函数中就已经完成的。用了dfs(),其中一个是在构造函数中初始dfs(),之后再在dfs()里面自己递归
 4.我们剩余的count(), isConnected()直接就可以用我们在构造函数中的结果。
 */
#include <iostream>
#include <cassert>

using namespace std;

template <typename Graph>
class Component
{
private:
    bool* visited;
    int cCount;
    int* id;
    Graph G;
    int n;
    
    void dfs(int v)
    {
        visited[v] = true;
        id[v] = cCount;
        typename Graph::adjIterator adj(G, v);
        for(int i = adj.begin(); !adj.end(); i = adj.next())
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
    }
    
public:
    Component(Graph g):G(g)
    {
        n = G.n;
        visited = new bool[n];
        cCount = 0;
        id = new int[n];
        for(int i = 0 ; i < n; i++)
        {
            visited[i] = false;
            id[i] = -1;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i);
                cCount++;
            }
        }
        
    }
    
    ~Component()
    {
        delete[] visited;
        delete[] id;
    }
    
    int count()//注意，如果我们的函数名字是count，那就不能有一个成员变量也叫count，所以我成员变量改成了cCount
    {
        return cCount;
    }
    
    bool isConnected(int v, int w)
    {
        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        assert( id[v] != -1 && id[w] != -1 );
        return id[v] == id[w];
    }
};


#endif /* Component_h */
