/**
 * tree.h
 * Tree class template declarations and implementations
 * 
 * @author Onurcan Erşen
 */

#ifndef TREE_H
#define TREE_H

#include <iostream>

#include "node.h"

using namespace std;

template <class T>
class Tree
{
    Node<T> *root;

public:
    Tree();
    void insert(const T &);
    void remove(const T &);
    void inorder(const Node<T> *) const;
    void print() const;
    void clear_util(Node<T> *);
    void clear();
    ~Tree();
};

/**
 * Tree constructor
 */
template <class T>
Tree<T>::Tree()
{
    this->root = nullptr;
};

/**
 * Insert data to tree
 * 
 * @param data Data to insert
 */
template <class T>
void Tree<T>::insert(const T &data)
{
    if (!this->root) // If tree is empty
    {
        this->root = new Node<T>(data);
        return;
    }
    Node<T> *current = this->root;
    while (current) // Traverse tree
    {
        if (data < current->data)
        {
            if (current->left)
                current = current->left;
            else
            {
                current->left = new Node<T>(data);
                return;
            }
        }
        else if (data > current->data)
        {
            if (current->right)
                current = current->right;
            else
            {
                current->right = new Node<T>(data);
                return;
            }
        }
        else
            throw "Data already exists in tree.";
    }
}

/**
 * Remove data from tree
 * 
 * @param data Data to remove
 */
template <class T>
void Tree<T>::remove(const T &data)
{
    Node<T> *current = this->root;
    Node<T> *parent;
    char direction = 'n';
    bool found = false;
    while (current && !found) // Traverse tree
    {
        if (data < current->data)
        {
            parent = current;
            direction = 'l';
            current = current->left;
        }
        else if (data > current->data)
        {
            parent = current;
            direction = 'r';
            current = current->right;
        }
        else
            found = true;
    }
    if (found)
    {
        if (direction == 'l')
        {
            if (!current->left)
                parent->left = current->right;
            else if (!current->right)
                parent->left = current->left;
            else
            {
                Node<T> *temp = current->right;
                while (temp->left)
                    temp = temp->left;
                temp->left = current->left;
                parent->left = current->right;
            }
        }
        else if (direction == 'r')
        {
            if (!current->left)
                parent->right = current->right;
            else if (!current->right)
                parent->right = current->left;
            else
            {
                Node<T> *temp = current->right;
                while (temp->left)
                    temp = temp->left;
                temp->left = current->left;
                parent->right = current->right;
            }
        }
        else
        {
            if (!current->left)
                this->root = current->right;
            else if (!current->right)
                this->root = current->left;
            else
            {
                Node<T> *temp = current->right;
                while (temp->left)
                    temp = temp->left;
                temp->left = current->left;
                this->root = current->right;
            }
        }
        delete current;
    }
    else
        throw "Data does not exist in tree.";
}

/**
 * Print nodes with inorder traversal using recursion
 * 
 * @param node Root node of subtree
 */
template <class T>
void Tree<T>::inorder(const Node<T> *node) const
{
    if (node)
    {
        this->inorder(node->left);
        cout << node->data << " ";
        this->inorder(node->right);
    }
}

/**
 * Print all nodes
 */
template <class T>
void Tree<T>::print() const
{
    this->inorder(this->root);
    cout << endl;
}

/**
 * Delete nodes using recursion
 * 
 * @param node Root node of subtree
 */
template <class T>
void Tree<T>::clear_util(Node<T> *node)
{
    if (node)
    {
        if (node->left)
        {
            this->clear_util(node->left);
            node->left = nullptr;
        }
        if (node->right)
        {
            this->clear_util(node->right);
            node->right = nullptr;
        }
        delete node;
    }
}

/**
 * Clear wrapper function
 */
template <class T>
void Tree<T>::clear()
{
    this->clear_util(this->root);
    this->root = nullptr;
}

/**
 * Delete all nodes
 */
template <class T>
Tree<T>::~Tree()
{
    this->clear();
}

#endif