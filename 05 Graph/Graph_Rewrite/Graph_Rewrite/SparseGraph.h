//
//  SparseGraph.h
//  Graph_Rewrite
//
//  Created by 陈贝茜 on 2019/8/21.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef SparseGraph_h
#define SparseGraph_h


#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class SparseGraph
{
private:
    int n;
    int m;
    bool directed;
    vector<vector<int>> graph;
    
public:
    SparseGraph(int n, bool directed)
    {
        this->n = n;
        this->directed = directed;
        for(int i = 0; i < n; i++)
        {
            graph.push_back(vector<int>());
        }
    }
    
    ~SparseGraph()
    {
        
    }
    
    int V()
    {
        return n;
    }
    
    int E()
    {
        return m;
    }
    
    void addEdge(int v, int w)
    {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        
        if(hasEdge(v,w)) return;//加上这一句:消灭了平行边 + 自环边，也就是一旦有一个条v-w的边，以后都不可以加了
        graph[v].push_back(w);
        if(v != w && !directed) graph[w].push_back(v);//加上了v != w不是消灭了自环边，而是说你没有必要加两次，在一个节点上。
        m++;
    }
    
    bool hasEdge(int v, int w)
    {
        for(int i = 0; i < graph[v].size(); i++)
        {
            if(graph[v][i] == w) return true;
        }
        return false;
    }
    
    void show()
    {
        for(int i = 0; i < n; i ++)
        {
            cout<<i<<": ";
            for(int j = 0 ; j < graph[i].size()-1; j++)
            {
                cout<<graph[i][j]<<", ";
            }
            cout<<graph[i][graph[i].size()-1];
            cout<<endl;
        }
    }
    
    class adjIterator
    {
    private:
        SparseGraph &G;
        int v;
        int index;
        
    public:
        adjIterator(SparseGraph &graph, int v):G(graph)
        {
            this->v = v;
            this->index = 0;
        }
        
        ~adjIterator()
        {
            
        }
        
        int begin()
        {
            index = 0;
            if(G.graph[v].size() == 0) return -1;
            return G.graph[v][index];
        }
        
        bool end()
        {
            return index >= G.graph[v].size();
        }
        
        int next()
        {
            index++;
            if(end()) return -1;
            return G.graph[v][index];
        }
        
    };
};


#endif /* SparseGraph_h */
