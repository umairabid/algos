#ifndef TREE_NODE_H
#define TREE_NODE_H

class Node {
	public:
		Node* left;
		Node* right;
		int data;
		Node();
		Node(int x);
};

#endif