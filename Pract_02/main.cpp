#include "src/base.hpp"
#include "src/header.hpp"
#include "src/lc_double_z.hpp"
#include "src/leetcode.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

struct Node
{
	int data;
	Node *next;
};


void insert(Node **pointerToHead, int num) // double pointer because of passing pointer by reference
{
	Node *temp = new Node();		// greates new Node pointer and points it at newly greated Node object
	temp->data = num; 				// allocates new Node with data
	temp->next = *pointerToHead;	// allocatest the new node's next to point the old Node.
	*pointerToHead = temp;			// makes the previous Node to point to the new making temp the first.
}

void print(Node *head)
{
	while(head != NULL)
	{
		std::cout << head->data;
		head = head->next;			// modifying head->next to point the next Node of the current Node
	}
}

int main()
{
	Node *head = NULL;
	int ii;
	std::cin >> ii;
	for(int i = 0; i < ii; ++i)
	{
		int num;
		std::cin >> num;
		insert(&head, num);			// passing head by reference to the insert function
		print(head);
	}
	system("pause");
	return 0;
}