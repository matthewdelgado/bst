// Matthew Delgado
// ECE 2552, Dr. Smith
// Ch 10 Assignment
// 03/30/2022

#ifndef BSTNode_hpp
#define BSTNode_hpp

#include <stdio.h>
#include <iostream>

// class for creation of nodes in the tree
class BSTNode{
public:
    BSTNode(int key); // constructor where key is given
    BSTNode* Left; // pointer to left subtree node
    BSTNode* Right; // pointer to right subtree node
    BSTNode* Parent; // pointer to node's parent
    int Key; // data
};

// class to create an entire BST ds
class BST{
private:
    BSTNode* root; // root node
protected:
    BSTNode* Insert(BSTNode* node, int key);
    void PrintTreeInOrder(BSTNode* node);
    BSTNode* Search(BSTNode* node, int key);
    int FindMin(BSTNode* node);
    int FindMax(BSTNode* node);
    int Successor(BSTNode* node);
    int Predecessor(BSTNode* node);
    BSTNode* Remove(BSTNode* node, int v);
    BSTNode* minValueNode(BSTNode* node);
public:
    BST(); // default constructor
    void Insert(int key);
    void PrintTreeInOrder();
    bool Search(int key);
    int FindMin();
    int FindMax();
    int Successor(int key);
    int Predecessor(int key);
    void Remove(int v);
};
#endif /* BSTNode_hpp */
