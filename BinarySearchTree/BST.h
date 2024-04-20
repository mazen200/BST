#pragma once
#include<vector>
using namespace std;
enum Order
{
	INORDER = 0,
	PREORDER = 1,
	POSTORDER = 2,
	XOrder = 3
};

template <class T>
class Node
{
public:
	T value;
	Node<T>* left, * right;
	Node();
	Node(T val);
};

template <class T>
class BSTree
{
private:
	Node<T>* root;
	vector<T> sortedVector;
	bool isBalncedSubTree(Node<T>* node);
	int height(Node<T>* node);
	vector<Node<T>*>nodes;
	Node<T>* buildBalancedTree(int start, int end);
	void deleteBST(Node<T>* node);
public:
	
	void balanceTree();
	void inOrderTraversal(Node<T>* node);
	BSTree(void);
	~BSTree(void);
	void displayTree();
	bool contains(T val);
	Node<T>* findNode(T val);
	void insert(T val);
	bool isBalancedTree();

};

