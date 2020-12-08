#include "src/fuf.hpp"
#include "src/base.hpp"
#include "src/header.hpp"
#include "src/lc_double_z.hpp"
#include "src/MCS.hpp"
#include "src/leetcode.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

/*
20202 % 10 = 2
2020 % 10 = 0
202 % 10 = 2
20 % 10 = 0
2 % 10 = 2

linked list: Create, Add to the front, add to the back, add to the nth pos, delete

*/
struct Node
{
	int m_data;
	Node *next;
};

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

int main()
{
	Node *head{new Node()};
	int count{input("How many nodes you want to enter: ")};
	for(int i{0}; i < count; ++i) 
	{
		int data{input("Data you want to input: ")};
		insert(&head, data);
	}
	delFirst(&head);
	print(head);
	std::cout << std::endl;
	system("pause");
	return 0;
}