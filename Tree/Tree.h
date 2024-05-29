#pragma once

template <typename Type>
struct Node {
    Type value;

    Node* headNode;
    Node* leftNode;
    Node* rightNode;

    Node(Type value): value(value), headNode(nullptr), leftNode(nullptr), rightNode(nullptr) {};
};

template <typename Type>
class Tree {
private:
    Node* headTree;

public:
    // Add value in Tree
    void push(Type value);

    void pop(unsigned long long index);
    
    // Print in output file
    void print(std::ofstream&writeFile);

    // Print in console
    void print();
};