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
        std::cout << head->m_data << std::endl;
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

    void reverseList(Node **head)       //MycodeSchool versio en valitettavasti osannut tehdä tätä itse
    {
        Node *prev, *next, *current;
        current = *head;                //current points to the address of head
        prev = NULL;                    //prev points to NULL because current->next points to this first thing
        while(current != NULL)          // as long as current is different than zero loop
        {
            next = current->next;       //next points to the current next
            current->next = prev;       //current next points to prev which is actually NULL the first run
            prev = current;             //make previus point to the current
            current = next;             //and finally cut the link to the previus with next's address
        }
        *head = prev;                   //lastly because we are at the end of the list just make head to be prev
                                        //which is now the last node (current = NULL and next == NULL)
    }
}