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
#include "RedBlackTree.h"
#include "RedBlackTreeTemplate.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    fstream fin("/Users/rogerchen/Desktop/data/tinyTale.txt");
    RedBlackTree rbt;
    RedBlackTreeTemplate<string, int> rbtt;
    
    string temp;
    int    counter = 0;
    while(fin >> temp)
    {
        rbt.set(temp, ++counter);
        rbtt.set(temp, counter);
    }
    
    cout << rbt.size() << endl;
    cout << rbt.get("foolishness") << endl;
    cout << rbtt.size() << endl;
    cout << rbtt.get("it") << endl;
    
    return 0;
}
