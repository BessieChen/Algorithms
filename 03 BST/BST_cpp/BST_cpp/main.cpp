//
//  main.cpp
//  BST_cpp
//
//  Created by 陈贝茜 on 2019/7/21.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "BST.h"
#include "SequenceST.h"
#include "FileOps.h"

using namespace std;

// 实验二分搜索树的局限性
int main() {
    
    // 我们使用文本量更小的共产主义宣言进行试验:)
    //string filename = "communist.txt";
    string filename = "/Users/bessie/Downloads/ByB/Algorithms/bobo/05-Binary-Search-Tree/Course Code (C++)/10-The-Disadvantages-of-Binary-Search-Tree-and-More-Trees/communist.txt";
    vector<string> words;
    
    if( FileOps::readFile(filename, words) ) {
        
        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;
        
        
        // 测试1, 我们按照文本原有顺序插入进二分搜索树
        time_t startTime = clock();
        BST<string, int> *bst = new BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*bst).get(*iter);
            if (res == NULL)
                (*bst).add(*iter, 1);
            else
                (*res)++;
        }
        cout<<bst->getSize()<<endl;
        // 我们查看unite一词的词频
        if( bst->contains("unite") )
            cout << "'unite' : " << *(*bst).get("unite") << endl;
        else
            cout << "No word 'unite' in " + filename << endl;
        time_t endTime = clock();
        
        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;
        
        //已检查
//        bst->levelOrder();
//        bst->preOrder();
//        bst->postOrder();
//        bst->inOrder();
        
        //已检查 ok
        for (vector<string>::iterator iter = words.begin(); iter != words.end() && bst->getSize() > 0; iter++) {
            bst->remove(*iter);
        }
        cout<<bst->getSize()<<endl;
        
        //已检查 ok
        while(!(*bst).isEmpty())
        {
            bst->removeMin();
        }
        cout<<bst->getSize()<<endl;
        
        if(bst->isEmpty())
            cout<<"bst is empty."<<endl;
        delete bst;
        
        
        // 测试2, 我们按照文本原有顺序插入顺序查找表
        startTime = clock();
        SequenceST<string, int> *sst = new SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*sst).search(*iter);
            if (res == NULL)
                (*sst).insert(*iter, 1);
            else
                (*res)++;
        }
        
        // 我们查看unite一词的词频
        if( sst->contain("unite") )
            cout << "'unite' : " << *(*sst).search("unite") << endl;
        else
            cout << "No word 'unite' in " + filename << endl;
        endTime = clock();
        
        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;
        
        delete sst;
        
        
        sort( words.begin() , words.end() );
        
        // 测试3, 我们将原文本排序后插入二分搜索树, 查看其效率
        startTime = clock();
        BST<string, int> *bst2 = new BST<string, int>();
        
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*bst2).get(*iter);
            if (res == NULL)
                (*bst2).add(*iter, 1);
            else
                (*res)++;
        }
        
        // 我们查看unite一词的词频
        cout << "'unite' : " << *(*bst2).get("unite") << endl;
        endTime = clock();
        
        cout << "BST2 , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;
        
        delete bst2;
    }
    
    return 0;
}

/*
 There are totally 11528 words in communist.txt
 
 'unite' : 2
 BST , time: 0.023044 s.
 
 'unite' : 2
 SST , time: 0.401087 s.
 
 'unite' : 2
 BST2 , time: 1.38737 s.
 
 Program ended with exit code: 0
 */
