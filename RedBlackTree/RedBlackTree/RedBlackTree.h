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
#include <string>
using namespace std;

class RedBlackTree{
private:
    class Node{
    private:
        using keyType    = string;
        using valueType  = int;
        using pNode      = unique_ptr<Node>;
        using Color      = bool;
        
    public:
        keyType           key_;
        valueType         value_;
        pNode             left_, right_;
        Color             color_;
        int               N_;
        
    public:
        Node(keyType key, valueType value, int N, Color color):
        key_(key),
        value_(value),
        color_(color),
        N_(N)
        {
            
        }
        
        bool isRed() const
        {
            return color_ == RED;
        }
    };
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
    pNode  set(pNode n, string key, int value);
    int&   get(const pNode &n, const string &key);
    
public:
    void   set(string key, int value);
    int&   get(const string &key);
    
};

#endif
