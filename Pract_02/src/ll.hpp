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

#endif