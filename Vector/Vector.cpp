#include<iostream>
#include<string>

#include "Vector.h"

std::string ERROR_GET_INDEX_ARRAY = "The index must be greater than or equal to the length of the array and not less than zero";

// ...
template <typename Type>
void Vector<Type>::push(Type value) {
    typename Node<Type>::Node* ptr = new Node(value);

    // ...
    if (!headNode) {
        headNode = ptr;
        tailNode = ptr;
        length++;
        return;
    }

    // ...
    tailNode->nextNode = ptr;
    tailNode = ptr;
    length++;
}

// ...
template <typename Type>
Type Vector<Type>::pop() {
    // ...
    if (!length) {
        throw ERROR_GET_INDEX_ARRAY;
    }

    // ...
    Type value = tailNode->value;
    typename Node<Type>::Node* ptr = headNode;

    // ...
    while(ptr->nextNode != tailNode) {
        ptr = ptr->nextNode;
    }
    // ...
    tailNode = ptr;

    // ...
    delete ptr->nextNode->value;
    delete ptr->nextNode->nextNode;

    // ...
    return value;
}

// ...
template <typename Type>
Type Vector<Type>::peek() {
    // ...
    return tailNode.value;
}

// ...
template <typename Type>
Type Vector<Type>::get(unsigned long long indexGet) {
    unsigned long long indexCurrent = 0;

    // ...
    if (length <= indexGet || indexGet < 0) {
        throw ERROR_GET_INDEX_ARRAY;
    }

    // ...
    typename Node<Type>::Node* ptr = headNode;
    while(indexCurrent < indexGet) {
        ptr = ptr->nextNode;
    }

    // ...
    return ptr->value;
}