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
    Vector<Type>(): headNode(nullptr), tailNode(nullptr), length(0) {};

    void push(Type value);
    Type pop();
    Type peek();
    Type get(unsigned long long indexGet);
};