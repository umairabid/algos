/**
* This file contain iterative methods in Tree.h
**/

#include <iostream>
#include <cstddef>
#include "Node.h"
#include "Tree.h"
#include <stack>

using namespace std;

void Tree::insertInTreeIterative(Node *&root, int x) {
	Node *predecessor = NULL;
	Node *tree = root;

	while(tree != NULL) {
		predecessor = tree;
		if(x < tree->data ) tree = tree->left;
		else tree = tree->right;
	}

	if(predecessor == NULL) root = new Node(x);
	else if(x < predecessor->data) predecessor->left = new Node(x);
	else predecessor->right = new Node(x);
}

void Tree::inorderTreeIterative(Node *&root) {
	stack <int> s; 
	cout << "Inorder traversal" << '\n';
}
