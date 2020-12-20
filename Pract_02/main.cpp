#include "src/fuf.hpp"
// every little function that is used all the time currently only printArray functio
#include "src/leetcode.hpp"
#include "src/timer.hpp"
// timer reset elapsed(which returs double value)
#include "src/test_arr.hpp"
// two arrays array and array_small accessable by Test:: namespace small is -9 - 9 array is 0 - 5000
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <chrono>

class Node
{
public:
	int m_data;
	Node *next;
	Node() : next{NULL}
	{
	}
};

class Head
{
private:
	Node *head;

public:
	Head() : head{NULL} {}
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
};

int main()
{
	using namespace LC;
	Timer time;
	Head head;
	// 1 2 3 4 6
	head.addAtHead(100);
	head.printList();
	head.addAtHead(1100);
	head.addAtHead(1600);
	head.addAtHead(1200);
	head.addAtHead(1500);
	head.printList();
	head.addAtTail(2);
	head.addAtTail(5);
	head.printList();
	head.invert();
	head.printList();

	std::cout
		<< "Time Taken To Run This Program: " << time.elapsed() << std::endl;
	system("pause");
	return 0;
}

// arr[i] = *(arr + i)
// *arr[i] = **(arr + i)