#pragma once

template <typename Type>
struct Node {
    Type value;
    Node* nextNode;
    Node(Type value): value(value), nextNode(nullptr) {};
};

template <typename Type>
class Vector {
private:
    typename Node<Type>::Node* headNode;
    typename Node<Type>::Node* tailNode;
    unsigned long long length = 0;

public:
    // ...
    Vector<Type>(): headNode(nullptr), tailNode(nullptr), length(0) {};

    // ...
    void push(Type value) {
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
    unsigned long long size() {
        // ...
        return length;
    }

    // ...
    Type pop() {
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
    Type peek() {
        // ...
        return tailNode.value;
    }


    // ...
    Type operator[](unsigned long long indexGet) {
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
};