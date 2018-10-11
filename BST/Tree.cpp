#include <iostream>
#include <cstddef>
#include "Node.h"
#include "Tree.h"

using namespace std;

Tree::Tree () {
	root = NULL;
}

/**
* Public Methods
**/

void Tree::insert (int x) {
	insertInTreeIterative(root, x);
}

void Tree::inorder () {
	inorderTreeIterative(root);
	cout << "\n";
}

Node* Tree::search (int x) {
	return searchInTreeIterative(root, x);
}

/**
* Private Methods
**/

void Tree::insertInTree(Node *&tree, int x) {
	if(tree == NULL) tree = new Node(x);
	else if(x < tree->data) {
		if(tree->left == NULL) tree->left = new Node(x);
		else insertInTree(tree->left, x);
	} else {
		if(tree->right == NULL) tree->right = new Node(x);
		else insertInTree(tree->right, x);
	}
}

void Tree::inorderTree(Node *&tree) {
	if(tree != NULL) {
		inorderTree(tree->left);
		cout << tree->data << "\t";
		inorderTree(tree->right);
	}
}

Node* Tree::searchInTree(Node *&tree, int x) {
	if(tree == NULL || tree->data == x) {
		return tree;
	} else {
		if(x < tree->data) return searchInTree(tree->left, x);
		else return searchInTree(tree->right, x);
	}
}
