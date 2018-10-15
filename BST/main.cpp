#include <iostream>
#include "Node.h"
#include "Tree.h"

using namespace std;

int main () {
	Tree tree;
	tree.insert(5);
	tree.insert(9);
	tree.insert(8);
	tree.insert(4);
	tree.insert(6);
	tree.insert(10);
	tree.insert(1);
	tree.insert(7);
	tree.insert(3);
	tree.insert(2);

	Node *node = tree.search(4);
	Node *successor = tree.findSuccessor(node);
	/**
	Node* searchResult = tree.search(10);
	if(searchResult == NULL) cout << "NOT FOUND";
	else cout << searchResult->data;
	**/

	//tree.inorder();
	/**
	Node* max = tree.maximum();
	if(max == NULL) cout << "NOT FOUND";
	else cout << max->data;
	**/


	return 0;
}
