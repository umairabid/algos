#include <iostream>
#include <cstddef>
#include "Node.h"
#include "Tree.h"

using namespace std;

Tree::Tree () {
	root = NULL;
}

void Tree::insert (int x) {
	if(root == NULL) {
		root = new Node(x);
	} else {
		insertInTree(root, x);
	}
}

void Tree::insertInTree(Node* tree, int x) {
	if(x < tree->data) {
		if(tree->left == NULL) tree->left = new Node(x);
		else insertInTree(tree->left, x);
	} else {
		if(tree->right == NULL) tree->right = new Node(x);
		else insertInTree(tree->right, x);
	}
}

void Tree::inorder () {
	inorderTraversal(root);
	cout << "\n";
}

void Tree::inorderTraversal(Node* tree) {
	if(tree != NULL) {
		inorderTraversal(tree->left);
		cout << tree->data << "\t";
		inorderTraversal(tree->right);
	}
}