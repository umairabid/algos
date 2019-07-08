#include <iostream>
#include <cstddef>
#include <queue>  
#include <map>
#include "Node.h"
#include "Tree.h"
typedef map<int, pair<int, int> >::iterator map_type;
using namespace std;

Tree::Tree () {
	root = NULL;
	length = 0;
}

/**
* Public Methods
**/


void Tree::insert (int x) { 
	insertInTree(root, x);
	length = length + 1;
}
void Tree::inorder () { inorderTree(root); }
void Tree::preorder () { preorderTree(root); }
void Tree::postorder () { postorderTree(root); }
void Tree::levelorder () { levelorderTree(root); }
Node *Tree::search(int x) { return searchInTree(root, x); }
Node *Tree::maximum() { return maximumInTree(root); }
Node *Tree::minimum() { return minimumInTree(root); }

void Tree::getNodesDistance() { 
	map<int, pair<int, int> > levelDistances = map<int, pair<int, int> >();
	getNodesDistanceInTree(root, 0, 1, levelDistances);

	for(map_type iterator = levelDistances.begin(); iterator != levelDistances.end(); iterator++) {
		//cout << iterator->first <<  " : " << iterator->second.first <<  " : " << iterator->second.second << "\n";
		cout << iterator->second.first << "\t";
	}
}

void Tree::remove(Node *&node) {
	if(node->left == NULL)
		transplant(node, node->right);
	else if(node->right == NULL)
		transplant(node, node->left);
	else {
		Node *successor = minimumInTree(node->right);
		if(node->right != successor) {
			transplant(successor, successor->right);
			successor->right = node->right;
			successor->right->predecessor = successor;
		}
		transplant(node, successor);
		successor->left = node->left;
		successor->left->predecessor = successor;
	}
	length = length - 1;
}

Node *Tree::findSuccessor(Node *&node) {
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

void Tree::transplant(Node *&old, Node *&newNode) {
	if(old->predecessor == NULL)
		root = newNode;
	else if(old->predecessor->left == old)
		old->predecessor->left = newNode;
	else
		old->predecessor->right = newNode;
	if(newNode != NULL)
		newNode->predecessor = old->predecessor;
}

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

Node* Tree::searchInTree(Node *&tree, int x) {
	if(tree == NULL || tree->data == x) {
		return tree;
	} else {
		if(x < tree->data) return searchInTree(tree->left, x);
		else return searchInTree(tree->right, x);
	}
}

Node* Tree::maximumInTree(Node *&tree) {
	if(tree->right != NULL)
		return maximumInTree(tree->right);
	return tree;
}

Node* Tree::minimumInTree(Node *&tree) {
	if(tree->left != NULL)
		return minimumInTree(tree->left);
	return tree;
}

void Tree::inorderTree(Node *&node) {
	if(node != NULL) {
		inorderTree(node->left);
		cout << node->data << "\t";
		inorderTree(node->right);
	}
}

void Tree::postorderTree(Node *&node) {
	if(node != NULL) {
		postorderTree(node->left);
		postorderTree(node->right);
		cout << node->data << "\t";
	}
}

void Tree::preorderTree(Node *&node) {
	if(node != NULL) {
		cout << node->data << "\t";
		preorderTree(node->left);
		preorderTree(node->right);
	}
}

int Tree::getLength() {
	return length;
}

void Tree::levelorderTree(Node *&node) {
	queue<Node*> nodeQueue;
	nodeQueue.push(node);
	while(!nodeQueue.empty()) {
		Node *&currentNode = nodeQueue.front();
		cout << currentNode->data << "\t";
		nodeQueue.pop();
		if(currentNode->left != NULL) {
			nodeQueue.push(currentNode->left);
		}
		if(currentNode->right != NULL) {
			nodeQueue.push(currentNode->right);
		}
		
	}
}

void Tree::getNodesDistanceInTree(Node *&node, int distance, int level, map<int, pair<int, int> > &distances) {
	map_type existing = distances.find(distance);
	if(existing == distances.end()) {
		distances[distance] = make_pair(node->data, level);
	} else {
		int nodeDistance = existing->first;
		int nodeData = existing->second.first;
		int nodeLevel = existing->second.second;
		if(distance > nodeDistance)
			distances[distance] = make_pair(node->data, level);
	}
	
	if(node->left != NULL) {
		getNodesDistanceInTree(node->left, distance-1, level + 1, distances);
	}
	if(node->right != NULL) {
		getNodesDistanceInTree(node->right, distance+1, level + 1, distances);
	}
	
}


