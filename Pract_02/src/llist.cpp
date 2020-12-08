#include "llist.hpp"
#include <iostream>
namespace LL
{
    void insert(Node **head, int data)
    {
        Node *nextNode{new Node()};
        nextNode->m_data = data;
        nextNode->next = *head;
        *head = nextNode;
    }

    void print(Node *head)
    {
        while(head->next != NULL)
        {
            std::cout << head->m_data << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    int input(std::string message)
    {
        int num{0};
        std::cout << message;
        std::cin >> num;
        std::cout << std::endl;
        return num;
    }

    void delNode(Node *head)
    {
        Node *temp;
        int index{input("Delete Node at index: ")};
        for(int i{0}; i < index; ++i)
        {
            if(i == index - 1)
                temp = head;
            head = head->next;
        }
        temp->next = head->next;
        delete head;
    }

    void delLast(Node *head)
    {
        if(head->next == NULL)
        {
            delete head;
            return;
        }
        Node *temp;
        while(head->next != NULL)
        {
            temp = head;
            head = head->next;
        }
        temp->next = NULL;
        delete head;
    }

    void delFirst(Node **head)
    {
        if((*head)->next == NULL)
        {
            delete *head;
            return;
        }
        Node *temp{*head};
        *head = (*head)->next;
        delete temp;
    }
}