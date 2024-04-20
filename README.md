# Binary Search Tree (BSTree) Template

## Introduction

This is a C++ template for a Binary Search Tree (BSTree), a fundamental data structure used for efficient searching, insertion, and deletion operations.

## Node Class

The `Node` class represents individual nodes of the BST. Each node contains a value of type `T`, and pointers to its left and right children.

## BSTree Class

The `BSTree` class implements operations on the binary search tree such as insertion, search, deletion, balancing, and checking balance. It utilizes the `Node` class for representing individual nodes.

### Public Methods

- **Constructor**: Initializes the BST.
- **Destructor**: Cleans up memory allocated for the BST.
- **insert(T val)**: Inserts a value into the BST.
- **contains(T val)**: Checks if a value is present in the BST.
- **findNode(T val)**: Finds the node with a specific value.
- **displayTree()**: Displays the tree structure.
- **isBalancedTree()**: Checks if the tree is balanced.
- **balanceTree()**: Balances the tree if it is unbalanced.

### Private Helper Methods
- **buildBalancedTree(int start, int end)**: Builds a balanced tree from sorted values.
- **deleteBST(Node<T>* node)**: Deletes the entire tree starting from a given node.
- **isBalancedSubTree(Node<T>* node)**: Checks if a subtree is balanced.
- **height(Node<T>* node)**: Calculates the height of the tree.

## Usage

To use this template, instantiate the `BSTree` class with the desired data type and call its methods to perform operations on the binary search tree.

