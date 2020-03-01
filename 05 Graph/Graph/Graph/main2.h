//
//  main2.h
//  Graph
//
//  Created by 陈贝茜 on 2019/7/28.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef main2_h
#define main2_h


#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

using namespace std;

// 测试通过文件读取图的信息
void main2 () {
    
    cout<<endl;
    
    // 使用两种图的存储方式读取testG1.txt文件
    string filename = "/Users/bessie/Downloads/ByB/Algorithms/Graph/Graph/testG1.txt";
    SparseGraph g1( 13 , false );
    ReadGraph<SparseGraph> readGraph1( g1 , filename );
    cout<<"test G1 in Sparse Graph:" << endl;
    g1.show();
    
    cout<<endl;
    
    DenseGraph g2( 13 , false );
    ReadGraph<DenseGraph> readGraph2( g2 , filename );
    cout<<"test G1 in Dense Graph:" << endl;
    g2.show();
    
    cout<<endl;
    
    // 使用两种图的存储方式读取testG2.txt文件
    filename = "/Users/bessie/Downloads/ByB/Algorithms/Graph/Graph/testG2.txt";
    SparseGraph g3( 6 , false );
    ReadGraph<SparseGraph> readGraph3( g3 , filename );
    cout<<"test G2 in Sparse Graph:" << endl;
    g3.show();
    
    cout<<endl;
    
    DenseGraph g4( 6 , false );
    ReadGraph<DenseGraph> readGraph4( g4 , filename );
    cout<<"test G2 in Dense Graph:" << endl;
    g4.show();
    
}

#endif /* main2_h */
