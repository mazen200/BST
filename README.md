<h1 align="center" id="title">Binary Search Tree (BSTree) Template</h1>

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


## Detailed Explanation of Key Functions

### `isBalncedSubTree(Node<T>* node)`
- **Description**: Recursively checks whether the subtree rooted at the given node is balanced. It calculates the height of the left and right subtrees and compares them. If the absolute difference in heights is more than 1, it returns false, indicating that the subtree is unbalanced. Otherwise, it recursively checks whether both left and right subtrees are balanced.
- **Parameters**: 
  - `node`: The root node of the subtree to check.
- **Returns**: 
  - `true` if the subtree is balanced.
  - `false` if the subtree is unbalanced.

### `height(Node<T>* node)`
- **Description**: Recursively calculates the height of the subtree rooted at the given node. If the node is NULL, the height is 0. Otherwise, it recursively calculates the height of the left and right subtrees and returns the maximum height plus 1.
- **Parameters**: 
  - `node`: The root node of the subtree.
- **Returns**: 
  - The height of the subtree.

### `balanceTree()`
- **Description**: Balances the entire BST by rearranging nodes to ensure it is balanced. It performs an in-order traversal of the tree to store nodes in a vector, then recursively constructs a balanced tree from the sorted vector of nodes using the `buildBalancedTree()` function, and finally sets the root of the BST to the new balanced tree.
- **Note**: This function is essential for maintaining the efficiency of operations on the BST, as unbalanced trees can lead to degraded performance.

### `buildBalancedTree(int start, int end)`
- **Description**: Constructs a balanced BST from a sorted vector of nodes. It recursively selects the middle node of the vector range defined by `start` and `end`, assigns it as the root of the subtree, and recursively builds balanced left and right subtrees using the nodes before and after the middle node, respectively.
- **Parameters**: 
  - `start`: The start index of the range of nodes in the sorted vector.
  - `end`: The end index of the range of nodes in the sorted vector.
- **Returns**: 
  - The root node of the balanced subtree.
