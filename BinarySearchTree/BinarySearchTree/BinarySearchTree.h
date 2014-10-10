//
//  BinarySearchTree.h
//  BinarySearchTree
//
//  Created by RogerChen on 14-10-2.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef BinarySearchTree_BinarySearchTree_h
#define BinarySearchTree_BinarySearchTree_h

#include <memory>
using namespace std;

struct Node{
    using NodePtr = unique_ptr<Node>;
    
    NodePtr     lchild;
    NodePtr     rchild;
    double      key;
    double      value;
    
    Node(double k, double v):
        key(k),
        value(v)
    {}
    
    Node(double k):
        key(k)
    {}
};

class BinarySearchTree{
    using NodePtr = Node::NodePtr;
    NodePtr     root_;
    
    void insert(NodePtr &tree, NodePtr &node);
    void search(NodePtr &tree, NodePtr &node);
    void remove(NodePtr &tree, double key);
    NodePtr & find_max(NodePtr &tree);
public:
    double get(double key);
    void set(double key, double value);
    void remove(double key);
};


#endif
