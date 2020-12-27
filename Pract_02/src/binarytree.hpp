#include <iostream>

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

namespace bt
{
    class Node // Node of a binary tree
    {
    public:
        int m_data;
        Node *left, *right; // binary tree pointers to the downstream

        Node(int val) : m_data{val}, left{nullptr}, right{nullptr} {}
        Node() : left{nullptr}, right{nullptr} {}
    };

    class Tree // binary tree class contains root pointer
    {
    private:
        Node *root;

    public:
        Tree() : root{nullptr} {}
        Node *getRoot() const;
        void insert(int val, Node *root); // Insert Node to the binary tree
        void search(Node *temp, int val);
        void print() const; // Print the binary Tree
    };

} // namespace bt

#endif