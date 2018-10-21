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

	tree.inorder();
	cout << endl;
	Node *deletable = tree.search(5);
	tree.remove(deletable);
	tree.inorder();

	return 0;
}
