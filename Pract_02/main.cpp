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

Node *head;

void insert(int num)
{
	Node *temp = new Node();
	temp->data = num;
	temp->next = head;
	head = temp;
}

void print()
{
	Node *temp = head;
	while(temp != NULL)
	{
		std::cout << temp->data;
		temp = temp->next;
	}
}

int main()
{
	head = NULL;
	int ii;
	std::cin >> ii;
	for(int i = 0; i < ii; ++i)
	{
		int num;
		std::cin >> num;
		insert(num);
		print();
	}
	system("pause");
	return 0;
}