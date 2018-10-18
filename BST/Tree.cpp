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
	insertInTree(root, x);
}

void Tree::inorder () {
	inorderTree(root);
	cout << "\n";
}

Node *Tree::search (int x) {
	return searchInTree(root, x);
}

Node *Tree::maximum () {
	return maximumInTree(root);
}

Node *Tree::minimum () {
	return minimumInTree(root);
}

Node *Tree::findSuccessor (Node *&node) {

	if(node->right != NULL)
		return minimumInTree(node->right);

	Node *predecessor = node->predecessor;
	while(predecessor != NULL && node == predecessor->right) {
		node = predecessor;
		predecessor = node->predecessor;
	}
	return predecessor;
}

/**
* Private Methods
**/

void Tree::insertInTree(Node *&tree, int x) {
	if(tree == NULL) tree = new Node(x);
	else if(x < tree->data) {
		if(tree->left == NULL) tree->left = new Node(x, tree);
		else insertInTree(tree->left, x);
	} else {
		if(tree->right == NULL) tree->right = new Node(x, tree);
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

Node *Tree::maximumInTree(Node *&tree) {
	if(tree->right != NULL)
		return maximumInTree(tree->right);
	return tree;
}

Node *Tree::minimumInTree(Node *&tree) {
	if(tree->left != NULL)
		return minimumInTree(tree->left);
	return tree;
}
