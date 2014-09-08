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

template<typename>
class TD;

class RedBlackTree{
private:
    class Node;
    using pNode = unique_ptr<Node>;
    static const bool RED   = true;
    static const bool BLACK = false;

private:
    pNode root;

private:
    bool   isRed(const pNode &x);
    pNode  rotateLeft(pNode x);
    pNode  rotateRight(pNode x);
    void   flipColor(pNode &x);
    int    size() const;
    int    size(const pNode &x);
    
private:
    pNode  set(pNode n, int key, int value);
    
public:
    
};

#endif
