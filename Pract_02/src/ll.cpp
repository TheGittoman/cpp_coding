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
namespace lc
{
    int MyLinkedList::get(int index)
    {
        Node *temp{head};
        for (int currentIndex{0}; currentIndex < index; ++currentIndex)
        {
            if (temp->next == NULL)
            {
                return -1;
            }
            temp = temp->next;
        }
        return temp->m_val;
    }
    void MyLinkedList::addAtHead(int val)
    {
        Node *newNode{new Node()};
        newNode->m_val = val;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void MyLinkedList::addAtTail(int val)
    {
        Node *temp{head};
        Node *newNode{new Node()};
        newNode->m_val = val;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }
    void MyLinkedList::addAtIndex(int index, int val) // works, but maybe not as it should
    {
        if (index < 0)
        {
            return;
        }
        if (head == NULL)
        {
            return;
        }
        Node *temp{head};
        Node *newNode{new Node()};
        newNode->m_val = val;
        if (index == 0)
        {
            temp->prev = newNode;
            newNode->next = temp;
            head = newNode;
            return;
        }
        for (int currentIndex{0}; currentIndex < index; ++currentIndex)
        {
            if (temp == NULL)
            {
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            delete newNode;
            return;
        }
        if (!temp->next)
        {
            temp->prev->next = newNode;
            newNode->prev = temp->prev;
            temp->prev = newNode;
            newNode->next = temp;
            return;
        }
        temp->prev->next = newNode;
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev = newNode;
    }
    void MyLinkedList::deleteAtIndex(int index) // Works
    {
        Node *temp{head};
        if (index < 0)
        {
            return;
        }
        if (index == 0)
        {
            head = head->next;
            head->prev = NULL;
            delete temp;
            return;
        }
        for (int currentNode{0}; currentNode < index; ++currentNode)
        {
            if (temp == NULL)
            {
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return;
        }
        if (!temp->next)
        {
            temp->prev->next = NULL;
            delete temp;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    void MyLinkedList::printReverse()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp{head};
        std::cout << "Backwards!" << std::endl;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        std::cout << temp->m_val << ", ";
        while (temp->prev != NULL)
        {
            temp = temp->prev;
            std::cout << temp->m_val << ", ";
        }
        std::cout << std::endl;
    }
    void MyLinkedList::print() const
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp{head};
        std::cout << "Forward!" << std::endl;
        std::cout << temp->m_val << ", ";
        while (temp->next != NULL)
        {
            temp = temp->next;
            std::cout << temp->m_val << ", ";
        }
        std::cout << std::endl;
    }
} // namespace lc