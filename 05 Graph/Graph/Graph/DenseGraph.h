//
//  DenseGraph.h
//  Graph
//
//  Created by 陈贝茜 on 2019/7/27.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

/*
 目录：
 1. int v是代表着顶点的编号从0->v-1;
 */
#ifndef DenseGraph_h
#define DenseGraph_h

#include "iostream"
#include "vector"
#include "cassert"

using std::vector;


class DenseGraph
{
private:
    int v;
    int e;
    bool directed;
    vector<vector<bool>> graph;
    
public:
    DenseGraph(int v, bool directed)
    {
        this->v = v;
        this->e = 0;
        this->directed = directed;
        for(int i = 0; i < v; i++)
            graph.push_back(vector<bool>(v, false));
    }
    
    ~DenseGraph()
    {}
    
    int V()
    {
        return v;
    }
    
    int E()
    {
        return e;
    }
    
    void addEdge(int v1, int v2)
    {
        assert(v1 >= 0 && v1 < v && v2 >= 0 && v2 < v);
        if(hasEdge(v1, v2))
            return;
        
        graph[v1][v2] = true;
        if(!directed && v1 != v2)
        {
            graph[v2][v1] = true;
        }
        e++;
    }
    
    bool hasEdge(int v1, int v2)
    {
        assert(v1 >= 0 && v1 < v && v2 >= 0 && v2 < v); 
        return graph[v1][v2];
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
    
    class adjIterator
    {
    private:
        DenseGraph &G;
        int v;
        int index;
        
    public:
        adjIterator(DenseGraph &graph, int v) : G(graph)//引用G可以用参数列表来初始化
        {
            this->index = 0;
            this->v = v;
        }
        
        int begin()
        {
            index = -1;
            return next();
        }
        
        bool end()
        {
            //method 1:
            //return index >= G.graph[v].size();
            
            //method 2:
            return index >= G.V(); //矩阵是正方形的。
        }
        
        int next()
        {
            //method 1:
            //            for(index++; index < G.V(); index++)//先将index += 1，再判断 == true。配合main中的: for(int v2 = iter.begin(); !iter.end(); v2 = iter.next())
//            
//            {
//                if(G.graph[v][index] == true)
//                {
//                    return index;
//                }
//            }
//            return -1;
            
            //method 2: ByB
            index++;
            if(end()) return -1;
            if(G.graph[v][index] == false)
            {
                return next();
            }
            return index;//走到这里，说明G.graph[v][index] == true;
        }
        
    };
};

#endif /* DenseGraph_h */
