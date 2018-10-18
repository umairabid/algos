#ifndef TREE_NODE_H
#define TREE_NODE_H

class Node {
	public:
		Node *left;
		Node *right;
		Node *predecessor;
		int data;
		Node();
		Node(int x);
		Node(int x, Node *predecessor);
};

#endif
