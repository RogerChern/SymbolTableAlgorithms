//
//  BinarySearchTree.cpp
//  BinarySearchTree
//
//  Created by RogerChen on 14-10-2.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "BinarySearchTree.h"
BinarySearchTree::NodePtr & BinarySearchTree::find_max(NodePtr &tree)
{
    if(tree->lchild == nullptr)
        return tree;
    return find_max(tree->lchild);
}

void BinarySearchTree::insert(NodePtr &tree, NodePtr &node)
{
    if(tree == nullptr){
        tree = std::move(node);
        return;
    }
    
    if(tree->key == node->key)
        return;
    
    if(node->key > tree->key)
        insert(tree->lchild, node);
    else
        insert(tree->rchild, node);
    
}

void BinarySearchTree::search(NodePtr &tree, NodePtr &node)
{
    if(node->key > tree->key)
        search(tree->lchild, node);
    else if (node->key < tree->key)
        search(tree->rchild, node);
    else
        node->value = tree->value;
}

void BinarySearchTree::remove(NodePtr &tree, double key)
{
    if (tree == nullptr)
        return;
    
    if (key > tree->key)
        remove(tree->lchild, key);
    else if (key < tree->key)
        remove(tree->rchild, key);
    else if (tree->lchild && tree->rchild) {
        NodePtr & temp = find_max(tree->rchild);
        tree->value    = temp->value;
        tree->key      = temp->key;
        remove(tree->rchild, key);
    }
    else {
        if (tree->lchild)
            tree = std::move(tree->lchild);
        else
            tree = std::move(tree->rchild);
    }
}

void BinarySearchTree::set(double key, double value)
{
    NodePtr temp = make_unique<Node>(key, value);
    insert(root_, temp);
}

double BinarySearchTree::get(double key) 
{
    NodePtr temp = make_unique<Node>(key);
    search(root_, temp);
    
    return temp->value;
}

void BinarySearchTree::remove(double key)
{
    remove(root_, key);
}