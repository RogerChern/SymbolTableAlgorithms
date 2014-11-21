//
//  RedBlackTreeTemplate.h
//  RedBlackTree
//
//  Created by RogerChen on 14-9-6.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef RedBlackTree_RedBlackTreeTemplate_h
#define RedBlackTree_RedBlackTreeTemplate_h

#include <memory>
#include <string>
using namespace std;

template<typename Key, typename Value>
class RedBlackTreeTemplate{
private:
    class Node{
    private:
        using keyType    = Key;
        using valueType  = Value;
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
            return color_ == true;
        }
    };
    using pNode = unique_ptr<Node>;
    static const bool RED   = true;
    static const bool BLACK = false;

private:
    pNode root;

private:
    bool   isRed(const pNode &x)
    {
        if(x == nullptr)
        {
            return BLACK;
        }
        else
        {
            return x->isRed();
        }
    }

    pNode  rotateLeft(pNode &n)
    {
        pNode x            = std::move(n->right_);
        n->right_          = std::move(x->left_);
        x->left_           = std::move(n);
        x->color_          = x->left_->color_;
        x->left_->color_   = RED;
        x->N_              = x->left_->N_;
        x->left_->N_       = size(x->left_->left_) + size(x->left_->right_) + 1;
        return x;
    }

    pNode  rotateRight(pNode &n)
    {
        pNode x            = std::move(n->left_);
        n->left_           = std::move(x->right_);
        x->right_          = std::move(n);
        x->color_          = x->left_->color_;
        x->right_->color_  = RED;
        x->N_              = x->right_->N_;
        x->right_->N_      = size(x->right_->left_) + size(x->right_->right_) + 1;
        return x;
    }
    
    void   flipColor(pNode &n)
    {
        n->color_          = !n->color_;
        n->left_->color_   = !n->left_->color_;
        n->right_->color_  = !n->right_->color_;
    }
    
    int    size(const pNode &n) const
    {
        if(n == nullptr)
        {
            return 0;
        }
        
        return n->N_;
    }
    
private:
    pNode  set(pNode &n, const Key &key, Value value)
    {
        if(n == nullptr)
        {
            //if change 'true' with 'RED', the linker will failed
            return make_unique<Node>(key, value, 1, true);
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
        n->N_ = size(n->left_) + size(n->right_) + 1;
        
        return std::move(n);
    }

    Value& get(const pNode &n, const Key &key) const
    {
        if(key < n->key_)
        {
            return get(n->left_, key);
        }
        else if(key > n->key_)
        {
            return get(n->right_, key);
        }
        
        return n->value_;
    }
    
public:
    void   set(const Key &key, Value value)
    {
        root = set(root, key, value);
        root->color_ = BLACK;
    }

    Value& get(const Key &key) const
    {
        return get(root, key);
    }
    
    int    size() const
    {
        return size(root);
    }
};



#endif
