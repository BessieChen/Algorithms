//
//  Component.h
//  Graph
//
//  Created by 陈贝茜 on 2019/7/28.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef Component_h
#define Component_h

template <typename Graph>
class Component
{
private:
    Graph &G;
    int v;
    int cCount;
    bool* isVisited;
    int* ID;
    
public:
    Component(Graph &G) : G(G)
    {
        this->v = G.graph.V();
        int cCount = 0;
        isVisited = new bool[v];
        for(int i = 0; i < v; i++) isVisited[i] = false;
        ID = new int[v];
    }
    
    ~Component()
    {
        delete[] isVisited;
        delete[] ID;
    }
    
    int Count()
    {
        for(int v1 = 0; v1 < v ; v1++)
        {
            typename Graph::adjIterator iter(G, v1);
            for(int v2 = iter.begin(); !iter.end(); v2 = iter.next())
            {
                if(!isVisited[v2 - 1])
                {
                    bfs(v2);//执行完这一步，也就是从一个节点v2入手的所有联通的节点都找到了。这里不需要担心我们还没有执行Count()中的v2 = iter.next()，因为bfs()函数中已经可以确保
                }
            }
        }
    
        return -1;
    }
    
private:
    void bfs(int v1)
    {
        isVisited[v1 - 1] = true;
        typename Graph::adjIterator iter(G, v1);
        for(int v2 = iter.begin(); !iter.end(); v2 = iter.next())
        {
            if(!isVisited[v2 - 1])
            {
                bfs(v2);
            }
        }
        return;
    }
};

#endif /* Component_h */
