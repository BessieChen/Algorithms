//
//  SparseGraph.h
//  Graph
//
//  Created by 陈贝茜 on 2019/7/27.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef SparseGraph_h
#define SparseGraph_h

#include "iostream"
#include "vector"
#include "cassert"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class SparseGraph
{
private:
    int v;
    int e;
    bool directed;
    vector<vector<int>> graph;
    
public:
    SparseGraph(int v, bool directed)
    {
        this->v = v;
        this->e = 0;
        this->directed = directed;
        
        for(int i = 0; i < v; i++)
        {
            graph.push_back(vector<int>());
        }
    }
    
    ~SparseGraph()
    {
        
    }
    
    int V()
    {
        return v;
    }
    
    int E()
    {
        return e;
    }
    /**
     这个函数，是不能像densegraph那样z直接忽略平行边的。
     我们的sparsegraph这里涉及的是可以包含 平行边的
     这就导致了，我们不需要判断是否含有v1,v2: hasEdge(v1, v2)
     例如可以有两个1-3，1-3
     注意自环边不可以加两次。例如给的v1 = 5, v2 = 5，directed == false。只需要加一次就好了。
     */
    
    void addEdge(int v1, int v2)
    {
        assert(v1 >= 0 && v1 < v && v2 >= 0 && v2 < v);
        graph[v1].push_back(v2);
        if(!directed && v1 != v2)
            graph[v2].push_back(v1);
        e++;
    }
    
    bool hasEdge(int v1, int v2)
    {
        assert(v1 >= 0 && v1 < v && v2 >= 0 && v2 < v);
        
        for(int i = 0; i < graph[v1].size(); i++)
        {
            if(graph[v1][i] == v2)
                return true;
        }
        return false;
    }
    
    void show()
    {
        for(int i = 0; i < v; i++)
        {
            cout<<"vertex "<<i<<": ";
            for(int j = 0; j < graph[i].size(); j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    /*
     这个是用来当做遍历的，是指给定某个v顶点的遍历。
     */
    
    class adjIterator
    {
    private:
        SparseGraph &G;//需要一个引用
        int v;
        int index;
        
    public:
        adjIterator(SparseGraph &graph, int v):G(graph)//引用G可以用参数列表来初始化
        {
            this->index = 0;
            this->v = v;
        }
        
        int begin()
        {
            index = 0;//这里需要手动再次设为0，因为要防止用户重复使用adjIterator
            if(G.graph[v].size() == 0) return -1;//注意不是G[v]是G.graph[v]!!
            return G.graph[v][index];
        }
        
        bool end()
        {
            return index >= G.graph[v].size(); //当index == size-1时候已经到达终点。
        }
        
        int next()
        {
            if(end()) return -1;
            index++;
            return G.graph[v][index];
        }
    };
};

#endif /* SparseGraph_h */
