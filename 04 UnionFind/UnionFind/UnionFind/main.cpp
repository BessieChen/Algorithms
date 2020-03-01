//
//  main.cpp
//  UnionFind
//
//  Created by 陈贝茜 on 2019/8/20.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#include <iostream>
#include "UnionFindTestHelper.h"
#include "main2.h"

int main() {
    
    UF5::UnionFind uf = UF5::UnionFind(5);
    uf.unionElements(1,0);
    uf.unionElements(2,1);
    uf.unionElements(3,2);
    uf.unionElements(4,3);
    uf.show();
    
    cout<<"======"<<endl;
    uf.find(4);
    uf.show();
    
    main2();
    
    return 0;
}


/*
 0 : 1
 1 : 1
 2 : 1
 3 : 1
 4 : 1
 ======
 0 : 1
 1 : 1
 2 : 1
 3 : 1
 4 : 1
 UF1, 20000 ops, 0.183859 s
 UF2, 20000 ops, 0.044466 s
 UF3, 20000 ops, 0.000898 s
 UF4, 20000 ops, 0.000905 s
 UF5, 20000 ops, 0.000818 s
 Program ended with exit code: 0
 */
