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
	stack <Node *> s;
	Node *current = root;
	while(current != NULL || !s.empty()) {
		while (current != NULL) {
			s.push(current);
			current = current->left;
		}
		current = s.top();
		s.pop();
		cout << current->data << "\t";
		current = current->right;
	}
}

Node* Tree::searchInTreeIterative(Node *&tree, int x) {
	while(tree != NULL && tree->data != x) {
		if(x < tree->data) tree = tree->left;
		else tree = tree->right;
	}
	return tree;
}
