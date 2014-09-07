//
//  RedBlackTree.h
//  RedBlackTree
//
//  Created by RogerChen on 14-9-6.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef RedBlackTree_RedBlackTree_h
#define RedBlackTree_RedBlackTree_h

#include <memory>
using namespace std;

class RedBlackTree{
private:
    class Node;
    using pNode = unique_ptr<Node>;

private:
    pNode root;

private:
    bool   isRed(pNode x) const;
    pNode  rotateLeft(pNode x);
    pNode  rotateRight(pNode x);
    void   flipColor(pNode x);
    int    size();
    int    size(pNode);
    
private:
    pNode  set(pNode n, int key, int value);
    
public:
    
};

#endif
