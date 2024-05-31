#pragma once

template <typename Type>
struct Node {
    Type value;

    Node* nextNode;

    // ...
    Node(Type value): value(value), nextNode(nullptr) {};
};


template <typename Type>
class Stack {
private:
    Node* headNode;
    Node* tailNode;
    unsigned long long size;

public:
    // ...
    Stack(): headNode(nullptr), tailNode(nullptr), size(0) {};

    // ...
    Stack Stack(Stack& stack) {
        Stack newStack = Stack();

        Node* ptr = stack.headNode;
        while(ptr) {
            newStack.push(ptr->value);
            ptr = ptr->nextNode;
        }

        return newStack;
    }

    // ...
    ~Stack() {
        Node *ptr = headNode;
        
        while(ptr) {
            delete ptr->value;
            ptr = ptr->nextNode;
        }
    }

    // ...
    void push(Type value) {
        Node* ptr = new Node(value);

        if (!headNode) {
            headNode = ptr;
            tailNode = ptr;
            return;
        }

        tailNode->nextNode = ptr;
        tailNode = ptr;
    }

    // ...
    Type pop() {
        Type value = tailNode->value;

        delete tailNode->value;

        Node* ptr = headNode;
        while(ptr->nextNode != tailNode) {
            ptr = ptr->nextNode;
        }
        tailNode = ptr;

        return value;
    }

    // ...
    Type peek() {
        return tailNode->value;
    }
    
    // ...
    unsigned long long size() {
        return size;
    }

    // ...
    bool isEmpty() {
        return size == 0;
    }
};