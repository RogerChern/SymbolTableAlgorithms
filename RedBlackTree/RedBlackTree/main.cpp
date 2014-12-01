//
//  main.cpp
//  RedBlackTree
//
//  Created by RogerChen on 14-9-6.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include "RedBlackTree.h"
#include "RedBlackTreeTemplate.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    fstream fin("/Users/rogerchen/Desktop/data/largeT.txt");
    //RedBlackTree rbt;
    RedBlackTreeTemplate<int, int> rbtt;
    
    auto beg = clock();

    int temp;
    while(fin >> temp)
    {
        rbtt.set(temp, temp);
    }
    auto end = clock();

    cout << double(end - beg) / CLOCKS_PER_SEC * 1000 << " ms" << endl;


    cout << rbtt.size() << endl;
    cout << rbtt.get(333) << endl;
    
    return 0;
}
