#include "ll.hpp"
#include <iostream>

namespace dll
{
    void Head::insert(int val)
    {
        Node *newNode{new Node(val)};
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void Head::insertTail(int val)
    {
        Node *temp{head};
        Node *newNode{new Node(val)};
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void Head::print() const
    {
        if (head == NULL)
        {
            std::cerr << "Head Was Empty!" << std::endl;
            return;
        }
        Node *temp{head};
        std::cout << temp->m_data << ", ";
        while (temp->next != NULL)
        {
            std::cout << temp->next->m_data << ", ";
            temp = temp->next;
        }
        std::cout << std::endl;
        std::cout << "!And Now Backwards!" << std::endl;
        while (temp != NULL)
        {
            std::cout << temp->m_data << ", ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
    void Head::clean()
    {
        if (head == NULL)
        {
            std::cerr << "Head Was Empty!" << std::endl;
            return;
        }
        Node *next{NULL};
        next = head->next;
        while (next != NULL)
        {
            delete head;
            head = next;
            next = head->next;
        }
        delete head;
        head = NULL;
    }
} // namespace dll