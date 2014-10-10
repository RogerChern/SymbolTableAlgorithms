//
//  main.cpp
//  BinarySearchTree
//
//  Created by RogerChen on 14-10-2.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
    
    vector<double> test = {1, 2, 3, 5, 6, 4, 8, 7, 0, 9};
    BinarySearchTree bst;
    
    for(auto &&x : test)
        bst.set(x, x);
    
    bst.remove(2);

    cout << bst.get(1) << bst.get(8);
    return 0;
}
