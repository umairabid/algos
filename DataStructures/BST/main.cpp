#include <iostream>
#include "Node.h"
#include "Tree.h"

using namespace std;

int main () {
	Tree tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(5);
	tree.insert(3);
	tree.insert(6);
	tree.insert(4);

	tree.getNodesDistance();
	cout << endl;

	return 0;
}
