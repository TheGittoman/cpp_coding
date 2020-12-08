#ifndef LLIST_HPP
#define LLIST_HPP
#include <iostream>

namespace LL
{
    //
    // Node class for the linked list includes int datatype and next pointer for next element in linked list
    //
    struct Node
    {
        int m_data; // just data
        Node *next; // Pointer to the next element in the array
    };
    //
    // Inserts Node to the linked list uses **head because of passing the head by reference
    //
    void insert(Node **head, int data);
    //
    // Prints all elements in the linked list
    //
    void print(Node *head);
    //
    // input is not neccessarily linked list thing but now it is here anyways 
    //
    int input(std::string message);
    //
    // Deletes node from user inputted index
    //
    void delNode(Node *head);
    //
    // Deletes last element in the linked list
    //
    void delLast(Node *head);
    //
    // Deletes first element in the array also checks if list is only 1 element long and just deletes the last item
    //
    void delFirst(Node **head);
}

#endif