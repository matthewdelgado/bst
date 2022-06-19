// Matthew Delgado
// ECE 2552, Dr. Smith
// Ch 10 Assignment
// 03/30/2022

#include "BSTNode.hpp"

// BSTNode parameterized constructor
BSTNode::BSTNode(int key){
    Key = key;
    Left = NULL;
    Right = NULL;
    Parent = NULL;
}

// BST parameterized constructor
BST::BST(){ root = NULL; }

// insert a new BSTNode with a given key
BSTNode* BST::Insert(BSTNode* node, int key){
    if(node == NULL) return new BSTNode(key); // Insert as root, if root is NULL
    else{
        BSTNode* cur;
        if(key <= node->Key){
            cur = Insert(node->Left, key);
            node->Left = cur;
        }else{
            cur = Insert(node->Right, key);
            node->Right = cur;
        }
    return node; // Return 'root' node, after insertion
    }
}

// Passing root node and given key to Insert
void BST::Insert(int key){ root = Insert(root, key); }

// print the entire tree in order
void BST::PrintTreeInOrder(BSTNode* node){
    if(node == NULL) return; // Stop printing if no node found
    PrintTreeInOrder(node->Left); // Get the smallest key first (left)
    std::cout << node->Key << " "; // Print the key
    PrintTreeInOrder(node->Right); // Continue to the greatest key (right)
}

// call print function to print entire tree in order
void BST::PrintTreeInOrder(){
   PrintTreeInOrder(root); // Traverse the BST then print all keys
   std::cout << std::endl;
}

// search entire tree for node given a key
BSTNode* BST::Search(BSTNode* node, int key){
    if(node == NULL || node->Key == key) return node; // Base Cases: root is null or key is at root
    if(node->Key < key) return Search(node->Right, key); // Key is greater than root's key
    return Search(node->Left, key); // Key is smaller than root's key
}

// call the search function to search tree for key given the root node
bool BST::Search(int key){
   BSTNode* result = Search(root, key); // Invoking Search() operation and passing root node
   return result == NULL ? false : true; // If key is found, returns TRUE otherwise returns FALSE
}

// find the min key value
int BST::FindMin(BSTNode* node){
    if(node == NULL) return INT_MAX;
    int min = node->Key;
    int leftMin = FindMin(node->Left);
    int rightMin = FindMin(node->Right);
    if(leftMin < min) min = leftMin;
    if(rightMin < min) min = rightMin;
    return min;
}

// find the max key value
int BST::FindMax(BSTNode* node){
    if(node == NULL) return INT_MIN;
    int max = node->Key;
    int leftMax = FindMax(node->Left);
    int rightMax = FindMax(node->Right);
    if(leftMax > max) max = leftMax;
    if(rightMax > max) max = rightMax;
    return max;
}

// call the find min function with the root node
int BST::FindMin(){ return FindMin(root); }

// call the find max function with the root node
int BST::FindMax(){ return FindMax(root); }

// find the node with the minimum value. returns node pointer
BSTNode* BST::minValueNode(BSTNode* node){
   BSTNode* current = node;
   while (current->Left != NULL) current = current->Left;
   return current;
}

// returns the key of the successor node
int BST::Successor(BSTNode* node){
    BSTNode* temp = root;
    BSTNode* s = root;
    if(node->Right != NULL){
        temp = node->Right;
        while(temp->Left != NULL) temp = temp->Left;
    }else{
        while(s->Key != node->Key){
            if(node->Key <= s->Key){
                temp = s;
                s = s->Left;
            }else s = s->Right;
        }
    }
    return temp->Key;
}

// call the successor function to find the successor to a node given a key
int BST::Successor(int key){
   BSTNode* keyNode = Search(root, key); // Search the key's node first
   return keyNode == NULL ? -1 : Successor(keyNode); // Return the key, If key not found or successor not found, return -1
}

// returns the key of the predecessor node
int BST::Predecessor(BSTNode* node){
    if(node->Left != NULL) return FindMax(node->Left);
    BSTNode* temp = root;
    BSTNode* predecessor = NULL;
    while(temp != NULL){
        if(node->Key > temp->Key){
            predecessor = temp;
            temp = temp->Right;
        }else if(node->Key < temp->Key) temp = temp->Left;
        else break;
    }
    if(!predecessor) return -1;
    return predecessor->Key;
}

// call the predecessor function to find the predecessor to a node given a key
int BST::Predecessor(int key){
   BSTNode* keyNode = Search(root, key); // Search the key's node first
   return keyNode == NULL ? -1 : Predecessor(keyNode); // Return the key, If key not found or successor not found, return -1
}

// remove a bst node
BSTNode* BST::Remove(BSTNode* node, int key){
    if(node == NULL) return node;
    if(key < node->Key) node->Left = Remove(node->Left, key);
    else if(key > node->Key) node->Right = Remove(node->Right, key);
    else{
      if(node->Left == NULL){
         BSTNode* temp = node->Right;
         free(node);
         return temp;
      }else if(node->Right == NULL){
         BSTNode* temp = node->Left;
         free(node);
         return temp;
      }
      BSTNode* temp = minValueNode(node->Right);
      node->Key = temp->Key;
      node->Right = Remove(node->Right, temp->Key);
    }
    return node;
}

// call the remove function given a key to a node
void BST::Remove(int key){ root = Remove(root, key); }
