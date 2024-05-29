#include<iostream>

#include "Tree.h"

// ...
template <typename Type>
void Tree<Type>::push(Type value) {
    Node* ptr = new Node(value);

    if (!headTree) {
        headTree = ptr;
    }

    Node* ptrCurrNode = headTree;
    while(ptrCurrNode) {
        if (value < ptrCurrNode->value && !ptrCurrNode->leftNode) {
            ptrCurrNode->leftNode = new Node(value);
        } else if (ptrCurrNode->value <= value && !ptrCurrNode->rightNode) {
            ptrCurrNode->rightNode = new Node(value);
        } else if (value < ptrCurrNode->value) {
            ptrCurrNode = ptrCurrNode->leftNode;
        } else {
            ptrCurrNode = ptrCurrNode->rightNode;
        }
    }
}

// ...
template <typename Type>
void Tree<Type>::pop(unsigned long long index = 0) {

}

// ...
template <typename Type>
void Tree<Type>::print(std::ofstream&writeFile) {

}

// ...
template <typename Type>
void Tree<Type>::print() {

}