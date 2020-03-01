//
//  Student.h
//  SelectionSort
//
//  Created by 陈贝茜 on 2019/6/25.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef Student_h//宏定义，防止多重引用
#define Student_h

#include <iostream>
#include <string>

using namespace std; //应该尽量少用using namespace，因为容易导致命名空间污染，但是这门课不需要担心这些

struct Student
{
    string name;
    int score;
    
    bool operator< (const Student &otherStudent)
    {
        //method 1:单纯给score排序
        //return score < otherStudent.score;
        
        //method 2:如果分数相同，再给姓名排序
        return score == otherStudent.score ? name < otherStudent.name : score < otherStudent.score;
        
    }
    
    friend ostream& operator<< (ostream &os, const Student &student)
    {
        os<<"Student:" <<student.name<<" "<<student.score<<endl;
        return os;
    }
};
#endif /* Student_h */
