#include "BST.h"
#include <iostream>
#include <assert.h>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;
template <class T>
Node<T>::Node()
{
	left = right = NULL;
}

template <class T>
Node<T>::Node(T val)
{
	value = val;
	left = right = NULL;
}

template <class T>
BSTree<T>::BSTree(void)
{
	root = NULL;
}


template <class T>
bool BSTree<T>::contains(T val)
{
	Node<T>* tmp = findNode(val);
	return (tmp != NULL);
}

template <class T>
Node<T>* BSTree<T>::findNode(T val)
{
	Node<T>* temp = root;
	while (temp != NULL)
	{
		if (temp->value == val)
			return temp;
		else if (temp->value < val)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return temp;
}

template <class T>
void BSTree<T>::insert(T val)
{
	if (contains(val))
		return;
	Node<T>* nodeToBeAdded = new Node<T>(val);
	if (root == NULL)
		root = nodeToBeAdded;
	else
	{
		Node<T>* temp = root;
		while (true)
		{
			if (temp->value < val)
			{
				// right
				if (temp->right == NULL)
				{
					temp->right = nodeToBeAdded;
					break;
				}
				else
					temp = temp->right;
			}
			else
			{
				// left
				if (temp->left == NULL)
				{
					temp->left = nodeToBeAdded;
					break;
				}
				else
					temp = temp->left;
			}
		}
	}
}

template<class T>
bool BSTree<T>::isBalancedTree()
{
	return isBalncedSubTree(root);
}

template<class T>
bool BSTree<T>::isBalncedSubTree(Node<T>* node)
{
	if (node == NULL)//base case
		return true;
	return (abs(height(node->left) - height(node->right)) <= 1) and isBalncedSubTree(node->left) and isBalncedSubTree(node->right);
}

template<class T>
int BSTree<T>::height(Node<T>* node)
{
	//Base case
	if (node == NULL)
		return  0;
	//Transition
	int ret = 0;
	int l =  height(node->left), r = height(node->right);
	ret += (l > r ? l + 1 : r + 1);
	return ret;
}
template<class T>
void BSTree<T>::balanceTree()
{
	nodes.clear();
	inOrderTraversal(root);
	root = buildBalancedTree(0, int(nodes.size()) - 1);

}

template<class T>
void BSTree<T>::inOrderTraversal(Node<T>* node) {
	if (node == nullptr)
		return;
	inOrderTraversal(node->left);
	nodes.push_back(node);
	
	inOrderTraversal(node->right);
}

template <class T>
Node<T>* BSTree<T>::buildBalancedTree(int start, int end) {
	if (start > end)
		return nullptr;

	int mid = (start + end) / 2;
	Node<T>* root = nodes[mid];
	root->left = buildBalancedTree(start, mid - 1);
	root->right = buildBalancedTree(mid + 1, end);
	
	return root;
}
template <class T>
void BSTree<T>::deleteBST(Node<T>* node)
{
	if (node == NULL)
		return;

	Node<T>* currentTreeNode = node;
	Node<T>* leftTreeNode = node->left;
	Node<T>* rightTreeNode = node->right;
	delete(currentTreeNode);
	deleteBST(leftTreeNode);
	deleteBST(rightTreeNode);
}

template <class T>
BSTree<T>::~BSTree(void)
{
	deleteBST(root);
}

template<class T>
void BSTree<T>::displayTree()// display tree level by level using BFS
{
	int levels = 0;
	vector<vector<T>>v(100);// 100 =  mx level size , you can change it as you need
	queue<Node<T>*>q;
	v.push_back({ root->value });
	map<T, int>vis;
	q.push(root);
	while (!q.empty()) {
		Node<T>* node = q.front();
		q.pop();
		if (node->left != NULL) {
			q.push(node->left);
			vis[node->left->value] = vis[node->value] + 1;
		}
		if (node->right != NULL) {
			q.push(node->right);
			vis[node->right->value] = vis[node->value] + 1;
		}
		levels = (levels > vis[node->value] ? levels : vis[node->value]);
		v[vis[node->value]].push_back(node->value);
	}
	for (int i = 0; i <= levels; i++) {
		cout <<"nodes in level" <<  i + 1 << " = ";
		for (auto j : v[i])
			cout << j << " ";
		cout << "\n";
	}
}
