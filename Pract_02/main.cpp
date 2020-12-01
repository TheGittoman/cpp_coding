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


void insert(Node **pointerToHead, int num)
{
	Node *temp = new Node();
	temp->data = num;
	temp->next = *pointerToHead;
	*pointerToHead = temp;
}

void print(Node *head)
{
	while(head != NULL)
	{
		std::cout << head->data;
		head = head->next;
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
		insert(&head, num);
		print(head);
	}
	system("pause");
	return 0;
}