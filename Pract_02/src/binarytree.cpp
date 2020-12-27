#include "binarytree.hpp"
#include <iostream>

namespace bt
{
    Node *Tree::getRoot() const
    {
        return root;
    }
    void Tree::insert(int val, Node *temp)
    {
        if (root == nullptr)
        {
            root = new Node(val);
            return;
        }
        else if (val <= temp->m_data)
        {
            if (temp->left != nullptr)
            {
                insert(val, temp->left);
            }
            else
            {
                std::cout << "Inserted to left!" << std::endl;
                temp->left = new Node(val);
            }
        }
        else
        {
            if (temp->right != nullptr)
            {
                insert(val, temp->right);
            }
            else
            {
                std::cout << "Inserted to right!" << std::endl;
                temp->right = new Node(val);
            }
        }
    }
    void Tree::search(Node *temp, int val)
    {
        if (temp == nullptr)
        {
            std::cout << "Not Found" << std::endl;
            return;
        }
        else if (val == temp->m_data)
        {
            std::cout << "Found" << std::endl;
            return;
        }
        else if (val <= temp->m_data)
        {
            search(temp->left, val);
        }
        else
        {
            search(temp->right, val);
        }
    }
    void Tree::print() const
    {
        Node *temp{root};
        while (temp->right != nullptr && temp->left != nullptr)
        {
        }
    }
} // namespace bt