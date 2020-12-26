#ifndef LL_HPP
#define LL_HPP
#include <iostream>

namespace dll
{
    class Node
    {
    public:
        int m_data;
        Node *next, *prev;
        Node(int val) : m_data{val}, next{NULL}, prev{NULL} {}
        Node() : next{NULL}, prev{NULL} {}
    };

    class Head
    {
    private:
        Node *head;

    public:
        Head() : head{NULL} {}
        void insert(int val);
        void print() const;
        void insertTail(int val);
        void clean();
    };

} // namespace dll

namespace lc
{
    class Node
    {
    public:
        int m_val;
        Node *next, *prev;

        Node() : next{NULL}, prev{NULL} {}
    };

    class MyLinkedList
    {
    private:
        Node *head;

    public:
        /** Initialize your data structure here. */
        MyLinkedList() : head{NULL}
        {
        }

        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
        int get(int index);

        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        void addAtHead(int val);

        /** Append a node of value val to the last element of the linked list. */
        void addAtTail(int val);

        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
        void addAtIndex(int index, int val);

        /** Delete the index-th node in the linked list, if the index is valid. */
        void deleteAtIndex(int index);

        void printReverse();

        void print() const;
    };
} // namespace lc

#endif