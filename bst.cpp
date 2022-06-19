// Matthew Delgado
// ECE 2552, Dr. Smith
// Ch 10 Assignment
// 03/30/2022

#include "BSTNode.hpp"
#include <iostream>

int main(){
    BST* tree = new BST;
    int keys[] = {23, 12, 31, 3, 15, 7, 29, 88, 53}; // Define key value to be inserted to BST

    for(const int& key : keys) tree->Insert(key); // Inserting keys

    std::cout << "Tree keys: "; // Traversing tree in order then print all keys
    tree->PrintTreeInOrder();

    std::cout << "Search key 31: ";
    bool b = tree->Search(31); // Search key 31 it should be found
    if(b) std::cout << "found";
    else std::cout << "NOT found";

    std::cout << std::endl;

    std::cout << "Search key 18: ";
    b = tree->Search(18); // Search key 18 it should NOT be found
    if(b) std::cout << "found";
    else std::cout << "NOT found";

    std::cout << std::endl;

    std::cout << "Min. Key : " << tree->FindMin(); // Retrieving min key
    std::cout << std::endl;
    std::cout << "Max. Key : " << tree->FindMax(); // Retrieving max key
    std::cout << std::endl;

    // Finding successor
    std::cout << "Successor(31) = ";
    std::cout << tree->Successor(31) << std::endl; // Successor(31) should be 53
    std::cout << "Successor(15) = ";
    std::cout << tree->Successor(15) << std::endl; // Successor(15) should be 23
    std::cout << "Successor(88) = ";
    std::cout << tree->Successor(88) << std::endl; // Successor(88) should be -1 or NULL

    // Finding predecessor
    std::cout << "Predecessor(12) = ";
    std::cout << tree->Predecessor(12) << std::endl; // Predecessor(12) should be 7
    std::cout << "Predecessor(29) = ";
    std::cout << tree->Predecessor(29) << std::endl; // Predecessor(29) should be 23
    std::cout << "Predecessor(3) = ";
    std::cout << tree->Predecessor(3) << std::endl; // Predecessor(3) should be -1 or NULL

    // Removing a key
    std::cout << "Removing key 15" << std::endl;
    tree->Remove(15);
    std::cout << "Removing key 53" << std::endl;
    tree->Remove(53);

    // Printing all keys again, Key 15 and 53 should be disappeared
    std::cout << "Tree keys: ";
    tree->PrintTreeInOrder();
}

