#include <iostream>
#include "BST.cpp"

using namespace std;


int main() {
	BSTree<int>t;
	int n; cin >> n;
	for (int i = 0,j; i < n; i++) 
		cin >> j,
		t.insert(j);
	cout << (t.isBalancedTree() ? "YES\n" : "No\n");
	t.displayTree();
	t.balanceTree();
	t.displayTree();
	cout << (t.isBalancedTree() ? "YES\n" : "No\n");


	return 0;
}