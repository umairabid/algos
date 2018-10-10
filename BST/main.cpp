#include <iostream>
#include "Node.h"
#include "Tree.h"

using namespace std;

int main () {
	Tree tree;
	tree.insert(5);
	tree.insert(9);
	tree.insert(4);
	tree.insert(10);
	tree.insert(1);
	tree.inorder();
	
	return 0;
}