//
//  main1.h
//  Graph_Rewrite
//
//  Created by 陈贝茜 on 2019/8/21.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//


#ifndef main1_h
#define main1_h

using std::cout;
using std::cin;
using std::endl;

void main1(){
    vector<int> arr({1,2,3,4,5});
    vector<int>::iterator iter;
    for(iter = arr.begin(); iter != arr.end(); iter++)
        cout<<*iter<<" ";
    cout<<endl<<endl;
    
    //自动生成一个SparseGraph并且遍历它
    int V = 20;
    int E = 100;
    
    srand(static_cast<unsigned int>(time(NULL)));
    SparseGraph sg(V, false);//这样就可以初始一个了
    DenseGraph dg(V, false);//这样就可以初始一个了
    for(int i = 0; i < E; i++)
    {
        int v1 = rand() % V;
        int v2 = rand() % V;
        sg.addEdge(v1, v2);
        dg.addEdge(v1, v2);
    }
    
    for(int v1 = 0; v1 < V ; v1++)
    {
        cout<<v1<<": ";
        SparseGraph::adjIterator iter(sg, v1);//遍历以 i 为顶点的所有边
        for(int v2 = iter.begin(); !iter.end(); v2 = iter.next())
        {
            cout<<v2<<" ";
        }
        cout<<endl;
        
    }
    cout<<endl;
    
    for(int v1 = 0; v1 < V ; v1++)
    {
        cout<<v1<<": ";
        DenseGraph::adjIterator iter(dg, v1);//遍历以 i 为顶点的所有边
        for(int v2 = iter.begin(); !iter.end(); v2 = iter.next())
        {
            cout<<v2<<" ";
        }
        cout<<endl;
        
    }
    
}


#endif /* main1_h */
