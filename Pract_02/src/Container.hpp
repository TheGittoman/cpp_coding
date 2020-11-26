#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iostream>

class Node
{
private:
	int m_data{};
public:
	Node();
	Node(int data) : m_data{data} {}
	int getData() const{
		return m_data;
	}
};

class Container
{
private:
	Node *m_nodes{nullptr};
	int m_nodeCount{0};
public:
	Container() = default;
	void getNodeCount() const
	{
		std::cout << m_nodeCount << std::endl;
	}
	void addNode(int data) {
		if (m_nodes == nullptr)
		{
			m_nodes = new Node{data};
			++m_nodeCount;
		}
	}
	int getInfo() const 
	{
		return m_nodes->getData();
	}
	~Container()
	{
		delete[] m_nodes;
	}
};
#endif