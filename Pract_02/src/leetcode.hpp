#ifndef LEETCODE_HPP
#define LEETCODE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

namespace LC
{
    void print();

    int reverse(int x);

    void testRevInt();

    bool isPalindrome(int x);

    int removeElement(std::vector<int> &nums, int val);

    int removeDouble(std::vector<int> &nums);

    int removeDoubleUusi(std::vector<int> &nums);

    bool checkIfExistWorseMemoryUsageFaster(std::vector<int> &arr);

    bool checkIfExistBetterMemoryUsageSlower(std::vector<int> &arr);

    bool validMountainArray(std::vector<int> &arr);

    std::vector<int> replaceElements(std::vector<int> &arr);

    void moveZeroes(std::vector<int> &nums);

    std::vector<int> sortArrayByParity(std::vector<int> &A);

    std::vector<int> sortedSquares(std::vector<int> nums);

    int heightChecker(std::vector<int> &heights); // leetcode does not accept this answer despite I dont get what is wrong

    int heightCheckerFixed(std::vector<int> &heights); // leetcode does not accept this answer despite I dont get what is wrong

    std::vector<int> findDisappearedNumbers(std::vector<int> &nums);

    class Node
    {
    public:
        int m_data;
        Node *next;
        Node() : next{NULL}
        {
        }
    };

    class Head // Oma linked list class omasta päästä
    {
    private:
        Node *head;

    public:
        Head() : head{NULL} {}
        Node *getNode()
        {
            return this->head;
        }
        int get(int index)
        {
            if (index < 0)
            {
                return -1;
            }
            Node *temp = head;
            for (int i{0}; i < index; ++i)
            {
                if (i < index && temp->next == NULL)
                {
                    return -1;
                }
                temp = temp->next;
            }
            return temp->m_data;
        }

        void addAtHead(int val)
        {
            Node *newNode{new Node()};
            newNode->m_data = val;
            newNode->next = head;
            head = newNode;
        }
        void addAtTail(int val)
        {
            Node *temp{head};
            Node *newNode{new Node()};
            newNode->m_data = val;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        void addAtIndex(int index, int val)
        {
            Node *temp{head};
            Node *prev;
            for (int i{0}; i < index; ++i)
            {
                if (i < index && temp->next == NULL)
                {
                    return;
                }
                if (i == index - 1)
                {
                    prev = temp;
                }
                temp = temp->next;
            }
            Node *newNode{new Node()};
            newNode->m_data = val;
            prev->next = newNode;
            newNode->next = temp;
        }
        void deleteAtIndex(int index)
        {
            Node *temp{head};
            Node *prev;
            for (int i{0}; i < index; ++i)
            {
                if (i < index && temp->next == NULL)
                {
                    return;
                }
                if (i == index - 1)
                {
                    prev = temp;
                }
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
        void printList()
        {
            Node *temp{head};
            while (temp->next != NULL)
            {
                std::cout << temp->m_data << ",";
                temp = temp->next;
            }
            std::cout << temp->m_data;
            std::cout << std::endl;
        }
        void invert()
        {
            Node *prev{NULL};
            Node *next;
            while (head != NULL)
            {
                next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
            head = prev;
        }
        void recRevPrint(Node *temp) // recursive reverse print
        {
            if (temp->next == NULL)
                return;
            recRevPrint(temp->next);
            std::cout << temp->m_data << ", ";
        }
        void recForwPrint(Node *temp) // recursive reverse print
        {
            std::cout << temp->m_data << ", ";
            if (temp->next == NULL)
                return;
            recForwPrint(temp->next);
        }
        void reverseRec(Node *temp)
        {
            if (temp->next == NULL) // do if temp->next is NULL
            {
                this->head = temp; // make the head pointer to point to the temp(last node)
                return;
            }
            reverseRec(temp->next); // call recursively the next node(advance in the link list)
            Node *prev{temp->next}; // Now we have gone to the last node and returned to level below and thus printing this
            prev->next = temp;      // attaches the previous node to the current node
            temp->next = NULL;      // because we want the last(first) node's next pointer to point NULL
        }
    };
} // namespace LC

#endif