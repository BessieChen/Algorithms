//
//  DenseGraph.h
//  Graph_Rewrite
//
//  Created by 陈贝茜 on 2019/8/21.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef DenseGraph_h
#define DenseGraph_h

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class DenseGraph
{
private:
    int n;//节点个数
    int m;//边个数
    bool directed;
    vector<vector<bool>> graph;
    
public:
    DenseGraph(int n, bool directed)
    {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        //graph = new vector<bool>(n);不能这么写！因为你()括号里面的n可不是vector<bool>(),我们最外层的vector里面需要的也是vector
        for(int i = 0; i < n; i++)
        {
            graph.push_back(vector<bool>(n, false));
        }
    }
    
    ~DenseGraph()
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
        
        if(!hasEdge(v, w))//注意，我们的矩阵自动忽略 平行边+自环边
        {
            graph[v][w] = true;
            if(!directed) graph[w][v] = true;//这里不需要加if( v != w && !directed),因为本身就自动忽略自环边：v==w的情况
            m++;
        }
    }
    
    void addEdge2(int v, int w)
    {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        
        if(hasEdge(v, w)) return;
        
        graph[v][w] = true;
        if(!directed) graph[w][v] = true;//这里不需要加if( v != w && !directed),因为本身就自动忽略自环边：v==w的情况
        m++;
    }
    
    bool hasEdge(int v, int w)
    {
        return graph[v][w];
    }
    
    void show()
    {
        for(int i = 0; i < n; i++)
        {
            cout<<i<<": ";
            for(int j = 0; j < n-1; j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<graph[i][n-1];
            cout<<endl;
        }
    }
    
    class adjIterator
    {
    private:
        int v;//用来记录我们要遍历哪个节点的领边。这个节点就是v
        int index;//用来记录我们遍历到哪一个了。
        DenseGraph &G;
        
    public:
        adjIterator(DenseGraph &graph, int v):G(graph)
        {
            this->v = v;
            this->index = -1;//之所以是-1，是因为我们每次都是先index += 1，然后再判断这个新的index是不是对应的graph[v][index] == true, 所以第一个index += 1之后得==0，所以初始index = -1
            
        }
        
        ~adjIterator()
        {
            
        }
        
        int begin()
        {
            index = -1;
            return next();
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
//            index++;
//            if(end()) return -1;
//            if(G.graph[v][index] == false)
//            {
//                return next();
//            }
//            return index;//走到这里，说明G.graph[v][index] == true;
            
            //method 3: ByB
            for(index += 1; index < G.n && G.graph[v][index] == false; index++);//易错的地方：G.graph才是图，而不只是G
            return index;
        }
        
        bool end()
        {
            return index >= G.n;
        }
    };
};

#endif /* DenseGraph_h */
