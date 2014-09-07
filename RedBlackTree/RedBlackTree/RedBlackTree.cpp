//
//  RedBlackTree.cpp
//  RedBlackTree
//
//  Created by RogerChen on 14-9-6.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "RedBlackTree.h"

class RedBlackTree::Node{
private:
    using keyType    = int;
    using valueType  = int;
    using pNode      = unique_ptr<Node>;
    using Color      = bool;
    
public:
    static const bool RED   = true;
    static const bool BLACK = false;
    
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

bool RedBlackTree::isRed(pNode x) const
{
    if(x == nullptr)
    {
        return false;
    }
    else
    {
        return x->isRed();
    }
}

auto RedBlackTree::set(pNode n, int key, int value) ->pNode
{
    if(n == nullptr)
    {
        return make_unique<Node>(key, value, 1, Node::BLACK);
    }
    
    if(key < n->key_)
    {
        n->left_ = set(n->left_, key, value);
    }
    else if(key > n->key_)
    {
        n->right_ = set(n->right_, key, value);
    }
    else
    {
        n->value_ = value;
    }
    
    if(isRed(n->right_) && !isRed(n->left_))
    {
        n = rotateLeft(n);
    }
    if(isRed(n->left_) && isRed(n->left_->left_))
    {
        n = rotateRight(n);
    }
    if(isRed(n->left_) && isRed(n->right_))
    {
        flipColor(n);
    }
    n->N_ = size(n->left_) + size(n->right_);
    
    return n;
}

auto RedBlackTree::rotateLeft(pNode n) ->pNode
{
    pNode x            = n->left_;
    n->left_           = x->right_;
    x->right_          = n;
    x->color_          = x->left_->color_;
    x->right_->color_  = Node::RED;
    x->N_              = n->N_;
    n->N_              = size(n->left_) + size(n->right_) + 1;
    return x;
}

auto RedBlackTree::rotateRight(pNode n) ->pNode
{
    pNode x            = n->right_;
    n->right_          = x->left_;
    x->left_           = n;
    x->color_          = x->left_->color_;
    x->left_->color_   = Node::RED;
    x->N_              = n->N_;
    n->N_              = size(n->left_) + size(n->right_) + 1;
    return x;
}

void RedBlackTree::flipColor(pNode n)
{
    n->color_          = !n->color_;
    n->left_->color_   = !n->left_->color_;
    n->right_->color_  = !n->right_->color_;
}

