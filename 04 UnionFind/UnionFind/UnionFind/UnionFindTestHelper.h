//
//  UnionFindTestHelper.h
//  UnionFind
//
//  Created by 陈贝茜 on 2019/8/20.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef UnionFindTestHelper_h
#define UnionFindTestHelper_h

#include <iostream>
#include <ctime>
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include "UnionFind5.h"

using namespace std;


namespace UnionFindTestHelper{
    
    void testUF1( int n ){
        
        srand(static_cast<unsigned int>(time(NULL)) );
        UF1::UnionFind uf = UF1::UnionFind(n);
        
        time_t startTime = clock();
        
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();
        
        cout<<"UF1, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    
    void testUF2( int n ){
        
        srand(static_cast<unsigned int>(time(NULL)));
        UF2::UnionFind uf = UF2::UnionFind(n);
        
        time_t startTime = clock();
        
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        
        time_t endTime = clock();
        
        cout<<"UF2, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    
    void testUF3( int n ){
        
        srand(static_cast<unsigned int>(time(NULL)) );
        UF3::UnionFind uf = UF3::UnionFind(n);
        
        time_t startTime = clock();
        
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        
        time_t endTime = clock();
        
        cout<<"UF3, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    
    void testUF4( int n ){
        
        srand( static_cast<unsigned int>(time(NULL)) );
        UF4::UnionFind uf = UF4::UnionFind(n);
        
        time_t startTime = clock();
        
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();
        
        cout<<"UF4, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    
    void testUF5( int n ){
        
        srand( static_cast<unsigned int>(time(NULL)));
        UF5::UnionFind uf = UF5::UnionFind(n);
        
        time_t startTime = clock();
        
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();
        
        cout<<"UF5, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
}

#endif /* UnionFindTestHelper_h */
